#include <stdio.h>

int main() {
    int x = 10;
    int y = 20;
    int result;
    if (x < y) {
        result = x + y;
    } else {
        result = x - y;
    }
    printf("Result: %d\n", result);
    return 0;
}
