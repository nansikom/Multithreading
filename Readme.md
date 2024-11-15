MyCounter
Introduction
MyCounter is a C program designed to demonstrate threading, mutual exclusion, and condition variables. The program implements a simple Producer-Consumer model where two threads share and increment a counter from 0 to 10.

Project  Outcomes
Understand and apply mutual exclusion for thread-safe access to shared resources.
Create and manage threads and their lifecycle in C.
Utilize condition variables to synchronize thread operations.

Features
Two Threads: A Producer (initial thread) and a Consumer (created by the Producer).
Shared Counter: A variable, myCount, incremented by both threads from 0 to 10.
Synchronization: Mutex (myMutex) and two condition variables (myCond1, myCond2) ensure controlled thread access to myCount.

Program Flow
Initialization: The Producer thread creates and starts the Consumer thread.
Producer-Consumer Execution: Both threads increment myCount, alternating based on conditions:
Mutex (myMutex): Ensures exclusive access to myCount.
Condition Variables (myCond1, myCond2): Coordinate thread turns.
Termination: The program stops once myCount reaches 10.
Variable Naming
Mutex: myMutex
Condition Variables: myCond1 and myCond2
Counter: myCount

Getting Started
Compile
bash
Copy code
gcc -pthread -o myCounter myCounter.c
Run
bash
Copy code
./myCounter
Note: This is a school project hosted by Oregon state university
