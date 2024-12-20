#include <stdio.h>
#include <string.h>

// Определяем новую структуру TBook
typedef struct {
    char author[40];  // Поле для автора книги
    char title[80];   // Поле для названия книги
    int count;        // Поле для количества экземпляров книги
} TBook;

// Создаем псевдоним для указателей на структуры TBook
typedef TBook* PBook;
int main()
{
    const int N = 100; // Размер массива книг
    // Инициализируем массив структур TBook
    TBook Books[N];
    // Массив указателей на элементы массива Books
    PBook p[N], p1;
    int i, j, M;       // Переменные для индексов и счетчика записей
    FILE *F;           // Указатель на файл
    // Заполняем массив указателей p адресами элементов массива Books
    for (i = 0; i < N; i++) {
        p[i] = &Books[i];
    }
    // Открываем файл books.dat для чтения в бинарном режиме
    F = fopen("books.dat", "rb");
    // Считываем данные из файла в массив Books
    M = fread(&Books[0], sizeof(TBook), N, F);
    // Закрываем файл
    fclose(F);
    printf("Имеющиеся данные о книгах:\n");
    // Проходим по считанным данным и выводим информацию о каждой книге
    for (i = 0; i < M; i++) {
        printf("%s, %s, %d\n", Books[i].author, Books[i].title, Books[i].count);
    }
    // Сортируем массив указателей p по полю author в алфавитном порядке
    for (i = 0; i < M - 1; i++) {
        for (j = M - 2; j >= i; j--) {
            if (strcmp(p[j]->author, p[j + 1]->author) > 0) {
                p1 = p[j];     // Меняем местами указатели
                p[j] = p[j + 1];
                p[j + 1] = p1;
            }
        }
    }
    printf("\nПосле сортировки через указатели:\n");
    // Проходим по отсортированному массиву указателей и выводим информацию о каждой книге
    for (i = 0; i < M; i++) {
        printf("%s, %s, %d\n", p[i]->author, p[i]->title, p[i]->count);
    }
    getchar();
    return 0;
}

