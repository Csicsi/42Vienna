🎨 Fract-ol – Interactive Fractal Renderer

Fract-ol is a 42 Vienna project focused on graphics programming, complex numbers, and fractal generation using MiniLibX. It allows for the visualization of mathematical fractals with real-time interaction, including zooming, panning, and dynamic color adjustments.
🖼️ Supported Fractals

✅ Mandelbrot Set – The classic fractal revealing infinite complexity.
✅ Julia Set – A dynamic fractal influenced by a user-defined constant.
✅ Burning Ship Set – A variation of Mandelbrot with absolute values, creating a ship-like structure.
⚡ Features

    ✅ Real-time zooming – Use the mouse wheel to zoom into intricate details.
    ✅ Panning & navigation – Move around using arrow keys or WASD.
    ✅ Color customization – Shift colors dynamically.
    ✅ Julia Parameter Adjustments – Modify Julia fractal behavior in real-time.
    ✅ Optimized rendering – Smooth performance with efficient calculations.

📌 How It Works

    Complex Numbers & Iterations
        Each pixel represents a complex number (c).
        The fractal function is applied iteratively (Z = Z² + c for Mandelbrot/Julia).
        Burning Ship variation: Uses Z = (|Re(Z)| + i * |Im(Z)|)² + c.
        The number of iterations before escape determines the pixel color.

    MiniLibX for Graphics
        Uses MiniLibX for efficient pixel manipulation.
        Handles keyboard and mouse events for interactive navigation.

    Performance Optimizations
        Multi-threading (Bonus): Divides the image into segments for parallel computation.
        Adaptive iteration limits to prevent excessive calculations when zooming.

🎮 Controls
Key	Action
W / Up Arrow	Move Up
A / Left Arrow	Move Left
S / Down Arrow	Move Down
D / Right Arrow	Move Right
Space	Shift Colors
U / J	Shift Julia Real Part
I / K	Shift Julia Imaginary Part
Mouse Wheel	Zoom In/Out
ESC	Exit
🚀 How to Run

./fractol <FractalType> [arguments]

Fractal Types
Fractal	Argument	Example
Mandelbrot	Mandelbrot / M / m / 0	./fractol Mandelbrot
Julia	Julia / J / j / 1	./fractol Julia -0.7 0.27 (optional real/imaginary parameters)
Burning Ship	Burning ship / B / b / 2	./fractol Burning ship

💡 Example Commands:

./fractol Mandelbrot
./fractol Julia -0.7 0.27
./fractol Burning ship

🎯 What I Learned

    Graphics programming using MiniLibX.
    Mathematical properties of fractals and their visualization.
    Optimizing computations for real-time rendering.
    Handling real-time user input & interactivity.
    Implementing multi-threading for faster performance.
