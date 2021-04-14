#include "poly.h"
void insert_at_end(List *list, int data) 
{
	//Create node to be inserted as well as a temporary node
	Node *new_node,*q;
	new_node=(Node*)malloc(sizeof(Node));
	new_node->data=data;
	new_node->link=NULL;
	
	//check if first node
	if(list->head==NULL)
		list->head=new_node;
	
	else{
		q=list->head;
		while(q->link!=NULL){
			q=q->link;
		}
		q->link=new_node;
	}
	
	list->number_of_nodes++;
}

long long int evaluate(List *list, int x)
{
    #include<math.h>
	long long int value=0;
	int n=0;
	Node *q;
	q=list->head;
	
	while(n<list->number_of_nodes){
		value=value+((q->data)*(pow(x,n)));
		q=q->link;
		n++;
	}
	
	return value;

}
