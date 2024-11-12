# Processes Lab Questions

## Part 1 - Process Tree

1. Each child process prints its PID and its parent's PID. This helps us to see how the processes can be shown as a tree. Then each process prints that it has received a signal (10) from the parent process.

2. Each child responds by printing to the console that it has received the signal with value 10.

3. Each process needs to be set up to handle the signals before the parent can start sending the signals and expect a response/action to occur.

- [x] Extension: added to the `handle_signal` function to start a timer when receiving the correct signal

## Part 2 - Message passing with named pipes

1. Similar to file reading, the sender program writes data to the pipe (fi), and the reader reads from the pipe (fo). If the pipe is full, processes will have to wait to read before writing more data to the pipeline.

2. It is NOT necessary to run the receiver first. The data is written to the pipe and can be read by a receiver at any time. (I tried it both ways)

3. You may need to make a second pipe that the sender can read from and the receiver can write to. This way the communication does not get overwritten or confused

![Running the sender and receiver in 2 terminals](https://github.com/isaacdenny/csc2410/blob/main/lab12-processes/sender-receiver-processes.png)
