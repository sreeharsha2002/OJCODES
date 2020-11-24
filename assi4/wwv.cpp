#include<bits/stdc++.h>
#define int long long int
using namespace std;
int sum[200005],par[200005];
vector<pair<int,pair<int,int>>>vec;
vector<pair<int,pair<int,int>>>vec1;
vector<pair<int,pair<int,pair<int,int>>>>vec2;
vector<pair<int,pair<int,pair<int,int>>>>vec4;
vector<int>v[100005];
bool vis[100005];
void dfs(int p)
{
	vis[p]=true;
	for(int i=0;i<v[p].size();i++)
	{
		if(vis[v[p][i]]==false)
		{
			dfs(v[p][i]);
		}
	}
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
	int n,m,k,num=0,sumsc=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		sum[i]=1;
	}
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1 || b==1)
		{
			vec1.push_back(make_pair(c,make_pair(a,b)));
		}
		vec.push_back(make_pair(c,make_pair(a,b)));
	}
	if(vec1.size()<k)
	{
		cout<<-1<<endl;
	}
	else
	{
		int a1,b1,c1,mids=0;
		int min=-1e13,max=1e13,mid;
		while(min+1<max)
		{
			num=0;
			sumsc=0;
			if(vec2.size()!=0)
			{
				vec2.clear();
			}
			mid=min+(max-min)/2;
			for(int i=0;i<m;i++)
			{
				a1=vec[i].second.first;
				b1=vec[i].second.second;
				c1=vec[i].first;
				if(a1==1 || b1==1)
				{
					vec2.push_back(make_pair(c1+mid,make_pair(c1,make_pair(a1,b1))));
				}
				else
				{
					vec2.push_back(make_pair(c1,make_pair(c1,make_pair(a1,b1))));
				}
			}
			sort(vec2.begin(),vec2.end());
			for(int i=0;i<m;i++)
			{
				a1=vec2[i].second.second.first;
				b1=vec2[i].second.second.second;
				c1=vec2[i].second.first;
				if(root(a1)!=root(b1))
				{
					un(a1,b1);
					if(a1==1 || b1==1)
					{
						num++;
					}
					v[a1].push_back(b1);
					v[b1].push_back(a1);
					sumsc+=c1;
				}
			}
		//	cout<<min<<' '<<mid<<' '<<max<<endl;
			if(num>k)
			{
				min=mid;
				mids=mid;
			}
			else if(num==k)
			{
				break;
			}
			else
			{
				max=mid;
			}
			for(int i=1;i<=n;i++)
			{
				par[i]=i;
				sum[i]=1;
				v[i].clear();
			}
		}
		if(num==k)
		{
			dfs(1);
			bool dfsb=true;
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==false)
				{
					dfsb=false;
				}
			}
			if(dfsb==false)
				cout<<-1<<endl;
			else
				cout<<sumsc<<endl;
		}
		else
		{
			int a1,b1,c1;
			for(int i=0;i<m;i++)
			{
				a1=vec2[i].second.second.first;
				b1=vec2[i].second.second.second;
				c1=vec2[i].second.first;
				if(a1==1 || b1==1)
				{
					vec4.push_back(make_pair(c1+mids,make_pair(c1,make_pair(a1,b1))));
				}
				else
					vec4.push_back(make_pair(c1,make_pair(c1,make_pair(a1,b1))));

			}
			sort(vec4.begin(),vec4.end());
			sumsc=0;
			for(int i=1;i<=n;i++)
			{
				par[i]=i;
				sum[i]=1;
				v[i].clear();
				vis[i]=false;
			}
			num=0;
			for(int i=0;i<m;i++)
			{
				a1=vec4[i].second.second.first;
				b1=vec4[i].second.second.second;
				c1=vec4[i].second.first;
				if(root(a1)!=root(b1) &&(num+(a1==1 || b1==1)<=k))
				{
					un(a1,b1);
					sumsc+=c1;

					v[a1].push_back(b1);
					v[b1].push_back(a1);
					if(a1==1 || b1==1)
					{
						num++;
					}
				}
			}
			dfs(1);
			bool dfsa=true;
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==false)
					dfsa=false;
			}
			if(dfsa==false)
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<sumsc<<endl;
			}

		}
	}
	return 0;
}	



