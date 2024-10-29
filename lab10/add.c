#include <stdio.h>

int sum(int x, int y) {
    int c = 0;
    c = x + y;
    return c;
}

int main() {
    int z = 0, x = 4, y = 6;
    z = sum(x, y);
    printf("Sum is: %d\n", z);
    return 0;
}
