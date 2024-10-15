#include <stdio.h>

// Function Definitions

// Performs the bitwise AND operation between two integers.
// Returns the result of a & b.
int andOperation(int a, int b) {
    return a & b;
}

// Performs the bitwise OR operation between two integers.
// Returns the result of a | b.
int orOperation(int a, int b) {
    return a | b;
}

// Performs the bitwise XOR operation between two integers.
// Returns the result of a ^ b.
int xorOperation(int a, int b) {
    return a ^ b;
}

// Performs the bitwise NOT operation on an integer.
// Returns the result of ~a.
int notOperation(int a) {
    return ~a;
}

// Shifts the bits of 'num' to the left by 'shift' positions.
// Returns the result of num << shift.
int leftShift(int num, int shift) {
    return num << shift;
}

// Shifts the bits of 'num' to the right by 'shift' positions.
// Returns the result of num >> shift.
int rightShift(int num, int shift) {
    return num >> shift;
}

// Sets the bit at 'position' in 'num' to 1.
// Returns the modified number.
int setBit(int num, int position) {
    /* 
     * num = 10010
     * position = 2
     * mask = 1 << 2 = 100
     * num | mask = 10010 | 100 = 10110
     */

    int mask = 1 << (position - 1);
    return num | mask;
}

// Clears the bit at 'position' in 'num' (sets it to 0).
// Returns the modified number.
int clearBit(int num, int position) {
    /*
     * num = 10110
     * position = 2
     * mask = ~(1 << 2) = ~100 = 011
     * num & mask = 10110 & 11011 = 10010
     */

    int mask = ~(1 << (position - 1));
    return num & mask;
}

// Toggles the bit at 'position' in 'num'.
// Returns the modified number.
int toggleBit(int num, int position) {
    int mask = 1 << (position - 1);
    return num ^ mask;
}

// Packs two 4-bit numbers 'a' and 'b' into a single 8-bit number.
// 'a' occupies the higher 4 bits, and 'b' occupies the lower 4 bits.
// Returns the packed 8-bit number.
int packBits(int a, int b) {
    /*
     * a = 1101
     * b = 0011
     * num = 1101 0011
     */    

    // make sure there are no other bits on
    a &= 0x000F;
    b &= 0x000F;

    int num = a << 4;
    return num | b; 
}

// Unpacks an 8-bit number 'packed' into two 4-bit numbers.
// Stores the higher 4 bits in '*a' and the lower 4 bits in '*b'.
void unpackBits(int packed, int *a, int *b) {
    /*
        packed = 0000 0000 1111 1010
        a = 1111
        b = 1010
    */
    
    *a = (packed >> 4) & 0xF;
    *b = packed & 0xF;
}

// Performs a circular left shift on 'num' by 'shift' positions.
// Returns the result of the circular left shift.
int circularLeftShift(int num, int shift) {
    /*
       make sure shift amount is not bigger than the num width
       
       32 bits in this type of int

       shift bits over by shifted amount
       handle overflow case by shifting to the start of the int

       bitwise OR to keep changes of both cases

       This only works for unsigned ints 
    */
    shift %= 32;

    int shifted = num << shift;
    int handleOverflow = num >> (32 - shift);

    return shifted | handleOverflow;
}

// Performs a circular right shift on 'num' by 'shift' positions.
// Returns the result of the circular right shift.
int circularRightShift(int num, int shift) {
    shift %= 32;

    int shifted = num >> shift;
    int handleOverflow = num << (32 - shift);

    return shifted | handleOverflow;
}

int main() {
    int a = 3; // Example value
    int b = 10; // Example value

    // Perform and display results for each bitwise operation
    printf("AND Operation: %d\n", andOperation(a, b));
    printf("OR Operation: %d\n", orOperation(a, b));
    printf("XOR Operation: %d\n", xorOperation(a, b));
    printf("NOT Operation: %d\n", notOperation(a));

    int shift = 2;
    printf("Left Shift: %d\n", leftShift(a, shift));
    printf("Right Shift: %d\n", rightShift(a, shift));

    // Bit manipulation examples
    int position = 2;
    printf("Set Bit: %d\n", setBit(a, position));
    printf("Clear Bit: %d\n", clearBit(a, position));
    printf("Toggle Bit: %d\n", toggleBit(a, position));

    // Packing and unpacking
    int packed = packBits(a, b);
    printf("Packed Bits: %d\n", packed);
    int unpackedA, unpackedB;
    unpackBits(packed, &unpackedA, &unpackedB);
    printf("Unpacked Bits A: %d\n", unpackedA);
    printf("Unpacked Bits B: %d\n", unpackedB);

    // Circular shifts
    printf("Circular Left Shift: %d\n", circularLeftShift(a, shift));
    printf("Circular Right Shift: %d\n", circularRightShift(a, shift));

    return 0;
}
