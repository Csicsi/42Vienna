document.addEventListener("DOMContentLoaded", async function () {
	let map = L.map('map').setView([47.5, 16.5], 8);

	L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
		attribution: '&copy; OpenStreetMap contributors'
	}).addTo(map);

	let stationData = await (await fetch("data/travel_times.json")).json();
	let adData = await (await fetch("data/real_estate_ads.json")).json();

	let markers = {};
	let adMarkers = {};
	let visibleStations = new Set();
	let showStations = true;

	function normalizeName(name) {
		return name.trim().toLowerCase();
	}

	let stationNameMapping = {};

	for (let extractedStation in stationData) {
		let { original_name, latitude, longitude, travel_times } = stationData[extractedStation];
		let normalizedOriginal = normalizeName(original_name);
		let normalizedExtracted = normalizeName(extractedStation);
		stationNameMapping[normalizedOriginal] = extractedStation;

		let popupContent = `<b>${extractedStation}</b><br>`;
		for (let dest in travel_times) {
			popupContent += `${dest}: ${travel_times[dest]} minutes<br>`;
		}

		let marker = L.circleMarker([latitude, longitude], {
			radius: 8,
			color: "blue",
			fillOpacity: 0.7
		}).bindPopup(popupContent);

		markers[extractedStation] = { marker, travel_times };
		visibleStations.add(normalizedExtracted);
	}

	let adCluster = L.markerClusterGroup();

	adData.forEach(ad => {
		let popupContent = `
			<b>${ad.title}</b><br>
			<b>Price:</b> ${ad.price} €<br>
			<b>Size:</b> ${ad.size} m²<br>
			<b>Location:</b> ${ad.zip_code} ${ad.city}, ${ad.region}<br>
			<b>Nearest station:</b> ${ad.nearest_station} (${ad.distance_to_station} m)<br>
			<a href="${ad.url}" target="_blank">Visit ad</a>
		`;

		let marker = L.circleMarker([ad.latitude, ad.longitude], {
			radius: 12,
			color: "red",
			fillOpacity: 0.8
		}).bindPopup(popupContent);

		adMarkers[ad.url] = { marker, ad };
		adCluster.addLayer(marker);
	});

	map.addLayer(adCluster);

	function updateMarkers() {
		let travelLimits = {
			"Gloggnitz": parseInt(document.getElementById("slider_Gloggnitz").value),
			"Sopron": parseInt(document.getElementById("slider_Sopron").value),
			"Schimetta": parseInt(document.getElementById("slider_Schimetta").value)
		};

		let distanceLimit = parseInt(document.getElementById("slider_Distance").value);
		let maxPrice = parseInt(document.getElementById("slider_Price").value);
		let minSize = parseInt(document.getElementById("slider_Size").value);

		visibleStations.clear();

		for (let station in markers) {
			let { marker, travel_times } = markers[station];

			let meetsCriteria = Object.keys(travelLimits).every(dest =>
				travel_times[dest] !== undefined ? travel_times[dest] <= travelLimits[dest] : true
			);

			if (meetsCriteria) {
				visibleStations.add(normalizeName(station));
				if (showStations) marker.addTo(map);
			} else {
				map.removeLayer(marker);
			}
		}

		adCluster.clearLayers();
		adData.forEach(ad => {
			let { marker, ad: adData } = adMarkers[ad.url];
			let normalizedNearestStation = normalizeName(adData.nearest_station || "");
			let extractedStation = stationNameMapping[normalizedNearestStation] || adData.nearest_station;

			if (
				adData.distance_to_station <= distanceLimit &&
				adData.price <= maxPrice &&
				adData.size >= minSize &&
				visibleStations.has(normalizeName(extractedStation))
			) {
				adCluster.addLayer(marker);
			}
		});

		map.addLayer(adCluster);
	}

	function syncSliderAndInput(sliderId, inputId) {
		let slider = document.getElementById(sliderId);
		let input = document.getElementById(inputId);

		slider.addEventListener("input", function () {
			input.value = this.value;
			updateMarkers();
		});

		input.addEventListener("input", function () {
			let value = Math.max(parseInt(slider.min), Math.min(parseInt(slider.max), parseInt(this.value) || 0));
			input.value = value;
			slider.value = value;
			updateMarkers();
		});
	}

	["Gloggnitz", "Sopron", "Schimetta"].forEach(dest => syncSliderAndInput(`slider_${dest}`, `input_${dest}`));
	syncSliderAndInput("slider_Distance", "input_Distance");
	syncSliderAndInput("slider_Price", "input_Price");
	syncSliderAndInput("slider_Size", "input_Size");

	document.getElementById("reset_filters").addEventListener("click", () => {
		["Gloggnitz", "Sopron", "Schimetta"].forEach(dest => {
			document.getElementById(`slider_${dest}`).value = 180;
			document.getElementById(`input_${dest}`).value = 180;
		});

		document.getElementById("slider_Distance").value = 30000;
		document.getElementById("input_Distance").value = 30000;
		document.getElementById("slider_Price").value = 2000000;
		document.getElementById("input_Price").value = 2000000;
		document.getElementById("slider_Size").value = 0;
		document.getElementById("input_Size").value = 0;

		updateMarkers();
	});

	document.getElementById("toggle_stations").addEventListener("click", function () {
		showStations = !showStations;

		for (let station in markers) {
			let { marker } = markers[station];

			if (showStations) {
				marker.addTo(map);
			} else {
				map.removeLayer(marker);
			}
		}

		this.textContent = showStations ? "Hide stations" : "Show stations";
	});

	let toggleButton = document.getElementById("toggle_controls");
	let controlsPanel = document.querySelector(".controls");

	toggleButton.addEventListener("click", function () {
		controlsPanel.classList.toggle("hidden");
		this.textContent = controlsPanel.classList.contains("hidden") ? "Settings" : "Map";
	});

	updateMarkers();
});
