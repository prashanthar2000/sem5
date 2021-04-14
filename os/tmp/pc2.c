#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int in=0, out=0;
int buffer[10000];


int item_count = 0;				// Semaphore for buffer empty
int mutex = 1;
//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void wait(int *semaphore)
{
	while(*semaphore <= 0) ;
	*semaphore -= 1;
}

void signal(int *semaphore)
{
	*semaphore += 1;
}

void *producer()
{
    int next_produced = 0;
    while(1) 
    {
        wait(&mutex);								// Acquire lock before entering critical section
		next_produced++;						// Produce an item
		printf("Producer : Produced item %d\n", next_produced);
		buffer[in++] = next_produced;
		signal(&item_count);						// Increment product count
        signal(&mutex);							// Release lock
        sleep(rand()%2);
    }
}

void *consumer()
{
    int next_consumed;
    while(1) 
    {   	
        wait(&item_count);							// Wait if buffer is empty
		wait(&mutex);							// Acquire lock before entering critical section		
			next_consumed = buffer[out++];
			printf("Consumer : Consumed item %d\n", next_consumed);
		signal(&mutex);						// Release lock
        sleep(rand()%3);
    }
}

int main()
{
    pthread_t p_thread, c_thread;
    pthread_create(&p_thread, NULL, producer, NULL);
    pthread_create(&c_thread, NULL, consumer, NULL);
    pthread_join(p_thread, NULL);
    pthread_join(c_thread, NULL);
}
