#include<stdio.h> 

int main()
{

    int foo = -10;
    printf("foo  %d \n", foo); 
    while(foo)
    {
        printf("foo  %d \n", foo);
        ++foo; 
    }
    printf("out of while looop \nfoo  %d \n", foo); 


}
