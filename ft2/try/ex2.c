#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data)
{
	struct Node* upd = malloc(sizeof(struct Node));
    upd->data = data;
    upd->link = NULL;
	
	if (list->head == NULL) {
		list->head = upd;
	}
	else {
		struct Node* temp = list->head;
		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = upd;
	}
	list->number_of_nodes++;
}


void list_delete_front(List* list) 
{
	if (list->head != NULL) {
		struct Node* delete = list->head;
		list->head = delete->link;
		list->number_of_nodes--;
	}
}

void list_insert_at (List *list, int data, int position) 
{

	if (position == 0) {
		struct Node* upd = malloc(sizeof(struct Node));
    	upd->data = data;
		upd->link = list->head;
		list->head = upd;
		list->number_of_nodes += 1;
	}

	else if (position <= list->number_of_nodes && position > 0) {
		struct Node* upd = malloc(sizeof(struct Node));
    	upd->data = data;
		struct Node* temp = list->head;
		for (int index = 0; index <= position; index++) {
			if (index == position - 1) {
				upd->link = temp->link;
				temp->link = upd;
				list->number_of_nodes += 1;
			}
			temp = temp->link;
		}	
	}
	
}

void list_reverse(List* list) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = list->head; 
    struct Node* next = NULL; 

    while (current != NULL) { 
        next = current->link; 
        current->link = prev; 
        prev = current; 
        current = next; 
    } 

    list->head = prev; 
}