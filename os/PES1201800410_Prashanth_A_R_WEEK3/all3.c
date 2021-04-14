#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
    pid_t pid; 
    pid = fork();
    if(pid == 0 )
    {
        printf("child process ....\n");
        char *argv[] = {"argument 1", "argument 2" , "argument3" , NULL};
        execv("./executable_program" ,argv);
        printf("this should not be printed if execv went well");
    }
    else
    {
        printf("wating for child process to complete \n");
        wait(NULL);
        printf("successfully waited till child process is complete \n");
    }
    
}
