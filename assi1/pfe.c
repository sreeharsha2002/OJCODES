#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long double data;
	struct node *next;
}node;

node *head;
node *current;

void push(long double d)
{
	node *temp=(node*)malloc(sizeof(node));
	if(head==NULL)
	{
		temp->data=d;
		temp->next=NULL;
		head=temp;
		current=NULL;
	}
	else
	{
		temp->data=d;
		temp->next=head;
		head=temp;
		current=head->next;
	}
}
void pop()
{
	node*temp;
	node*temp1=head;
	if(head==NULL)
	{
		current=NULL;
	}
	else 
	{
		temp=head->next;
		head=temp;
		if(head==NULL)current=NULL;
		else
	current=head->next;
	}
	free(temp1);
}		
long double stri(char *a)
{
	long double c=0;
	int i=0;
	while(a[i]!='\0')
	{
		c=c*10+a[i]-'0';
		i++;
	}
	return c;
}
int main()
{
	int t,i,j;
	char str[10001][12];
	char x;
	scanf("%d",&t);
	getchar();
	for(int p=0;p<t;p++)
	{
		head=NULL;
		current=NULL;
		 i=0,j=0;
		while(scanf("%c",&x))
		{
			if(x ==' ')
			{
				str[i][j]='\0';
				i++;
				j=0;
			}
			else if(x =='\n')
			{
				str[i][j]='\0';
				break;
			}
			else
			{
				str[i][j]=x;
				j++;
			}
		}
/*		push(1);
		push(30);
		display();
		pop();
		display();
		push(3980);
		display();
		pop();
		display();*/
		for(int u=0;u<=i;u++)
		{
			if(str[u][0]=='+')
			{
				
				{
					long double a=(current->data)+(head->data);
					pop();
					pop();
					push(a);
				}
			}
			else if(str[u][0]=='-')
                        {
                                {
					long double a=(current->data)-(head->data);
                                        pop();
                                        pop();
                                        push(a);
                                }
                        }
			else if(str[u][0]=='*')
                        {
                                {
					long double a=(current->data)*(head->data);
                                        pop();
                                        pop();
                                        push(a);
                                }
                        }
			else if(str[u][0]=='/')
                        {
                                {
					long double a=(current->data)/(head->data);
                                        pop();
                                        pop();
                                        push(a);
                                }
                        }
			else if(str[u][0]=='\0')
			{

			}

			else
			{
				push(stri(str[u]));
			}
		}
	printf("%0.6Lf\n",head->data);
	//	destroy();
	free(head);
	}
	return 0;
}
				

