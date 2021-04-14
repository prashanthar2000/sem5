#include <stdio.h>

int main()
{
	int a[5];
	for(int i = 0; i <= 5; ++i)
	{
		a[i] = i * i;
	}
	for(int i = 0; i <= 5; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
