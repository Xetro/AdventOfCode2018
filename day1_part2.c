#include <stdio.h>
#include <stdlib.h>

void setBit(int pos);
int checkBit(int pos);
void adjustFreq(int change);

int* bitmap = NULL;
size_t size_bitmap = 0;
int* input = NULL;
size_t size_input = 0;
int count = 0;

int freq = 0;
int found = 0;

void main() {
    setBit(0);
    int change;
    while (scanf("%d", &change) != EOF) {
        size_input++;
        void* new_ptr = realloc(input, size_input * sizeof(int));
        if (new_ptr == NULL && size_input != 0) {
            puts("Out of memory");
            break;
        }
        input = new_ptr;
        input[size_input - 1] = change;
    }

    while (found == 0) {
        for (int i = 0;i < size_input;i++) {
            adjustFreq(input[i]);
            if (found == 1) {
                break;
            }
        }
    }

    free(input);
    free(bitmap);
    bitmap = NULL;
    input = NULL;
}


void adjustFreq(int change) {
    freq += change;
    if (checkBit(freq)) {
        printf("twice: %d\n", freq);
        printf("%d\n", count);
        found = 1;
    } else {
        setBit(freq);
    }
}

void setBit(int pos) {
        int i = abs(pos / 16);

        if (i >= size_bitmap) {
            int diff = i - size_bitmap;
            size_bitmap = i + 1;
            void* new_ptr = realloc(bitmap, size_bitmap * sizeof(int));
            if (new_ptr == NULL && size_bitmap != 0) {
                puts("Out of memory");
            }
            bitmap = new_ptr;
            for (int j = 0; j <= diff; j++) {
                bitmap[i - j] = 0;
            }
        }

        count++;

        int k = 2 * (abs(pos) % 16);

        if (pos < 0) {
            k++;
        }
        unsigned int flag = 1;
        flag = flag << k;
        bitmap[i] = bitmap[i] | flag;
}

int checkBit(int pos) {
        int i = abs(pos / 16);

        if (i >= size_bitmap) {
            return 0;
        } 
        int k = 2 * (abs(pos) % 16);
        
        if (pos < 0) {
            k++;
        }
        unsigned int flag = 1;
        flag = flag << k;
        
        if ((bitmap[i] & flag) == flag) {
            return 1;
        }
        return 0; 
}
