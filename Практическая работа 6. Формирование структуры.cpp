#include <stdio.h>
#include <string.h>
typedef struct 
	{
		char author[40]; // �����, ������
		char title[80]; // ��������, ������
		int count; // ����������, �����
	}TBook;
main ()
{
const int N = 100; // ������ �������
//������������� ���������� � �������
TBook B;
TBook Books[N];
char *p, s[40]; //������ ���������� ��� ���������� ���������� �������
printf ( "������ ��������� TBook: %d\n", sizeof(TBook));
printf ( "������ ���������� B ���� Book: %d\n", sizeof(B));
printf ( "������ ���� author: %d\n", sizeof(B.author));
printf ( "������ ���� title: %d\n", sizeof(B.title));
printf ( "������ ���� count: %d\n", sizeof(B.count));
printf ( "������ ������� Books: %d\n", sizeof(Books));
//������������ ��������
strcpy ( B.author, "������ �.�." );
strcpy ( B.title, "�������" );
B.count = 1; //�������� ������� count
printf ( "��������� B:\n" );
//����� ����������
printf ( "author: %s\n", B.author );
printf ( " title: %s\n", B.title );
printf ( " count: %d\n", B.count );
//���������� �������� �� author � S, �� ������� �������
strcpy ( s, B.author );
p = strchr ( s, ' ' );
*(p+1) = '\0';//����������� ������
printf ( "������� ������: %s\n", s );
B.count --;
//������� ��� ������
if ( B.count == 0 )
printf ( "���� ���� ������ ���!");
//���� ������ � ����������
printf ( "\n������� ���� ��������� B:\n" );
printf ( "author: " );
gets ( B.author );
printf ( " title: " );
gets ( B.title );
printf ( " count: " );
scanf ( "%d", &B.count );
//����� ���������� � �������� ����� ������
printf ( "������ ��������� B:\n" );
printf ( "author: %s\n", B.author );
printf ( " title: %s\n", B.title );
printf ( " count: %d\n", B.count );
getchar();
}
