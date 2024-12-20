#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main() {
    const int max = 100;
    int a[max];
    int b = 0;
    int n1 = 0, n2 = 0;

    FILE* fin1 = fopen("int1.txt", "r");
    FILE* fin2 = fopen("int2.txt", "r");
    if (fin1 == NULL || fin2 == NULL) {
        printf("Ошибка открытия файла int.txt\n");
        return 1;
    }

    while (n1 < max) {
        int r = fscanf(fin1, "%d", &a[n1]);
        if (r < 1)
            break;
        n1++;
    }

    while (n2 < max) {
        int r = fscanf(fin2, "%d", &a[n1 + n2]);
        if (r < 1)
            break;
        n2++;
    }

    fclose(fin1);
    fclose(fin2);

    bubbleSort(a, n1 + n2);

    FILE* fout = fopen("out.txt", "w");
    if (fout == NULL) {
        printf("Ошибка создания файла out.txt\n");
        return 1;
    }

    for (int i = 0; i < n1 + n2; i++) {
        if (fprintf(fout, "%d\n", a[i]) < 0) {
            printf("Ошибка записи в файл out.txt\n");
            fclose(fout);
            return 1;
        }
    }

    fclose(fout);
    return 0;
}
