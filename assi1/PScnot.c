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
void pop()
{
	node*temp;
	node*temp1;
	temp1=head;
	if(head==NULL)
	{
	
	}
	else
	{
		temp=head->next;
		head=temp;
		free(temp1);
		
	}
}
void destroy()
{
	node*temp;
	node*temp1;
	temp=head;
	while(temp!=NULL)
	{
		temp1=temp;
		temp=temp->next;
		free(temp1);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int p=0;p<t;p++)
	{
		int n;
		scanf("%d",&n);
		int a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		head=NULL;
		int j=1,i=0;
		while(i<n)
		{
			if(j==a[i])
			{
				j++;
				if(i==n-1)
				{
					if(head==NULL)
					{
						
					}
					else if(j==head->data)
					{
						pop();
						j++;
					}
					else if(j!=head->data)
					{
						printf("No\n");
						break;
					}
				}
				i++;
			}
			else if(j!=a[i])
			{
				if(head==NULL)
				{
					push(a[i]);
					i++;
				}

				else  if((head->data==j)&&(i==n-1))
				{
					pop();
					j++;
					i++;
				}
				 else if((head->data==j)&&(i!=n-1))
				 {
					 pop();
					 j++;
				 }
				else if((head->data!=j)&&(i!=n-1))
				{
					push(a[i]);
					i++;
				}

				else if((head->data!=j)&&(i==n-1))
				{

					printf("No\n");
					break;
				}
			}
		}
		//printf("%d",i);
		if(i==n)
		{
			printf("Yes\n");
		}
	}
	destroy();
	return 0;
}
			

					















































































