#include<bits/stdc++.h>
#define int long  long int
using namespace std;
int M=1e17+7;
int d1[1005],d2[1005],d3[1005],d4[1005],ans[1005];
vector<int>v[1005];
signed main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	cin>>t;
	for(int p=0;p<t;p++)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;

			v[i].push_back(a);
			v[i].push_back(b);
			v[i].push_back(c);
		}
		for(int i=0;i<n-1;i++)
		{
			int j=0;
			while(v[j].size()!=0)
			{
				d1[v[j][0]]=min(d1[v[j][0]],d1[v[j][1]]+v[j][2]);
				d2[v[j][1]]=min(d2[v[j][1]],d2[v[j][0]]+v[j][2]);
				j++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			d3[i]=d1[i];
			d4[i]=d2[i];
		}
		for(int i=0;i<max(n,m);i++)
		{
			int j=0;
			while(v[j].size()!=0)
			{

				d3[v[j][0]]=min(d3[v[j][0]],d3[v[j][1]]+v[j][2]);
				d4[v[j][1]]=min(d4[v[j][1]],d4[v[j][0]]+v[j][2]);
				if(d3[v[j][0]]!=d1[v[j][0]])
				{
					d3[v[j][0]]=-M;
				}
				if(d4[v[j][1]]!=d2[v[j][1]])
				{
					d4[v[j][1]]=-M;
				}
				j++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if((d1[i]+d2[i])!=(d3[i]+d4[i]))
			{
				ans[i]=M;
			}
			else
				ans[i]=d1[i]+d2[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(ans[i]==M)
			{
				cout<<"INF"<<endl;
			}
			else
				cout<<ans[i]<<endl;
		}
		for(int i=0;i<m;i++)
		{
			while(v[i].size()!=0)
				v[i].pop_back();
		}
		for(int i=0;i<=n;i++) d1[i]=0,d2[i]=0,d3[i]=0,d4[i]=0,ans[i]=0;
	}
	return 0;
}



