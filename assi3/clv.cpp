#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<utility>
#include<algorithm>
#define int long long int
using namespace std;
int M=1e17+7;
signed main()
{
	int n,m,d,l;
	cin>>n>>m>>d>>l;
	int a[n+1][m+1][n+1][m+1];
	int dx[]={1,0,-1,0};
	int dy[]={0,1,0,-1};
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=n;k++)
			{
				for(int p=0;p<=m;p++)
				{
					a[i][j][k][p]=M;
					if(((i-k)*(i-k))+((j-p)*(j-p))==1)
					{
						a[i][j][k][p]=1;
					}
					a[i][j][i][j]=0;
				}
			}
		}
	}
	for(int i=0;i<d;i++)
	{
		int u,v1;
		cin>>u>>v1;
		a[u][v1][u][v1]=M+100;
		for(int j=0;j<4;j++)
		{
			if(u+dx[j]<=n && u+dx[j]>=1 && v1+dy[j]<=m && v1+dy[j] >=1){
				a[u][v1][u+dx[j]][v1+dy[j]]=M+100;
				a[u+dx[j]][v1+dy[j]][u][v1]=M+100;}
		}
	}
	pair<int,int> v[l];
	for(int i=0;i<l;i++)
	{
		int x,y;
		cin>>x>>y;
		v[i].first=x;
		v[i].second=y;
	}

	for(int k1=1;k1<=n;k1++)
	{
		for(int k2=1;k2<=m;k2++)
		{
			for(int i1=1;i1<=n;i1++)
			{
				for(int i2=1;i2<=m;i2++)
				{
					for(int j1=1;j1<=n;j1++)
					{
						for(int j2=1;j2<=m;j2++)
						{
							if(a[i1][i2][j1][j2]!=M+100)
								a[i1][i2][j1][j2]=min(a[i1][i2][j1][j2],a[i1][i2][k1][k2]+a[k1][k2][j1][j2]);
						}
					}
				}
			}
		}
	}
	int j=0,min=M,sum=0;
	sort(v,v+l);
	if(l!=0){
		do
		{
			sum=0;
			sum+=a[1][1][v[0].first][v[0].second];
			for(int i=0;i<l-1;i++)
			{
				sum+=a[v[i].first][v[i].second][v[i+1].first][v[i+1].second];
			}
			sum+=a[v[l-1].first][v[l-1].second][n][m];
			if(min>sum)
			{
				min=sum;
			}
			j++;
		}while((next_permutation(v,v+l)));

		/*	for(int i=0;i<l;i++)
			{
			if(min>sum[i])
			{
			min=sum[i];
			}
			}*/
	}
	else if(l==0)
	{
		min=a[1][1][n][m];
	}

	if(min>=M)
	{
		cout<<-1<<endl;
	}
	else
		cout<<min<<endl;
	return 0;
}







