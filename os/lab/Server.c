#include<stdio.h>
#include<stdlib.h>


int * take_input(int l)
{
    int * a = (int*)malloc(sizeof(int)*l);
    printf("ENTER ELEMENTS OF AN ARRAY\n");
    for(int i =0 ; i < l ; ++i )
    {
        scanf("%d", &a[i] );
        // printf("%d", a[i] );
    }
    return a;
}


int * reverse(int *a , int l)
{
    int *p = (int *) malloc(sizeof(int)*l);
    for(int i = 0; i < l ; i++)
    {
        p[i] = a[l -i -1];
    }
    free(a);
    return p;   
}

void display(int* a, int l)
{
    for(int i = 0 ; i < l ; ++i)
    {
        printf("%d" , a[i]);
    }
    printf("\n");

}

