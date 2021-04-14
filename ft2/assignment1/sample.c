#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p = (int*) malloc(sizeof(int)* 100);
    for(int i = 0 ; i < 100 ; ++i ) printf("%d\n", &p[i]);
    int s = &p[10];
    printf("%d \n" , s);    
}