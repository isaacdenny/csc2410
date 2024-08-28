# Computer Systems Lab 1

## After Part 1

1. The uname() system call shows the OS, domain name, release version, and the machine architecture. This information can be used to understand which applications can or cannot be run on the system and where to look for certain system files (different for OS's).
2. You could modify the function to just print one statement `printf("OS and Version: %s %s", buffer.sysname, buffer.version)
`
## After Part 2

1. Knowing the CPU details can help us understand our limits for the applications running on the machine. Vendors may release vulnerability assessments and recalls for a certain chip.
2. Cores may not be properly set up, leading them to handle memory incorrectly

## After Part 3

1. Differences may be caused by programs infinitely looping or failing to close data streams. Analyzing the RAM usage can give us a good idea of whether our programs are working or incorrectly handling the memory
2. The freeswap info is on the sysinfo object that we define at the beginning of the function `printf("Free Swap: %ld MB", info.freeswap / 1024 / 1024);`

## After Part 4

1. Understanding block size can help us to manage our storage space more efficiently. Smaller block sizes reduce slack space (like in an instance where we use 2.1 blocks, the rest of that 3rd block is not being used), but create more blocks to manage.
2. You could multiply the f_bsize by f_bfree to get the free space in bytes, then divide it by 1024 3 times to get the GB free.


