#include <bits/stdc++.h>
#define int long long int
using namespace std;
int sum[1005],par[1005],maxa=1;
bool vis[1005];
vector<int>vec[1005];
void dfs(int p)
{
	vis[p]=true;
	for(int i=0;i<vec[p].size();i++)
	{
		if(vis[vec[p][i]]==false)
		{
			dfs(vec[p][i]);
		}
	}

}
bool check(int a,int b)
{
	int c=a&b;
	if(c==b) return true;
	else
		return false;
}
/*bool bin(int a,int b)
  {
  int i=0;
  int ba[15]={0};
  while(a>0)
  {
  ba[i]=a%2;
  a=a/2;
  i++;
  }
  if(ba[b]==1)
  {
  return true;
  }
  else
  return false;
  }*/
int binary(int a)
{
	int i=0;
	int ba[15]={0};
	while(a>0)
	{
		ba[i]=a%2;
		a=a/2;
		i++;
	}
	return i-1;
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
		if(maxa<sum[ra])
			maxa=sum[ra];
	}
	else
	{
		par[ra]=rb;
		sum[rb]+=sum[ra];
		if(maxa<sum[rb])
			maxa=sum[rb];
	}


}
signed main()
{
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=0;i<=n;i++)
	{
		par[i]=i;
		sum[i]=1;
	}
	vector<pair<int,pair<int,pair<int,int>>>>v;
	for(int i=0;i<m;i++)
	{
		int u,v1,p,c;
		cin>>u>>v1>>p>>c;
		v.push_back(make_pair(c,make_pair(p,(make_pair(u,v1)))));
	}
	sort(v.begin(),v.end());
	int x1,y,cost,pt,ans;
	int sumsc[15]={0};
	int k=binary(x),atl=0,min=0;
	bool dfsa[15];
	for(int i=0;i<15;i++)
		dfsa[i]=true;
	for(int j=10;j>=0;j--)
	{
		ans=(1<<15)-1;
		for(int i=0;i<m;i++)
		{
			x1=v[i].second.second.first;
			y=v[i].second.second.second;
			pt=v[i].second.first;
			int als=ans&pt;
			cost=v[i].first;
			min=min+cost;
			/*	if(j>k){
				if(root(x1)!=root(y) && bin(als,j) )
				{
				un(x1,y);
				vec[x1].push_back(y);
				vec[y].push_back(x1);
				ans=als;
				sumsc[j]=sumsc[j]+cost;
				}}
				else
				{*/
			if((atl+(1<<j))>x)
			{
				if(root(x1)!=root(y) && check(pt,atl+(1<<j)))
				{
					un(x1,y);
					vec[x1].push_back(y);
					vec[y].push_back(x1);
					sumsc[j]=sumsc[j]+cost;

				}
			}
			else
			{
				atl=atl+(1<<j);
			}
			//}
		}
		dfs(1);
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==false)
			{
				dfsa[j]=false;
			}
		}


		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			sum[i]=1;
			vis[i]=false;
			vec[i].clear();
		}

	}
	int minc=min;
	for(int i=0;i<=10;i++)
	{
		if(dfsa[i]==true)
		{
			if(sumsc[i]<min)
			{
				min=sumsc[i];
			}
		}
	}
	if(min==minc)
	{
		cout<<-1<<endl;
	}
	else
		cout<<min<<endl;



	return 0;
}




