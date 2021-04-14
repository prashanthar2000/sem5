#include<stdlib.h>
#include<stdio.h>

int main()
{
    int max_range = 0; 
    printf("Enter max range of the disk\n");
    scanf("%d", &max_range);

    int queue_size = 0 ; 
    printf("Enter the size of queue request\n");
    scanf("%d", &queue_size );

    printf("Enter the queue of disk positions to be read\n");
    
    int *queue = (int*)malloc(sizeof(int)*queue_size+1);
    for(int i =1 ; i <= queue_size ; ++i)
    {
        scanf("%d" , &queue[i]);
    }

    // for(int i = 0 ; i < queue_size ; ++i)
    // {
    //     printf("%d " , queue[i]);
    // }

    // int head = 0 ; 
    printf("Enter the initial head position\n");
    scanf("%d" , &queue[0]);

    int seek = 0 ;
    int diff = 0 ;  
    for(int i = 0 ; i < queue_size ;++i )
    {
        diff = abs(queue[i+1] - queue[i]);
        seek += diff;
        printf("Disk head moves from %d to %d with seek %d\n",queue[i],queue[i+1],diff);
    }
    
    double avg = seek / (double)queue_size;
    // printf("%f %d %d" , avg , seek , queue_size);
    printf("Total seek time is %d\n",seek);
	printf("Average seek time is %f\n",avg);


}