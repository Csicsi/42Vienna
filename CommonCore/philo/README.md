🍽️ Philosophers – Optimized Synchronization with Initial Delay & Thinking Time

Philosophers is a 42 Vienna project that explores multithreading, synchronization, and deadlock prevention by simulating the Dining Philosophers Problem. The goal is to ensure efficient resource usage while avoiding race conditions, deadlocks, and starvation.
Project Overview

The simulation consists of N philosophers, each following this cycle:

    Thinking 🤔
    Picking up forks (both must be available to eat) 🍴
    Eating 🍽
    Putting forks down 💤
    Repeating the process 🔁

The challenge is to synchronize philosophers efficiently to avoid starvation, reduce contention, and prevent deadlocks.
🛠 My Synchronization Strategy

Unlike a basic implementation where philosophers act independently, I optimize synchronization by: ✅ Stacking philosophers with an initial delay to distribute eating times evenly.
✅ Calculating an optimal thinking time for each philosopher based on fork availability.
✅ Avoiding deadlocks by managing fork access order and limiting concurrent eaters.
📌 Initial Delay Calculation

    Each philosopher starts with a calculated delay, ensuring they don’t all compete for forks at the same time.
    This prevents unnecessary blocking and reduces contention for shared resources.
    This approach stacks the philosophers, spacing out eating cycles optimally.

📌 Dynamic Thinking Time Adjustment

    Instead of arbitrarily making philosophers think for a fixed time, I calculate an optimal thinking time.
    This balances the eating rhythm, ensuring a smoother cycle where no philosopher is left waiting too long.
    Key benefit: It prevents philosophers from trying to pick up forks when they are most likely unavailable.

Key Features

✅ Multithreaded (or Multi-process) implementation
✅ Uses mutexes or semaphores for synchronization
✅ Prevents deadlocks and starvation with smart scheduling
✅ Calculates dynamic thinking time for better efficiency
✅ Configurable philosopher count, time to die, eat, sleep, and meal limits
✅ Bonus: Process-based solution with semaphore synchronization
Concurrency & Synchronization Approach
🛠 Mutex-based Solution (Mandatory Part)

    Each philosopher is a thread.
    Each fork is protected by a mutex (pthread_mutex_t).
    A global print mutex ensures clean, non-overlapping console output.
    A monitor thread checks if a philosopher has died.

⚡ Semaphore-based Solution (Bonus Part)

    Each fork is a semaphore, allowing multiple philosophers to attempt eating.
    Each philosopher process is independent, synchronized through semaphores.

Deadlock & Starvation Prevention

🔹 Initial Delay Staggering: Prevents all philosophers from competing for forks at the same time.
🔹 Optimized Thinking Time: Avoids forks being requested too soon, reducing contention.
🔹 Monitor Thread: Continuously checks if any philosopher has exceeded time_to_die.
🔹 Limited Eating (if configured): The simulation stops after a set number of meals.
What I Learned

    Thread creation & management with pthread_create, pthread_join.
    Synchronization techniques with mutexes (pthread_mutex_t) and semaphores (sem_t).
    Fine-tuning concurrency with initial delays & calculated thinking times.
    Deadlock prevention strategies in concurrent systems.
    Process-based synchronization (Bonus part).
    Timing precision to ensure real-world execution accuracy.
