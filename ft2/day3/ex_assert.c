#include <stdio.h>
// turn off
#define NDEBUG 1
#include <assert.h>
// assert : macro
// man assert
int main()
{
	printf("ondu\n");
	// assert(10 == 10); // assert <boolean expr>
	assert(10 == 11); 
	printf("eradu\n");
}
