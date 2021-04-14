#include<stdio.h>
#include<stdlib.h>

// #define MAX_PARTITIONS 100

typedef struct partition
{
    int size ; 
    char *proc_name ; 
    int unused; 
} part_t; 

typedef struct process
{
    int size; 
    char name[5]; 
}proc_t;


int main()
{
    int n; 
    printf("Enter the number of memory segments:");
	scanf("%d",&n);
    part_t** part = (part_t**)malloc(sizeof(part_t*)*n);
    printf("\nEnter the Values:");
    for(int i = 0 ; i < n ; ++i)
    {
        part[i] = (part_t*)malloc(sizeof(part_t));
        printf("\nEnter Partition Size:");
		scanf("%d",&part[i]->size) ;
        // part[i]->proc_name = "";
        part[i]->unused = part[i]->size;
    }


    // for(int i =0 ; i < n ; ++i)
    // {
    //     printf("%d %s %d\n" , part[i]->size , part[i]->proc_name , part[i]->unused);
    // }
    int p;
    printf("Enter the number of processes to assign the memory:");
	scanf("%d",&p);
    // printf("n = %d\n", n );
    proc_t** proc = (proc_t**)malloc(sizeof(proc_t*)*n);
    
    // char ch[10];
    for(int i = 0 ; i < p ; ++i)
    {
        proc[i] = (proc_t*)malloc(sizeof(proc_t));
        printf("Enter the name of the process:");
		scanf("%s",proc[i]->name);
		// scanf("%s",ch);
        // printf("%s\n", ch);
        
        // printf("%s\n", proc[i]->name);
		printf("Enter the size of the process: ");
		scanf("%d",&proc[i]->size);

    }

    // for(int i = 0 ; i < n ; ++i)
    // {
    //     printf("\n %d %d %s" , i ,  proc[i]->size , proc[i]->name );   
    // }
    // printf("\n");
    int alloc_table[p];
    int unalloc_table[n];
    for(int i = 0 ; i < n ; ++i)
    {   
        unalloc_table[i]= 0;
    }
    int min = 99999;
    int min_index = 0;
    for(int i = 0 ; i < p ; ++i)
    {
        min = 99999;
        for(int j = 0 ; j < n ; ++j)
        {
            // printf(" i %d , j %d\n" , i , j );
            // printf("%d %d %d")
            if(part[j]->unused<= min && part[j]->unused >= proc[i]->size)
            {
                // printf("found min %d\n" , part[j]->unused);
                min = part[j]->unused;
                min_index =j; 
            }

        }
        part[min_index]->proc_name = proc[i]->name;
        part[min_index]->unused = part[min_index]->size - proc[i]->size;
        alloc_table[i] = min_index;
        unalloc_table[min_index] = 1;
    }

    printf("\nPartition no\tPartition_size\tPartition Status\tFragment\n");
    for(int i = 0 ; i < p ; ++i)
    {
        int idx = alloc_table[i];
        printf("%d\t\t%d\t\tallocated(%s)\t\t%d\t\t\n",i,part[idx]->size,part[idx]->proc_name,part[idx]->unused);

    }

    for(int i = 0 ; i < n ; ++i)
    {
        if(!unalloc_table[i])
        {
            printf("%d\t\t%d\t\tfree\t\t \n" , i , part[i]->size );
        }
    }

}