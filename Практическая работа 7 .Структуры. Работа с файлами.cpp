#include <stdio.h>
#include <string.h>
typedef
struct {
	char author[40]; // автор, строка
	char title[80]; // название, строка
	int count; // количество, целое
}
TBook;

int main()
{
	const int N = 100;//размер массива
	//инициализация массива
	TBook Books[N];
	int i, M;
	FILE* F;//указыватель на файл
	char s[80];
	F = fopen("books.dat", "rb");//открытие файла
	M = fread(&Books[0], sizeof(TBook), N, F);//чтение данных из файла
	fclose(F);//закрытие файла
	//вывод данных из массива
	printf("Имеющиеся данные о книгах:\n");
	for (i = 0; i < M; i++)
		printf("%s, %s, %d\n",
			Books[i].author, Books[i].title, Books[i].count);

	if (M < N) {
		//ввод данных
		printf("\nВведите поля новой структуры:\n");
		printf("author: ");
		fgets(Books[M].author, sizeof(Books[M].author), stdin);
		printf(" title: ");
		fgets(Books[M].title, sizeof(Books[M].title), stdin);
		printf(" count: ");
		fgets(s, sizeof(s), stdin);
		sscanf(s, "%d", &Books[M].count);
		M++;

		//сохранение данных в файл
		F = fopen("books.dat", "wb");
		fwrite(&Books[0], sizeof(TBook), M, F);
		fclose(F);
	}

	getchar();
}
