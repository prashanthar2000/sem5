#include<stdio.h>
#include<stdlib.h>

int main()
{
    long **p = (long**) malloc(sizeof(long*) * 100000000000000000000000);
    printf("ok this works");
    //exit(0);
    for(int i = 0 ; i < 1000000000 ; i++){
        p= (int*)malloc(sizeof(int)*i);
        free(p); //to see if the garbase collection workds well ; yo it actullay works 
        printf("%d\n" , i);
    }
       printf("it should do probably");
}
