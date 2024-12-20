#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Person {
    char name[81];
    int score;
} Person;

Person people[100];
int personCount = 0;

void swap(Person& a, Person& b) {
    Person temp = a;
    a = b;
    b = temp;
}

void selectionSort(Person arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].score > arr[maxIndex].score) {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

int main() {
    char s[80], original_s[80];
    int bal;
    FILE* Fin, * Fout;
    Fin = fopen("int.txt", "r");
    if (Fin) {
        while (fgets(s, sizeof(s), Fin)) {
            s[strcspn(s, "\n")] = '\0';

            strcpy(original_s, s);

            if (sscanf(s, "%[^0-9]%d", original_s, &bal) == 2) {
                if (bal > 80) {

                    strcpy(people[personCount].name, original_s);
                    people[personCount].score = bal;
                    personCount++;
                }
            }
        }

        selectionSort(people, personCount);

        Fout = fopen("out.txt", "w");
        for (int i = 0; i < personCount; i++) {
            char first_name[40], last_initial[2];
            sscanf(people[i].name, "%39s %1s", first_name, last_initial);
            fprintf(Fout, "%s. %s %d\n", last_initial, first_name, people[i].score);
        }
        fclose(Fout);
        printf("Данные сохранены в файле 'out.txt'.");
        fclose(Fin);
    }
    else {
        printf("Не удалось открыть файл 'int.txt'.");
    }
    getchar();
    return 0;
}
