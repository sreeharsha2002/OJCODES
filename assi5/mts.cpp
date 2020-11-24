#include<iostream>
#include<vector>
#define int long long int 
using namespace std;
bool vis[1000005];
int sub[1000005];
bool cent[1000005];
int mod=1e9+7;
vector<int>v[1000005];
int fact(int p)
{
	int fac=1;
	for(int i=1;i<=p;i++)
	{
		fac=(fac*i)%mod;
	}
	return fac;
}
int powerof(int a,int b)
{
	int r=1;
	while(b>0)
	{
		if(b%2==1)
		{
			r=(r*a)%mod;
		}
		a=(a*a)%mod;
		b=b/2;
	}
	return r;
}
void dfs(int p)
{
	vis[p]=true;
	sub[p]=1;
	for(int i=0;i<v[p].size();i++)
	{
		if(vis[v[p][i]]==false)
		{
			dfs(v[p][i]);
			sub[p]+=sub[v[p][i]];
		}
	}
}
int flag=0;
void centroid(int p,int n)
{
	vis[p]=true;
	bool centro=true;
	int hvc=0;
	for(int i=0;i<v[p].size();i++)
	{
		if(vis[v[p][i]]==false && cent[v[p][i]]==false)
		{
			if(sub[v[p][i]]>n/2)
			{
				centro=false;
			}
			if(hvc==0 || sub[v[p][i]]>sub[hvc])
			{
				hvc=v[p][i];
			}
		}
	}
	if(centro==true && n-sub[p]<=n/2)
	{
		cent[p]=true;
	}
	flag++;
	if(flag==n)
	{
		return;
	}
	centroid(hvc,n);
}
int size=1;
void topsort(int p)
{
	vis[p]=true;
	size=(size*powerof(sub[p],mod-2))%mod;
	for(int i=0;i<v[p].size();i++)
	{
		if(vis[v[p][i]]==false)
		{
			topsort(v[p][i]);
		}
	}
}



signed main()
{
	int t;
	cin>>t;
	for(int l=0;l<t;l++)
	{
		int n;
		cin>>n;
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(1);
		for(int i=0;i<=n;i++)
		{
			vis[i]=false;
		}
		centroid(1,n);
		for(int i=0;i<=n;i++)
		{
			vis[i]=false;
			sub[i]=0;
		}
		int ac=1;
		for(int i=n;i>=1;i--)
		{
			if(cent[i]==true)
			{
				ac=i;
				break;
			}
		}
		dfs(ac);
		for(int i=0;i<=n;i++)
		{
			vis[i]=false;
		}
		topsort(ac);
		int output=(fact(n)*size)%mod;
		cout<<ac<<' '<<output<<' '<<endl;
		for(int i=0;i<=n;i++)
		{
			vis[i]=false;
			sub[i]=0;
			cent[i]=false;
		}
		size=1;
		flag=0;
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
		}
	}
	return 0;
}




