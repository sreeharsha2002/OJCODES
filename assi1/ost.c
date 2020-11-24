#include<stdio.h>
#define lli long long int
int main()
{
	lli n;
	scanf("%lld",&n);
	lli a[n];
	for(lli i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	lli max=a[0],sum=0,i1=0;
	for(lli i=0;i<n;i++)
	{
		if(a[i]>=max)
		{
			sum=sum+max*(i-i1);
			max=a[i];
			i1=i;

		}
	}
	max=a[n-1];
	lli i2=n-1;
	for(lli i=n-1;i>=0;i--)
	{
		if(a[i]>max)
		{
			sum=sum+max*(i2-i);
			max=a[i];
			i2=i;
		}
	}
	printf("%lld\n",sum);
	return 0;
}

