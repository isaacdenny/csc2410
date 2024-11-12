#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void handle_signal(int sig) {
  printf("Process %d received signal %d\n", getpid(), sig);
}

void printProcessInfo(int id) {
  printf("Process %d: PID = %d, PPID = %d\n", id, getpid(), getppid());
}

void childProcess(int id) {
  signal(SIGUSR1, handle_signal); // Setup signal handler
  printProcessInfo(id);           // Print PID and PPID
  // Simulate work
  printf("Child Process %d is working...\n", id);
  sleep(5); // Waiting to receive a signal
  printf("Child Process %d exiting\n", id);
  exit(0); // End child process
}

int main() {
  pid_t pids[5];
  int n = 5;
  // Create child processes
  for (int i = 0; i < n; i++) {
    pids[i] = fork();
    if (pids[i] == 0) {
      childProcess(i); // Each child executes this function
    } else if (pids[i] < 0) {
      perror("Fork failed");
      exit(1);
    }
  }
  // Parent process sends a signal to each child
  sleep(1); // Ensure all child processes are ready
  for (int i = 0; i < n; i++) {
    printf("Parent sending SIGUSR1 to child %d (PID = %d)\n", i, pids[i]);
    kill(pids[i], SIGUSR1); // Send SIGUSR1 signal to child process
  }
  // Wait for all children to complete
  for (int i = 0; i < n; i++) {
    waitpid(pids[i], NULL, 0);
    printf("Parent Process: Child %d has exited\n", i);
  }
  printf("All child processes have completed.\n");
  return 0;
}
