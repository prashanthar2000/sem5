#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int n = 10 ;
    int a[] = {1 ,2 ,3,4, 5,6,7,8,9,10};
    pid_t pid; 
    pid = fork();
    if(pid == 0)
    {
        int sum = 0 ;
        for(int i = 0 ; i < n ; ++i)
        {
            sum += a[i];
        }
        printf("sum :%d\n" , sum);
    
    }
    else
    {
        int prod = 1; 
        for(int i = 0 ; i < n ; ++i)
        {
            prod *= a[i];
        }
        printf("prod :%d\n" , prod);
    }

}
