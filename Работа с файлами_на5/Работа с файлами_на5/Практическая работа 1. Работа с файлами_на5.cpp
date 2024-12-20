#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
    int a;
    int b = 0;
    int c = 0;
    int max = 0;

    FILE* fin = fopen("int.txt", "r");
    if (fin == NULL) 
    {
        printf("Ошибка открытия файла.");
    }

    if (fscanf(fin, "%d", &b) != 1)
    {
        printf("Файл пуст.\n");
        fclose(fin);
        return 1;
    }

    while (fscanf(fin, "%d", &a) == 1)
    {
        if (a == b)
        {
            c++;
        }
        else
        {
            if (c + 1 > max)
            {
                max = c + 1;
            }
            c = 0;
        }
        b = a;
    }

    if (c + 1 > max)
    {
        max = c + 1;
    }

    fclose(fin);

    FILE* fout = fopen("out.txt", "w");
    if (fout == NULL)
    {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    fprintf(fout, "%d\n", max);
    fclose(fout);

    printf("Все супер!\n");
    return 0;
}
