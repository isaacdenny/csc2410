
//Author: Kedrian James
//Date: 08/37/2024

/* Description: This program reads a binary file from disk, 
reverses the XOR transformation, and prints the binary 
data in hexadecimal and ASCII format.*/

#include <stdio.h>
#include <stdlib.h>

// Function to read the binary file from disk (e.g., data.bin)
unsigned char* readBinaryFile(const char* filename, size_t* fileSize) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    // Determine the size of the file
    fseek(file, 0, SEEK_END);
    *fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory to store the file contents
    unsigned char* buffer = (unsigned char*)malloc(*fileSize);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    // Read the file contents into the buffer
    fread(buffer, 1, *fileSize, file);
    fclose(file);

    return buffer;
}

// Function to reverse the XOR transformation
void reverseXORTransformation(unsigned char* buffer, size_t fileSize, unsigned char key) {
    for (size_t i = 0; i < fileSize; i++) {   
  
   /* ADD CODE HERE to XOR each byte with the key to reverse the transformation  */ 
        buffer[i] ^= key;  
    }
}

// Function to convert binary data to hexadecimal and print it
void convertBinaryToHex(unsigned char* buffer, size_t fileSize) {
    printf("====================================\n");
    printf("Hexadecimal Representation\n");
    printf("====================================\n");
    for (size_t i = 0; i < fileSize; i++) {
        
        // ADD CODE HERE to print the hexadecimal value of each byte
        char characters[] = "0123456789ABCDEF";

        // 1000 1010 0000 0000 0000 0000 00
        char first = buffer[i] >> 4; // 00001000
        char last = buffer[i] & 0x0F; // 00001111 
        

        // ADD CODE HERE to add a space after every 16 bytes for better readability
        printf("%c%c ", characters[first], characters[last]);

        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to convert binary data to ASCII and print it
void convertBinaryToASCII(unsigned char* buffer, size_t fileSize) {
    printf("====================================\n");
    printf("ASCII Representation\n");
    printf("====================================\n");
    for (size_t i = 0; i < fileSize; i++) {
        /*ADD CODE HERE to print the ASCII character if it's printable, 
        otherwise print a dot (.), except for the `\n` character*/
        printf("%d ", buffer[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }

    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    // Check if the filename is provided as a command-line argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];  // Read the filename from command-line arguments
    size_t fileSize = 0;
    unsigned char key = 0xAA;  // XOR key used for transformation

    // Read the binary file
    unsigned char* buffer = readBinaryFile(filename, &fileSize);
    if (!buffer) {
        return 1;
    }

    // Reverse the XOR transformation
    reverseXORTransformation(buffer, fileSize, key);

    // Convert and print the binary data to hexadecimal
    convertBinaryToHex(buffer, fileSize);

    // Convert and print the binary data to ASCII
    convertBinaryToASCII(buffer, fileSize);

    // Free the allocated memory
    free(buffer);
    return 0;
}
