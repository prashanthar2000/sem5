#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define BUFFER_SIZE 20

int in = 0 ; 
int out = 0 ; 
int counter = 0;
int buffer[BUFFER_SIZE];

void *Producer()
{
    int nextProduced = 0;
    while(1)
    {
        while(counter ==  BUFFER_SIZE  ); //do nothing
        buffer[in] = nextProduced;
        printf("job %d started\n", nextProduced);
        ++nextProduced;  
        in = (in +1) % BUFFER_SIZE;
        ++counter;

        //just to break out of infinite loop
        if(nextProduced == 30)
        {
            break; 
        }
    }     
}

void *Consumer()
{
    int nextConsumed = 0 ; 
    while(1)
    {
        while(counter ==  0); // do nothing
        nextConsumed = buffer[out];
        printf("job %d finished\n", nextConsumed);
        ++nextConsumed;
        out = (out + 1 ) % BUFFER_SIZE;
        --counter ; 

        //just to break out of infinite loop
        if(nextConsumed == 30)
        {
            break;           
        }
    }

    

}

int main()
{
    printf("With race condition\n");
    
    pthread_t producer_thread; 
    pthread_t consumer_thread; 

    pthread_create(&producer_thread , NULL , Producer , NULL);
    pthread_create(&consumer_thread , NULL , Consumer , NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);



}