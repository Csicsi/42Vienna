# 🎮 Cub3D – A Raycasting-Based 3D Game

**Cub3D** is a **42 Vienna** project inspired by Wolfenstein 3D, using raycasting to create a pseudo-3D world in a 2D environment. It features animated textures, doors, wall collision detection, and smooth player movement with mouse-based turning, making for an immersive experience.

## This was a duo project, where we divided responsibilities as follows:
## 🛠 My Contributions:

* Raycasting Engine – Implementing core 3D rendering via raycasting.
* Movement & Collision Handling – Smooth navigation with wall & door collisions.
* Animated Textures (Bonus Feature) – Rendering GIF-like wall animations dynamically.
* Doors (Bonus Feature) – Interactive openable/closable doors.
* Mouse-Based Turning (Bonus Feature) – Allows smooth camera movement.
* Minimap (Bonus Feature) – Real-time top-down player tracking.

## 👩‍💻 My Partner’s Contributions:

* Parsing System – Reading the .cub configuration file.
* Map Validation – Ensuring proper map structure and boundaries.

## ⚡ Features

* Real-time Raycasting – 3D projection using a 2D map.
* Animated Wall Textures (Bonus) – "GIF-like" wall animations.
* Interactive Doors (Bonus) – Openable/closable doors in the game world.
* Smooth Player Movement – Includes wall & door collision detection.
* Mouse-Based Camera Control (Bonus) – Look around smoothly with the mouse.
* Minimap – Displays the map layout with real-time player tracking.
* Configurable Maps – Loads from .cub files with custom textures & doors.
* Error Handling & Map Validation – Ensures correctness of .cub files.

## Raycasting (My Contribution)

* Casts rays from the player’s position to detect walls.
* Uses DDA (Digital Differential Analyzer) Algorithm for fast wall intersection detection.
* Corrects fisheye distortion for realistic depth perception.
* Applies texturing to walls based on ray collision points.

## Animated Wall Textures (My Contribution)
🔹 How It Works

* Instead of static textures, walls use "GIF-like" animations.
* Uses a frame system that cycles through multiple images over time.
* Performance-optimized: Texture updates occur independently from rendering cycles.

🔹 Why This Matters

* Adds visual dynamism to environments.
* Supports looping animations for water, fire, or other dynamic elements.
* More immersive gameplay compared to static walls.

## Doors & Collision Handling (My Contribution)

* Doors are interactive – players can open & close them.
* Implemented using special map values (D for doors).
*Raycasting detects whether a door is open or closed, adjusting rendering accordingly.

## Collision Handling

* Walls & Doors prevent movement – players cannot walk through them.
* Uses hitbox-based detection instead of single-pixel collision.
* Smooth edge handling ensures that the player doesn't get stuck.

## Mouse-Based Camera Control (My Contribution)

* The mouse controls the player's field of view dynamically.
* Horizontal mouse movement rotates the camera smoothly.
* Acceleration is adjusted for precise control.

## Benefits

* More intuitive than keyboard-only turning.
* Allows for quicker reactions & smoother gameplay.
* Feels closer to modern FPS controls.

## Movement & Minimap (My Contribution)

Implements WASD movement with smooth interpolation.
Uses arrow keys OR the mouse to rotate the player’s view.
Minimap dynamically updates, displaying:
* Player position
* Walls, doors, and empty spaces
* Directional view indicator

## Parsing & Map Validation (Partner’s Contribution)

* Reads the .cub map file and extracts:
* Map layout
* Player start position
* Wall textures & door locations

## Map Validation (Partner’s Contribution)

* Ensures the map is:
* Surrounded by walls (no open spaces).
* Contains exactly one player start position.
* Has valid texture paths and color definitions.

## 🎮 Controls
* W / Up Arrow	Move Forward
* S / Down Arrow	Move Backward
* A	Strafe Left
* D	Strafe Right
* ← / → Arrows	Rotate View (Keyboard)
* Mouse Movement	Rotate View (Smooth Camera)
* E	Open/Close Doors
* ESC	Exit Game

## 🎯 What I Learned

* Raycasting Algorithms – Rendering a 3D world from a 2D map.
* Texture Mapping & Animation – Creating dynamic, animated wall textures.
* Physics-Based Collision Detection – Preventing wall & door clipping.
* Game Engine Optimizations – Ensuring smooth performance.
* User Interactions – Implementing openable doors and minimap tracking.
* Mouse-Based Camera Handling – Creating a modern FPS-like feel.
