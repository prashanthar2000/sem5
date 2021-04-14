#include "poly.h"
void insert_at_end(List *list, int data)
{
	struct Node *temp = malloc(sizeof(struct Node));
	temp->data = data;
	temp->link = NULL;

	if(list->head == NULL)
        list->head=temp;
    else
    {
        struct Node *q = list->head;
        while(q->link != NULL)
            q=q->link;
        q->link=temp;
    }
}

long long int evaluate(List *list, int x)
{
    int result=0;
    int i=0,base;
    double power=1;

    Node *temp;
    temp=list->head;

    for(;i<list->number_of_nodes;i++)
    {
        base=i;
        while(base!=0)
        {
            power*=x;
            base--;
        }
        result+=((temp->data)*power);
        temp=temp->link;
        power=1;
    }
    return result;
}
