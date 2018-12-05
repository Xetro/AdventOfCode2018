#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util/hash_table.h"

#define WORDSIZE 26


void main() {

    char word[WORDSIZE];
    char tmp;
    ht_hash_table *ht = ht_new();

    while (scanf("%s", word) != EOF) {
        for (int i = 0; i < strlen(word); i++) {
            tmp = word[i];
            word[i] = '#';
            if (ht_search(ht, word) != NULL) {
                printf("FOUND WORD: %s\n", word);
                printf("Common characters: ");
                for (int j = 0; j < WORDSIZE; j++) {
                    if (j != i) {
                        printf("%c", word[j]);
                    }
                }
                printf("\n");
            } else {
                ht_insert(ht, word, word);
            }
            word[i] = tmp;
        }
    }
}
