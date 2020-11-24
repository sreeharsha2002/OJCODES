#include<stdio.h>
#define lli long long int
lli head=-1,b[1000003];
void push(lli d)
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
	lli n;
	scanf("%lld",&n);
	lli a[n],b1[n],b2[n];
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			b1[i]=0;
			push(a[i]);
		}
		else
		{
			if(b[head]>a[i])
			{

				b1[i]=b[head];
				push(a[i]);
			}
			else if(b[head]<=a[i])
			{
				while(head!=-1 && b[head]<=a[i])
				{
					pop();
				}
				if(head==-1)
				{
					b1[i]=0;
				}
				else
				{
					b1[i]=b[head];
				}
				push(a[i]);
			}
		}
	}
//	for(int i=0;i<n;i++)
//	{
//	printf("%lld",b1[i]);}
	head=-1;
	for(int i=0;i<n;i++)
	{
		b[i]=0;
	}

	for(int i=n-1;i>=0;i--)
	{
		if(i==n-1)
		{
			b2[i]=0;
			push(a[i]);
		}
		else
		{
			if(b[head]>a[i])
			{
				b2[i]=b[head];
				push(a[i]);
			}
			else if(b[head]<=a[i])
			{
				while(head!=-1 && b[head]<=a[i])
				{
					pop();
				}
				if(head==-1)
				{
					b2[i]=0;
				}
				else
				{
					b2[i]=b[head];
				}
				push(a[i]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		b[i]=b1[i]*b2[i];
	}
	lli max=b[0];
	for(int i=0;i<n;i++)
	{
		if(max<b[i])
			max=b[i];
	}
	printf("%lld\n",max);
	for(int i=0;i<n;i++)
	{
		printf("%lld ",b1[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%lld ",b2[i]);
	}

	return 0;
}






