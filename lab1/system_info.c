#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

void print_os_info() {
    struct utsname buffer;

    if (uname(&buffer) != 0) {
        perror("uname");
        exit(EXIT_FAILURE);
    }

    printf("Operating System: %s\n", buffer.system);
    printf("Node name: %s\n", buffer.nodename);
    printf("Release: %s\n", buffer.release);
    printf("Version: %s\n", buffer.version);
    printf("Machine: %s\n", buffer.machine);
    
}

int main() {
    print_os_info();
    return 0;
}