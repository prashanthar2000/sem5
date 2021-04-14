#include<stdio.h> 
#include<stdlib.h>

#if 1 
struct node
{
    int pid; 
    int burst; 
    int priority;
};
typedef struct node node_t;

#endif 

#if 1 

void disp(node_t *proc , int jobs)
{    
    for(int i = 0 ; i < jobs; ++i)
    {
        printf("%d \t %d\n" , proc[i].pid , proc[i].burst);
    }
}    
#endif

void swap(node_t *x, node_t *y) 
{ 
    node_t temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void sort(node_t *proc , int num)
{
    //disp(proc, num);
    //printf("\n");
    for(int i = 0 ; i < num -1 ; ++i)
    {
    
        for(int j = i+1 ; j < num ; ++j)
        {
            //printf("%d %d \n", i , j);
            if(proc[i].priority > proc[j].priority)
            {
                
                //printf("i: %d \tj: %d\t i.burst %d\t i.pid %d \t j.burst %d\t j.pid %d\n", i , j ,proc[i].burst ,proc[i].pid , proc[j].burst , proc[j].pid );
                swap(&proc[i] , &proc[j]);
                //disp(proc , num);
            }    
        }
    }
    
}



int main()
{
    printf("***Priority Scheduling***\nEnter no of Jobs: ");
    int jobs = 0 ; 
    scanf("%d" , &jobs);
    
    node_t *proc = (node_t*)malloc(sizeof(node_t)*jobs);
    
    
    for(int i = 0; i < jobs ; ++i )
    {
        printf("Enter Burst Time of %d Process: " , i+1);
        proc[i].pid = i+1; 
        scanf("%d" , &proc[i].burst);  
        printf("Enter Priority of %d Process: " , i+1); 
        scanf("%d" , &proc[i].priority);
    }
    printf("\n");
    sort(proc , jobs);
    int *w = (int*) malloc(sizeof(int)*jobs+1);
    int *t = (int*)malloc(sizeof(int)*jobs);
    
    w[0] = 0;
    t[0] = 0; 

    int avg_wait = 0; 
    int avg_turn = 0;
    
    printf("Jobs\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n"); 
    for(int i = 0 ; i < jobs ; ++i )
    {   
        t[i+1] = t[i] + proc[i].burst;    
        printf("%d \t   %d\t\t   %d   \t\t    %d \t\t   %d\n" , proc[i].pid ,proc[i].priority, proc[i].burst , w[i] , t[i+1] );
        w[i+1] = w[i] + proc[i].burst;
        avg_wait += w[i] ;  
        avg_turn += t[i+1];         
    }
    printf("\tAverage Waiting time is %f \n\tAverage turn around time is %f \n" , avg_wait/(float)jobs , avg_turn/ (float)jobs );
       
}


