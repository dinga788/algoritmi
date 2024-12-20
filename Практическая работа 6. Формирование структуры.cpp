#include <stdio.h>
#include <string.h>
typedef struct 
	{
		char author[40]; // автор, строка
		char title[80]; // название, строка
		int count; // количество, целое
	}TBook;
main ()
{
const int N = 100; // размер массива
//инициализация переменной и массива
TBook B;
TBook Books[N];
char *p, s[40]; //создаём указателия для дальнейшей сортировки авторов
printf ( "Размер структуры TBook: %d\n", sizeof(TBook));
printf ( "Размер переменной B типа Book: %d\n", sizeof(B));
printf ( "Размер поля author: %d\n", sizeof(B.author));
printf ( "Размер поля title: %d\n", sizeof(B.title));
printf ( "Размер поля count: %d\n", sizeof(B.count));
printf ( "Размер массива Books: %d\n", sizeof(Books));
//присваивание значений
strcpy ( B.author, "Пушкин А.С." );
strcpy ( B.title, "Полтава" );
B.count = 1; //значение столбца count
printf ( "Структура B:\n" );
//вывод информации
printf ( "author: %s\n", B.author );
printf ( " title: %s\n", B.title );
printf ( " count: %d\n", B.count );
//записываем значение из author в S, до первого пробела
strcpy ( s, B.author );
p = strchr ( s, ' ' );
*(p+1) = '\0';//Заканчивает строку
printf ( "Фамилия автора: %s\n", s );
B.count --;
//условие для вывода
if ( B.count == 0 )
printf ( "Этих книг больше нет!");
//ввод данных с клавиатуры
printf ( "\nВведите поля структуры B:\n" );
printf ( "author: " );
gets ( B.author );
printf ( " title: " );
gets ( B.title );
printf ( " count: " );
scanf ( "%d", &B.count );
//вывод информации о введённых новых данных
printf ( "Теперь структура B:\n" );
printf ( "author: %s\n", B.author );
printf ( " title: %s\n", B.title );
printf ( " count: %d\n", B.count );
getchar();
}
