
🔄 Push_swap – Optimized Sorting with Stack Operations

Push_swap is a 42 Vienna project where the goal is to sort a list of integers using two stacks (A and B) and a limited set of operations. My implementation focuses on an efficient sorting strategy that minimizes the number of moves.
Algorithm Overview

My Push_swap implementation follows a structured approach:

    Pre-sorting (Handling Large Inputs Efficiently)
    Finding the Best Target Position in Stack A
    Cost Calculation to Minimize Rotations
    Executing the Least-Cost Moves
    Final Sorting (Rotating Stack A into Place)

1️⃣ Pre-Sorting – Optimized Element Distribution

Before sorting, elements are pushed to Stack B strategically to optimize future operations:

    The top few largest elements remain in Stack A to preserve order.
    The rest are pushed to Stack B, prioritizing smaller elements first.
    If the element in Stack B is very small, it is immediately rotated to the bottom (rb) to distribute numbers evenly.
    Once Stack A is reduced to five elements, a simple sorting method is applied (simple_sort).

📌 Why?
This reduces the number of operations required in later steps and keeps elements better distributed.
2️⃣ Finding the Best Target in Stack A

Each node in Stack B needs a target position in Stack A where it will be inserted.

    For each number in Stack B, we find the smallest number in Stack A that is larger (i.e., the next-highest number).
    If no such number exists, it wraps around and targets the smallest element in Stack A.
    This ensures that elements are inserted in the right place, reducing unnecessary movements.

📌 Why?
It guarantees that numbers are inserted in the right order, keeping Stack A sorted as we go.
3️⃣ Calculating the Optimal Move Cost

To find the most efficient move, we calculate the cost of moving each number from Stack B into Stack A:

    Cost Calculation:
        Moving an element to the top of Stack A
        Moving an element to the top of Stack B
        Simultaneous moves (rr, rrr) to optimize rotations
    The move that results in the least total operations is chosen.

📌 Why?
Instead of blindly pushing numbers, we always move the most optimal element first.
4️⃣ Executing the Least-Cost Move

Once we know which move is the best, we execute it:

    If both A and B need to rotate in the same direction, use rr or rrr to optimize moves.
    If A and B rotate in opposite directions, we move them separately.
    The element is then pushed from B to A (pa).

📌 Why?
This method minimizes operations, keeping sorting as efficient as possible.
5️⃣ Final Sorting – Rotating Stack A

Once Stack B is empty, Stack A might not start at the smallest number.

    The smallest number's position is located.
    If it is in the first half of the stack, use ra to move it up.
    If it is in the second half, use rra to move it up.

📌 Why?
Ensures final ordering with the fewest rotations.

By combining pre-sorting, move cost optimization, and strategic rotations, my Push_swap implementation minimizes operations while maintaining order.

