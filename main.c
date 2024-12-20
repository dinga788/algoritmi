#include <stdio.h>
#include "TWordList.h"

int main()
{
    TWordList L;
    int p;
    char s[80];
    FILE* F;
    
    L.size = 0;
    L.capacity = 10;
    L.data = (TPair*)calloc(L.capacity, sizeof(TPair));

    F = fopen("words.txt", "r");
    while (fscanf(F, "%s", s) != EOF) {
        p = Find(L, s);
        if (p >= 0) {
            L.data[p].count++;
        } else {
            p = FindPlace(L, s);
            InsertWord(&L, p, s);
        }
    }
    fclose(F);

    F = fopen("ww.txt", "w");
    for (p = 0; p < L.size; p++) {
        fprintf(F, "%s: %d\n", L.data[p].word, L.data[p].count);
    }
    fclose(F);

    printf("\nРезультат записан в файл ww.txt\n");
    getchar();

    free(L.data);
    return 0;
}