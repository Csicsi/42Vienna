📜 get_next_line – Read a File Line by Line

get_next_line is a 42 Vienna project that involves creating a function to read a file descriptor line by line, handling dynamic memory allocation and buffer management efficiently. Unlike fgets() or read(), get_next_line retains data between function calls, making it ideal for parsing logs, reading configuration files, or handling continuous input streams.
Key Features

    ✅ Reads from any file descriptor (stdin, files, sockets, pipes, etc.).
    ✅ Handles multiple file descriptors at the same time (Bonus).
    ✅ Efficient buffer management (customizable via BUFFER_SIZE).
    ✅ Returns NULL on EOF or error, mimicking real-world behavior.
    ✅ No memory leaks – properly frees allocated memory after usage.

Bonus Features

🔹 Supports reading from multiple file descriptors simultaneously
🔹 Uses a linked list to efficiently manage leftover data
🔹 Optimized to avoid unnecessary memory allocations
How It Works

    Uses read() to fetch data into a buffer.
    Stores unread content between function calls using a static variable.
    Dynamically allocates memory to construct each line.
    Handles multiple open files (Bonus) by using a linked list to track different file descriptors.
    Returns the next line including the newline (\n) or the last line (EOF).

What I Learned

    Memory management with dynamic buffers (malloc, free).
    Working with static variables to retain state between calls.
    Handling edge cases (empty files, no newlines, large files).
    Managing multiple file descriptors with linked lists (Bonus).
