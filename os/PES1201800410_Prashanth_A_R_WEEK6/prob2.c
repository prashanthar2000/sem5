#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int mutex = 1 ;
int empty = BUFFER_SIZE  ; 
int full = 0; 
int buffer[BUFFER_SIZE];

int in  = 0 ;
int out = 0 ;

int wait(int *mutex)
{
    while(*mutex <= 0) ;
    return --*mutex; 
    
}

void signal(int *mutex)
{
    ++*mutex; 
}



void *Producer()
{
    int nextProduced = 0;
    int buffer_empty = 0;
    while(1)
    {
        wait(&empty); //no empty space left 
        wait(&mutex);
    
        //produce the product
        buffer[in] = nextProduced;
        printf("job %d started\n", nextProduced);
        ++nextProduced;  
        in = (in + 1 ) % BUFFER_SIZE;


        signal(&mutex);
        signal(&full);
        sleep(1);
        


    }     
}

void *Consumer()
{
    int nextConsumed = 0 ; 
    int index = 0;
    while(1)
    {
        wait(&full);
        wait(&mutex);
        
        //consume a product
        nextConsumed = buffer[out];
        printf("job %d finished\n", nextConsumed);
        ++nextConsumed;
        out = (out + 1 ) % BUFFER_SIZE;

        signal(&mutex);
        signal(&empty);
        

        

    }
}

int main()
{
    printf("Without race condition\n");
    
    pthread_t producer_thread; 
    pthread_t consumer_thread; 

    pthread_create(&producer_thread , NULL , Producer , NULL);
    pthread_create(&consumer_thread , NULL , Consumer , NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);



}