#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#define BufferSize 10
sem_t full,empty;
int in = 0, out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;
void *producer(void *prth)
{
    for(int i = 0; i < 10; i++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = i;
        printf("Produced item is: %d\n",buffer[in]);
        in = (in+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cnth)
{
    for(int i = 0; i < 10; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumed item is: %d\n",item);
        out = (out+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
int main()
{ 
    pthread_t prth,cnth;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);
    pthread_create(&prth, NULL, (void *)producer, NULL);
    pthread_create(&cnth, NULL, (void *)consumer, NULL);
    pthread_join(prth, NULL);
    pthread_join(cnth, NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
