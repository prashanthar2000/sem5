#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

enum {THINKING , HUNGRY , EATING};

#define LEFT		(id+5-1)%5
#define RIGHT		(id+1)%5


int state[5];
sem_t philosophers[5];
sem_t mutex;

void think(int id);
void eat(int id );
void pickup_fork(int id);
void drop_fork(int id);
void avalibility(int id );


void *philosopher(int *id)
{
    while(1)
    {
        think(*id);
        pickup_fork(*id);//he /she will eat if he had picked up the fork succesfully
        // eat(id);
        drop_fork(*id);

    }
}
void think(int id)
{
    printf("Philosopher %d is thinking\n", id + 1);
    sleep(1);
}

void eat(int id)
{
    printf("Philosopher %d is eating\n", id + 1);
    sleep(0.001);
}

void pickup_fork(int id)
{
    sem_wait(&mutex);
 	state[id] = HUNGRY;
	printf("Philosopher %d is Hungry\n", id + 1);
	
    avalibility(id);
 	sem_post(&mutex);
 	sem_wait(&philosophers[id]);
}

void avalibility(int id)
{
    if (state[id]==HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
		state[id] = EATING;
		printf("Philosopher %d takes fork %d and %d \n", id + 1, LEFT + 1, id + 1);
		eat(id);
		sem_post(&philosophers[id]);
	}
}
void drop_fork(int id)
{
    sem_wait(&mutex);
	state[id]=THINKING;
	printf("Philosopher %d putting fork %d and %d down\n", id + 1, LEFT + 1, id + 1);
    think(id+1);
	avalibility(LEFT);
	avalibility(RIGHT);
	sem_post(&mutex);
}
int indexs[5] = { 0, 1, 2, 3, 4 };
int main()
{
    pthread_t thd[5];
    int index;
    

    sem_init(&mutex, 0, 1);
	for (index = 0; index < 5; index++)
	{
		sem_init(&philosophers[index], 0, 0);
	}
	for (index = 0; index < 5; index++)
	{
		pthread_create(&thd[index], NULL, philosopher, &indexs[index]);
		
	}

	for (index = 0; index < 5; index++)
	{
		pthread_join(thd[index], NULL);
	}


}

