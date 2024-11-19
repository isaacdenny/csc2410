# Multithreading Lab

## Part 1 - Creating and Managing

1. We use `pthread_join` to make sure the threads are finished and to gather resulting data back to the main process
2. If we omitted `pthread_join`, the main program would not wait for the threads to finish before continuing, and therefore would not have access to the thread data

## Part 2 - Syncronizing Threads with Mutexes

1. If we removed the mutex, the threads would try to access the data at the same time and could create data hazards.
2. The final counter value is 5
3. My group and I will be using mutexes to protect against data races in our decentralized (blockchain) supply chain simulation for CSC2710

## Part 3 - Simplified with OpenMP

1. OpenMP abstracts the manual management of the threads and mutexes compared to pthread
2. A lot of the technical manipulation of the threads is abstracted and hidden, making it easier to get started, but limiting for more complex projects

## Part 4 - Loop Parallelization

1. OpenMP offers a much simpler interface, allowing users to focus on the logic of their program rather than the intrecacies of the library
2. Reduction ensures the partial sums are added sequentially instead of all at once, spreading the sums across more memory
3. We could extend this approach to include functionality for fibonacci number calculation

## Part 5 - Core Affinity

### Pthread

1. Threads can run faster with less overhead because context switching is not needed. Each thread can run unblocked by others 
2. Using separate cores for threads eliminates the need for context switching, allowing for better and more predictable performance
3. Threads may not all have the benefits of the cpu cache

### OpenMP

1. Performance improves because the threads are not moved between cores, and context switching is minimized.
2. Using env variables allows different configurations for testing quickly with the same code, or running the same code with different configurations of different machines.
3. I would just change the env variables to run the threads on the same core or grouping them.

---

## Section 2

1. Avg performance
- Multithreaded: 17.836 ms
- Single thread: 16.118 ms

2. Multithreading can increase overhead to manage threads and context switching, but generally provides increased performance on machines with multiple cores. Here, we can see that the overhead of managing the threads outweighs any performance increase.

3. Applications of multithreading include compute-intensive tasks that can be run on multiple cores.

4. Single threaded execution will be prefereable on a single-cored cpu/machine. There will otherwise be no performance increase.

![Google Sheets Data and Graph](https://github.com/isaacdenny/csc2410/blob/main/multithreading/google-sheets-data.png)

---

## Section 3

1. Avg performance
- Core Affinity: 16.789 ms
- No Core Affinity: 17.228 ms

2. Core affinity gave more variance to the execution times. I expect that it was because of the lower overhead of managing the threads across cores or the decreased cache misses

3. Applications that require heavy caching would perform great using core affinity

4. Not as frequently, because I/O action performance is more heavily influenced by network speeds, data transfer speeds than they are by CPU performance.

![Core affinity data](https://github.com/isaacdenny/csc2410/blob/main/multithreading/google-sheets-data-core-affinity.png)
