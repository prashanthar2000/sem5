#include <stdio.h>
int add(int p, int q)
{
	int temp;
	temp = p + q;
	return temp;
}
int main()
{
	int sum;
	int x; int y;
	x = 10;
	y = 20;
	sum = add(x, y);
	printf("sum : %d\n", sum);
}
