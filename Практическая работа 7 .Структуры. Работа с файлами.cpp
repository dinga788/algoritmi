#include <stdio.h>
#include <string.h>
typedef
struct {
	char author[40]; // �����, ������
	char title[80]; // ��������, ������
	int count; // ����������, �����
}
TBook;

int main()
{
	const int N = 100;//������ �������
	//������������� �������
	TBook Books[N];
	int i, M;
	FILE* F;//����������� �� ����
	char s[80];
	F = fopen("books.dat", "rb");//�������� �����
	M = fread(&Books[0], sizeof(TBook), N, F);//������ ������ �� �����
	fclose(F);//�������� �����
	//����� ������ �� �������
	printf("��������� ������ � ������:\n");
	for (i = 0; i < M; i++)
		printf("%s, %s, %d\n",
			Books[i].author, Books[i].title, Books[i].count);

	if (M < N) {
		//���� ������
		printf("\n������� ���� ����� ���������:\n");
		printf("author: ");
		fgets(Books[M].author, sizeof(Books[M].author), stdin);
		printf(" title: ");
		fgets(Books[M].title, sizeof(Books[M].title), stdin);
		printf(" count: ");
		fgets(s, sizeof(s), stdin);
		sscanf(s, "%d", &Books[M].count);
		M++;

		//���������� ������ � ����
		F = fopen("books.dat", "wb");
		fwrite(&Books[0], sizeof(TBook), M, F);
		fclose(F);
	}

	getchar();
}
