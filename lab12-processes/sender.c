#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  const char *fifo_path = "/tmp/my_fifo";
  char message[] = "Hello from sender!";
  int fifo_fd;
  // Open the FIFO for writing
  fifo_fd = open(fifo_path, O_WRONLY);

  if (fifo_fd == -1) {
    perror("Failed to open FIFO for writing");
    exit(1);
  }
  // Write message to FIFO
  write(fifo_fd, message, strlen(message) + 1); // Include null terminator 
  printf("Sender sent: %s\n", message);
  // Close the FIFO
  close(fifo_fd);
  return 0;
}
