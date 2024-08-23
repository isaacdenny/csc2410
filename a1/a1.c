#include <stdio.h>

int main() {
    int h = 'H';

    char word[6] = "Helo!3";

    for (int i = 0; i < sizeof(word); i++) {
        printf("Character: %c\n", word[i]);
        printf("Decimal: %d\n", word[i]);
        printf("Binary: ");
        for (int j = 128; j > 0; j >>= 1) {
            printf("%s", ((word[i] & j) == j) ? "1" : "0");
        }

        // 
        printf("\n\n");
    }

    // 1000
    // 0100
    // 0010
    // 0001

    return 0;
}