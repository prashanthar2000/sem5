void forkexample() 
{ 
    int x = 1; 
  
    if (fork() == 0) 
        printf("Child has x = %d\n", ++x); 
    else
        printf("Parent has x = %d\n", --x); 
} 
int main() 
{ 
    forkexample(); 
    return 0; 
} 
