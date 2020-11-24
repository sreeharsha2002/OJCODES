#include<stdio.h>
int a[104],b[104],head=-1;
void push(int d)
{
	head++;
	b[head]=d;
}
void pop()
{
	b[head]=0;
	head--;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int p=0;p<t;p++)
	{
		head=-1;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			b[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int j=1,i=0;
		   while(i<n)
                {
                        if(j==a[i])
                        {
                                j++;
                                if(i==n-1)
                                {
                                        if(head==-1)
                                        {

                                        }
                                        else if(j==b[head])
                                        {
                                                pop();
                                                j++;
                                        }
                                        else if(j!=b[head])
                                        {
                                                printf("No\n");
                                                break;
                                        }
                                }
				else
                                i++;
                        }
                        else if(j!=a[i])
                        {
                                if(head==-1)
                                {
                                        push(a[i]);
                                        i++;
                                }

                                else  if((b[head]==j)&&(i==n-1))
                                {
                                        pop();
                                        j++;
					if(head==-1)
					{
						i++;
					}

                                }
                                 else if((b[head]==j)&&(i!=n-1))
                                 {
                                         pop();
                                         j++;
                                 }
                                else if((b[head]!=j)&&(i!=n-1))
                                {
                                        push(a[i]);
                                        i++;
                                }

                                else if((b[head]!=j)&&(i==n-1))
                                {

                                        printf("No\n");
                                        break;
                                }
                        }
                }
                if(i==n)
		{
			printf("Yes\n");
		}
	}
	return 0;
}




