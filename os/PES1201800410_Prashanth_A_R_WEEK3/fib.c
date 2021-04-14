#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc , char* argv[])
{
  
  int a = 0 ;
  int b = 1 ;
  int temp = 0 ;
  /*
  for(int i = 0 ; i < argc ; i++)
  {
    printf("%d \n" , atoi(argv[i])  );
  }
  */
  
  
  //int arg = argc;  
  pid_t pid;
  // child process
  int num =  atoi(argv[1]);

  //printf("fib of:%d \n" , num); 

  pid = fork();
  if(pid == 0)
  { 
    
    printf("%d ", a);
    if(num == 1)
    {
      return 0;
    }
    printf("%d " , b);
    if(num == 2)
    {
      return 0;
    }
    for(int i =2; i < num ; i++)
    {
      temp = a + b;
      printf("%d ", temp);
      a = b;
      b = temp;
    }
  }

  else
  {
    //parent process do nothing
    return 0;
  }
  

}
