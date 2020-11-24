#include<iostream>
#include<vector>
#include<algorithm>
#define int long long int
using namespace std;
int vis[100005];
vector<int>vec[100005];
vector<int>top;
bool flag;
void dfs(int p)
{
	vis[p]=1;
	for(int i=0;i<vec[p].size();i++)
	{
		if(vis[vec[p][i]]==1)
			flag=true;
		if(vis[vec[p][i]]==0)
			dfs(vec[p][i]);

	}
	vis[p]=2;
	top.push_back(p);
}

signed main()
{
	int n,k;
	cin>>n>>k;
	vector<int> v[n];
	for(int i=0;i<n;i++)
	{
		int l,x;
		cin>>l;
		for(int j=0;j<l;j++)
		{
			cin>>x;
			v[i].push_back(x);
		}
	}
	vector<int>vec1;
	for(int i=0;i<n-1;i++)
	{
		int j=0;
		/*if(j<v[i+1].size() || v[i].size()<v[i+1].size())
		  {
		  if(v[i][j]!=v[i+1][j])
		  {
		  vec[v[i][j]].push_back(v[i+1][j]);
		  vec1.push_back(v[i][j]);
		  vec1.push_back(v[i+1][j]);
		  }
		  else
		  {
		  j++;
		  i--;
		  }
		  }
		  else
		  flag=true;*/
		while(v[i][j]==v[i+1][j] && j<v[i+1].size() && j<v[i].size() )
		{
			j++;
		}
		//cout<<i<<' '<<v[i].size()<<' '<<v[i+1].size()<<endl;
		if(v[i].size()>v[i+1].size() && j>=v[i+1].size())
		{
			//cout<<"flag"<<endl;
			flag=true;
		}
		else if(v[i][j]!=v[i+1][j])
		{
			vec[v[i][j]].push_back(v[i+1][j]);
			vec1.push_back(v[i][j]);
			vec1.push_back(v[i+1][j]);
		}



	}
	while(vec1.size()!=0)
	{
		sort(vec[vec1.back()].begin(),vec[vec1.back()].end(),greater<int>());
		vec1.pop_back();
	}
	for(int i=k;i>=1;i--)
	{
		if(vis[i]==0)
			dfs(i);
	}
	if(flag==false)
	{
		while(top.size()!=0)
		{
			if(top.size()!=1)
				cout<<top.back()<<' ';
			else
				cout<<top.back()<<endl;
			top.pop_back();
		}
	}
	else
		cout<<-1<<endl;
	return 0;
}








