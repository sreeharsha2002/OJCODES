#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
        int data;
        struct node *next;
}node;

node *head;
void push(int d)
{
        node*temp=(node*)malloc(sizeof(node));
        temp->data=d;
        if(head==NULL)
        {
                temp->next=NULL;
                head=temp;
        }
        else
        {
                temp->next=head;
                head=temp;
        }
}
int main()
{
	head=NULL;
	printf("%d",head->data);
	return 0;
}
