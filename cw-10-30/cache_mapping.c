#include <stdio.h>
#include <stdbool.h>

#define CACHE_SIZE 4  // Number of cache lines
#define MEMORY_SIZE 16 // Size of the main memory

// Cache line structure
typedef struct {
    int tag;
    bool valid;
} CacheLine;

// Function to access memory with a fully-associative cache
void accessMemory(int memory[], CacheLine cache[], int address) {
    int tag = address; // In fully-associative mapping, the address itself can be treated as the tag
    bool hit = false;

    // Check for a hit in the cache
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].valid && cache[i].tag == tag) {
            hit = true;
            printf("Cache Hit! Address: %d\n", address);
            break;
        }
    }

    // Cache miss; find a line to replace
    if (!hit) {
        // Find an empty line or replace the first invalid line (simple replacement policy)
        int replaced = -1;
        for (int i = 0; i < CACHE_SIZE; i++) {
            if (!cache[i].valid) {
                replaced = i;
                break;
            }
        }

        // If all lines are valid, replace the first one
        if (replaced == -1) {
            replaced = 0; // Simple FIFO replacement
            printf("Cache Miss! Replacing line with address: %d\n", cache[replaced].tag);
        } else {
            printf("Cache Miss! Filling empty line at index: %d\n", replaced);
        }

        // Update cache
        cache[replaced].tag = tag;
        cache[replaced].valid = true;
    }
}

int main() {
    // Simulated main memory
    int memory[MEMORY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    // Initialize cache
    CacheLine cache[CACHE_SIZE];
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].valid = false;
    }

    // Access some memory addresses
    for (int i = 0; i < 10; i++) {
        accessMemory(memory, cache, i);
    }

    for (int i = 0; i < 10; i++) {
        accessMemory(memory, cache, i);
    }
    return 0;
}

