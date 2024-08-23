#include <stdio.h>

int main() {
    char word[6] = "Helo!3";

    for (int i = 0; i < sizeof(word); i++) {
        printf("Character: %c\n", word[i]);
        printf("Decimal: %d\n", word[i]);
        printf("Binary: ");
        for (int j = 128; j > 0; j >>= 1) {
            printf("%s", ((word[i] & j) == j) ? "1" : "0");
        }
        printf("\n\n");
    }

    return 0;
}