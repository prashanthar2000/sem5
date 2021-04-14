#include <stdio.h>
#include <stdlib.h>


int main()
{   
    int n; 
    printf("Enter the number of processes: ");
    scanf("%d" , &n);
    printf("\n");
    int *bt = (int*)malloc(sizeof(int)* n);
    for(int i = 0 ; i < n ; ++i)
    {
        printf("Enter the process id : %d\n" , i+1 );
        printf("Enter the burst time: ");
        scanf("%d" , &bt[i]);
        printf("\n");

    }
    int tq; //time quantum
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    printf("\n");
    // for(int i = 0 ; i< n ; ++i)
    // {
    //     printf("%d\n" , bt[i]);

    // }

    int *rem_bt = (int*)malloc(sizeof(int)*n);
    int *wt = (int*)malloc(sizeof(int)*n);
    
    for(int i = 0 ; i < n ; ++i)
    {
        rem_bt[i] = bt[i];   
    }
    int ct = 0 ; // current time
    int done = 0;
    while(!done)
    {
        // printf("not yet\n");
        done = 1;
        for(int i = 0 ; i < n ; ++i)
        {
            if(rem_bt[i] > 0)
            {
                // printf("inside if %d  %d\n", rem_bt[i] , ct);
                done = 0;
                if(rem_bt[i] > tq)
                {
                    ct += tq;
                    rem_bt[i] -= tq;
                }
                else
                {
                    // printf("inside else %d  %d\n", rem_bt[i] , ct);
                    //last round
                    ct = ct + rem_bt[i];
                    wt[i] = ct - bt[i];
                    rem_bt[i] = 0;
                }
            }
            
        }
    }

    int wt_avg = 0 ;
    int tat_avg = 0;
    printf("Process pid\tburst time\twaiting time\tturn around time\n");
    for(int i = 0 ; i < n ; ++i)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\n" , i+1 , bt[i] , wt[i] , wt[i]+bt[i]);
        wt_avg += wt[i];
        tat_avg += wt[i] + bt[i];

    }
    printf("average Waiting time is %f\n", (float)wt_avg/ (float)n);
    printf("average turn around time is %f\n", (float)tat_avg/(float)n);
}
