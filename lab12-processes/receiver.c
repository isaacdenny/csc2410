#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  const char *fifo_path = "/tmp/my_fifo";
  char buffer[100];
  int fifo_fd;

  // Open the FIFO for reading
  fifo_fd = open(fifo_path, O_RDONLY);
  
  if (fifo_fd == -1) {
    perror("Failed to open FIFO for reading");
    exit(1);
  }

  // Read message from FIFO
  read(fifo_fd, buffer, sizeof(buffer));
  printf("Receiver received: %s\n", buffer);

  // Close the FIFO
  close(fifo_fd);
  return 0;
}
