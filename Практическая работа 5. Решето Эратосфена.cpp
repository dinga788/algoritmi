#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i, k;
	bool A[101];
	int N;

	printf("Input N: ");
	scanf("%d", &N);

	for (i = 2; i <= N; i++)
		A[i] = true;

	k = 2;
	while (k * k <= N)
	{
		if (A[k])
		{
			i = k * k;
			while (i <= N)
			{
				A[i] = false;
				i += k;
			}
		}
		k++;
	}

	for (i = 2; i <= N; i++)
		if (A[i])
			printf("%d ", i);
}
