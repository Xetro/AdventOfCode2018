#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charcomp(const void *x, const void *y) { 
    const char *x1 = x;
    const char *y1 = y;
    return *x1 - *y1;
}

void main() {
    int count_two = 0;
    int count_three = 0;
    char line[1024];

    while(scanf("%s", line) != EOF) {
        int set_two = 0;
        int set_three = 0;

        qsort(line, strlen(line), sizeof(char), charcomp);
        printf("%s\n", line);

        for (int i = 0; i < strlen(line); i++) {
            if (i > 0 && line[i - 1] == line[i]) {
                continue;
            }

            if(line[i] == line[i+1]) {
                if(line[i] != line[i+2]) {
                    /* TWO  */
                    if (set_two == 0) {
                        count_two++;
                        set_two = 1;
                    }
                } else if (line[i] != line[i+3]) {
                    /* THREE */
                    if (set_three == 0) {
                        count_three++;
                        set_three = 1;
                    }
                }
            }
        }

    printf(" doubles: %d, triples: %d\n", count_two, count_three);
    }
    printf("Final checksum: %d\n", count_two * count_three);
}
