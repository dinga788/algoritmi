#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a, s = 0.0L;
	int b = 0;
	FILE* fin, * fout;
	fin = fopen("i.txt", "r");
	fout = fopen("o.txt", "w");

	while (fscanf(fin, "%lf", &a) == 1)
	{
		s += a;
		b++;
	}
	if (b > 0)
	{
		s = s / b;
	}
	
	fclose(fin);
	fout = fopen("o.txt", "w");
	fprintf(fout, "%.2lf", s);
	fclose(fout);
}