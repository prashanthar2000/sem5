#include "poly.h"
void insert_at_end(List *list, int data) 
{
	Node *new = malloc(sizeof(struct Node));
	new->data=data;
	new->link=NULL;
	if(list->head==NULL) //if the list is empty
		list->head=new;
	else
	{
		Node *temp= list->head;
		while(temp->link != NULL) //traversing to last node of the LL	
			temp=temp->link;
		temp->link = new;
	}
	list->number_of_nodes++;
}

long long int evaluate(List *list, int x)
{	
	long long int sum =0;
	int pow=1;
	Node *temp=list->head;
	for(int i=1;i<=(list->number_of_nodes);i++)
	{
		for(int j=0; j<i-1;j++) //to calculate x^i
			pow=pow*x;
		sum=sum + (temp->data)*pow;
		temp=temp->link;
		pow=1;
	}
	return sum;	
}
