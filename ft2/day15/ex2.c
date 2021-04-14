#include <stdio.h>
int compute(int p, int q)
{
	int temp;
	temp = p / q;
	return temp;
}
int main()
{
	int res;
	int x; int y;
	x = 10;
	y = 20;
	res = compute(x, y);
	printf("sum : %d\n", res);
	
	x = 10;
	y = 0;
	res = compute(x, y);
	printf("sum : %d\n", res);
	printf("end\n");
		
	
}
