#include <stdio.h>

void main() {
    int freq = 0;
    int change;
    while (scanf("%d", &change) != EOF) {
        freq += change;
        printf("%d %d\n", change, freq);
    }

    printf("%d", freq);
}
