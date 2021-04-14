#include<stdio.h>
 
void main()
{
	int fragment[20],b[20],p[20],n,p_size,temp,min=9999;
	char p_name[20];
	printf("\nEnter the number of memory segments:");
	scanf("%d",&n);
	int visited[n+1],index[n+1];
	printf("\nEnter the Values:");
	for(int i=1;i<=n;i++)
    	{	
		visited[i]=0;
		index[i]=-1;
		printf("\nEnter Partition Size:");
        	scanf("%d",&b[i]);
    	}
	printf("Enter the number of processes to assign the memory:");
	scanf("%d",&p_size);	
	for(int i=1;i<=p_size;i++)
    	{
        	printf("\nEnter the name of the process:");
		scanf(" %c",&p_name[i]);
	    	printf("\nEnter the size of the process :");
        	scanf("%d",&p[i]);
    	}
	
	for(int i=1;i<=p_size;i++)
	{
	for(int j=1;j<=n;j++)
		{
			if(visited[j]!=1)
			{
				temp=b[j]-p[i];
				if(temp>=0)
					if(min>temp)
					{	
						visited[index[i]]=0;
						index[i]=j;
						min=temp;
					}
			}
		}
		
		fragment[i]=min;
		visited[index[i]]=1;
		min=10000;
	}


	printf("Partition no\tPartition_size\tPartition Status\tFragment\n");
	int count=0;
	for(int i=1;i<=n ;i++){
		if(index[i]!=-1)
			printf("%d\t\t%d\t\tAllocated<%c>\t\t%d\n",i,b[index[i]],p_name[i],fragment[i]);
	}
	for(int j=1;j<=n ;j++){
		if(visited[j]!=1){
			count++;
			printf("%d\t\t%d\t\tfree\t\t \n",n+(n-p_size)-count,b[j]);
		}
	}
}
		
