#include <stdio.h>

int main(int argc , char* argv[])
{
    printf("\ncustom executable_program, does nothing useful though \n");
    printf("printing all the arguments passed\n");
    for(int i = 0 ; i < argc ; ++i)
    {
        printf("%s\n" , argv[i] );
    } 
    printf("\n");
    

}
