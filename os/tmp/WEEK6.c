#include <stdio.h>
#include <pthread.h>
#define BUFFER_SIZE 10

int in = 0, out = 0;
int buffer[BUFFER_SIZE];

void *Producer()
{
    int next_produced = 0;
    while (next_produced < 20)
    {
        while (((in + 1) % BUFFER_SIZE) == out)
            ;
        ++next_produced;
        buffer[in] = next_produced;
        printf("Producer: Produced item %d\n", next_produced);
        in = (in + 1) % BUFFER_SIZE;
    }
}

void *Consumer()
{
    int next_consumed = -1;
    while (next_consumed < 20)
    {
        while (in == out)
            ;
        next_consumed = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumer: Consumed item %d\n", next_consumed);
    }
}

int main()
{
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, Producer, NULL);
    pthread_create(&consumer_thread, NULL, Consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
}