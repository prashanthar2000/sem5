#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
    printf("PES1201800410 --  Prashanth A R\n");
    int l ; 
    printf("ENTER SIZE OF AN ARRAY \n");
    scanf("%d", &l);
    int *a = take_input(l);
    a = reverse(a , l);
    display(a,l);
    
}