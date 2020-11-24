#include<iostream>
#define int long long int
using namespace std;
int m=1e9+7;
int sum[100005],par[100005];
int pov(int u,int y)
{
	int r=1;
	while(y>0)
	{
		if (y%2!=0)
		{
		       	r=(r*u)%m;
		}
		u=(u*u)%m;
		y=y/2;
	}
	return r;
}


int root(int i)
{
	while(par[i]!=i)
	{
		i=par[i];
		par[i]=par[par[i]];
	}
	return i;
}
int un(int a,int b)
{
	int ra=root(a);
	int rb=root(b);
	if(sum[ra]>sum[rb])
	{
		par[rb]=ra;
		sum[ra]+=sum[rb];
	}
	else
	{
		par[ra]=rb;
		sum[rb]+=sum[ra];
	}
}
signed main()
{
	int n,m,x=0;
	cin>>n>>m;
	int ar[m];
	for(int i=0;i<m;i++)
	{
		ar[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		sum[i]=1;
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		if(root(a)==root(b))
		{
			x++;
		}

		ar[i]=pov(2,x)-1;
		un(a,b);
	}
	for(int i=0;i<m;i++)
	{
		cout<<ar[i]<<endl;
	}
	return 0;
}





