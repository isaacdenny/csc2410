#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/statvfs.h>

void print_os_info() {
    struct utsname buffer;

    if (uname(&buffer) != 0) {
        perror("uname");
        exit(EXIT_FAILURE);
    }

    printf("Operating System: %s\n", buffer.sysname);
    printf("Node name: %s\n", buffer.nodename);
    printf("Release: %s\n", buffer.release);
    printf("Version: %s\n", buffer.version);
    printf("Machine: %s\n", buffer.machine);
    
}

void print_ram_info() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
       printf("Total RAM: %ld MB\n", info.totalram / 1024 / 1024);  // Print total RAM in MB
       printf("Free RAM: %ld MB\n", info.freeram / 1024 / 1024);    // Print free RAM in MB
    } else {
       perror("sysinfo");
       exit(EXIT_FAILURE);
    }
}

void print_disk_info() {
    struct statvfs info;

    if (statvfs("/", &info) == 0) {
        printf("Disk Block Size: %lu\n", info.f_bsize);      // Print block size
        printf("Total Disk Blocks: %lu\n", info.f_blocks);   // Print total number of blocks
        printf("Free Disk Blocks: %lu\n", info.f_bfree);     // Print number of free blocks
    } else {
        perror("statvfs");
        exit(EXIT_FAILURE);
    }
}

void print_cpu_info() {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "r");  // Open the CPU info file
    char line[256];
    int printed_family = 0, printed_vendor = 0, printed_cache = 0, printed_cores = 0, printed_model = 0, printed_mhz = 0;

    if (cpuinfo == NULL) {
        perror("Failed to open /proc/cpuinfo");
        exit(1);
    }

    while(fgets(line, sizeof(line), cpuinfo)) {
        if (strstr(line, "cpu family") != NULL && !printed_family) {
            printf("%s", line);
            printed_family = 1;
        }
        if (strstr(line, "vendor_id") != NULL && !printed_vendor) {
            printf("%s", line);
            printed_vendor = 1;
        }
        if (strstr(line, "cache size") != NULL && !printed_cache) {
            printf("%s", line);
            printed_cache = 1;
        }
        if (strstr(line, "cpu cores") != NULL && !printed_cores) {
            printf("%s", line);
            printed_cores = 1;
        }
        if (strstr(line, "model name") != NULL && !printed_model) {
            printf("%s", line);
            printed_model = 1;
        }
        if (strstr(line, "cpu MHz") != NULL && !printed_mhz) {
            printf("%s", line);
            printed_mhz = 1;
        }

        if (printed_family && printed_vendor && printed_cache && printed_cores && printed_model && printed_mhz) {
            break;
        }
    }
}

int main() {
    print_os_info();
    printf("\n");
    print_cpu_info();
    print_ram_info();
    print_disk_info();
    return 0;
}
