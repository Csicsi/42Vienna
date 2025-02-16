📡 Minitalk – Interprocess Communication via Signals

Minitalk is a 42 Vienna project that explores low-level interprocess communication (IPC) using Unix signals (SIGUSR1 and SIGUSR2). The goal is to implement a simple client-server communication system, where the client sends a message to the server one bit at a time using signals.
Key Features

    ✅ Bitwise message transmission using SIGUSR1 (0) and SIGUSR2 (1).
    ✅ Sends message length first, allowing the server to allocate memory dynamically.
    ✅ Asynchronous communication between two separate processes.
    ✅ Signal handling & custom handlers using sigaction().
    ✅ Bonus: Implements Unicode/extended character support and acknowledgments.

How It Works

    The client first sends the length of the message bit by bit so the server can allocate just enough memory.
    The server receives and stores the length before allocating memory.
    The client then sends the actual message, bit by bit.
    The server reconstructs the message by catching and interpreting these signals.
    Optionally, the server sends acknowledgments back to confirm message receipt (Bonus).

What I Learned

    How to use Unix signals for process communication.
    Bitwise operations to encode and decode messages efficiently.
    How to properly handle signals with sigaction().
    Memory management – Sending the message length first allows for efficient allocation.
    Real-time IPC challenges and handling signal synchronization.
