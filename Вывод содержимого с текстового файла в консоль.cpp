#include<stdio.h>
#define N 80
int main()
{
	FILE *fin;
	char arr[N];
	fin = fopen("marks.csv", "r");
	while(fgets(arr,N,fin)!=NULL)
	{
		printf("%s", arr);
	}
	printf("\n");
	fclose(fin);
}

