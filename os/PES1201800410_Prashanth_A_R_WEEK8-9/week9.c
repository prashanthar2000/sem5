#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void producer(FILE *pipewrite)
    {
        int i;
        for(i = 1; i <= 10; i++) {
        fprintf(pipewrite, "%d ", i);
        printf("Producer: Sent %d\n", i);
    }
    fclose(pipewrite);
    exit(0);
}
void consumer(FILE *piperead)
{
    int n,k;
    while(1) {
        int n = fscanf(piperead, "%d", &k);
        if(n == 1) printf("Consumer: Got %d\n", k);
        else break;
    }
    fclose(piperead);
    exit(0);
}
int main()
{
    pid_t p_id, c_id;
    int pd[2];
    FILE *pipewrite, *piperead;
    pipe(pd);
    piperead = fdopen(pd[0], "r");
    pipewrite = fdopen(pd[1], "w");
    p_id = fork();
    if(p_id == 0) {
        fclose(piperead);
        producer(pipewrite);
    }
    c_id = fork();
    if(c_id == 0) {
        fclose(pipewrite);
        consumer(piperead);
    }
    fclose(piperead);
    fclose(pipewrite);
    wait(NULL);
    wait(NULL);
    return 0;
}
