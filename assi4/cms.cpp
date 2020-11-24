#include<bits/stdc++.h>
#define int long long int
using namespace std;
int sum[3005],par[3005];
vector<int>v1[3005];
bool vis[3005];
int xorarr[3005];
int m=1e9+7;
void dfs(int p)
{
	vis[p]=true;
	for(int i=0;i<v1[p].size();i++)
	{
		if(vis[v1[p][i]]==false)
		{
			dfs(v1[p][i]);
		}
	}
}
int powerof(int a, int b)
{
	int r=1;
	while(b>0)
	{
		if(b%2==1)
		{
			r=(r*a)%m;
		}
		a=(a*a)%m;
		b=b/2;
	}
	return r;
}
int root(int i)
{
	if(par[i]==i)
	{
		return i;
	}
	int rr=par[i];
	par[i]= root(par[i]);
	xorarr[i]=xorarr[i]^xorarr[rr];
	return par[i];

}

int un(int a,int b,int c)
{
	int ra=root(a);
	int rb=root(b);
	if(sum[ra]>sum[rb])
	{
		par[rb]=ra;
		sum[ra]+=sum[rb];
		xorarr[rb]=xorarr[a]^xorarr[b]^c;
	}
	else
	{
		par[ra]=rb;
		sum[rb]+=sum[ra];
		xorarr[ra]=xorarr[a]^xorarr[b]^c;
	}


}
signed main()
{
	for(int i=0;i<3005;i++)
	{
		par[i]=i;
		sum[i]=1;
	}
	int n,m,k,nan=0;
	cin>>n>>m>>k;
	for(int i=0;i<k;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(root(a)!=root(n+b))
		{
			un(a,n+b,c);
			v1[a].push_back(n+b);
			v1[n+b].push_back(a);
		}
		else
		{
			if((xorarr[a]^xorarr[n+b]^c)!=0)
			{
				nan=1;
			}
		}

	}
	if(nan==1)
	{
		cout<<0<<endl;
	}
	else
	{

		int count=0;
		for(int i=1;i<=n+m;i++)
		{
			if(vis[i]==false)
			{
				dfs(i);
				count++;
			}
		}
		int ans=powerof(2,30*(count-1));
		cout<<ans<<endl;
	}
	return 0;
}







