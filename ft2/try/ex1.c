#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
	//TODO
	struct Node *temp,*q;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->link=NULL;
	
	if(list->head==NULL)
		list->head=temp;
	else{
		q=list->head;
		while(q->link!=NULL){
			q=q->link;
		}
		q->link=temp;
	}
	list->number_of_nodes++; 
}

void list_delete_front(List* list) {
	//TODO
	struct Node *q;
	q=list->head;
	list->head=q->link;
	free(q);
	list->number_of_nodes--;
}

void list_insert_at (List *list, int data, int position)
{
	//TODO
	struct Node *prev,*temp,*q;
	int i=1;
	q=list->head;
	prev=NULL;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->link=NULL;
	
	while((q!=NULL)&&(i<position)){
		prev=q;
		q=q->link;
		i++;
	}
	
	if(q!=NULL){
		if(prev==NULL){
			temp->link=q;
			list->head=temp;
		}
		else{
			prev->link=temp;
			temp->link=q;
		}
	}
	else{
		if(i==position)
			prev->link=temp;
	}
	list->number_of_nodes++;
}	

void list_reverse(List* list)
{
 	//TODO
 	struct Node *prev,*temp,*current;
 	prev=NULL;
 	current=list->head;
 	while(current!=NULL){
 		temp=current->link;
 		current->link=prev;
 		prev=current;
 		current=temp;
 	}
 	list->head=prev;
}
 	



