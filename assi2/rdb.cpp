#include<iostream>
#include<vector>
#include<deque>
#define int long long int
using namespace std;
typedef struct cost
{
	int nxt;
	int cst;
}cost;
vector<cost>v[100005];
int a[100005];
int vi[100005];
void dfs(int p,int pr,int df)
{
	vi[p]=df;
	for(int i=0;i<v[p].size();i++)
	{
		if((vi[v[p][i].nxt]==0)&&(v[p][i].cst<=pr))
		{
			dfs(v[p][i].nxt,pr,df);
		}
	}
}



signed main()
{
	int n,e,td,p=0;
	cin>>n>>e;
	int max=0;
	for(int i=0;i<e;i++)
	{
		cost prr;
		int a1,b,c;
		cin>>a1>>b>>c;
		if(max<c)
		{
			max=c;
		}
		prr.cst=c;
		prr.nxt=b;
		v[a1].push_back(prr);
		prr.nxt=a1;
		v[b].push_back(prr);
	}
	cin>>td;
	int j;
	int min=0,mid,sumn=0,sums=0;
	while(min<=max)
	{
		for(int i=0;i<=n;i++)
		{
			vi[i]=0;
			a[i]=0;
		}
		j=0,sums=0,sumn=0;
		mid=min+(max-min)/2;
		for(int i=1;i<=n;i++)
		{
			if(vi[i]==0)
				dfs(i,mid,i);
		}
		for(int i=1;i<=n;i++)
		{
			a[vi[i]]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0)
			{
				sums=sums+(a[i]*a[i]);
				sumn=sumn+a[i];
			}
		}
		j=((sumn*sumn)-sums)/2;
		if(j>=td)
		{
			min=mid+1;
		}
		else if(j<td)
		{
			max=mid-1;
			p=mid;
		}
	}
	cout<<p<<endl;
	return 0;
}




