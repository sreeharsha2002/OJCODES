#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int>v[100005];
deque<int>dq;
bool vi[100005];
int vis[100005];
void dfs(int p)
{
	vi[p]=true;
	dq.push_back(p);
	if(vi[v[p][0]]==false)
		dfs(v[p][0]);
	else
	{
		if(vis[v[p][0]]!=0)
		{
			vis[p]=vis[v[p][0]];
			dq.pop_back();
			while(dq.size()!=0)
			{
				vis[dq.back()]=vis[p];
				dq.pop_back();
			}

		}
		else{

		while(dq.back()!=v[p][0])
		{
			vis[dq.back()]=dq.back();
			dq.pop_back();
		}
		vis[v[p][0]]=v[p][0];
		dq.pop_back();
		while(dq.size()!=0)
		{
			vis[dq.back()]=v[p][0];
			dq.pop_back();
		}
		}
	}



}

int main()
{
	int t,n;
	cin>>t;
	for(int p=0;p<t;p++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
			vi[i]=false;
		}
		for(int i=1;i<=n;i++)
		{
			int b;	
			cin>>b;
			v[i].push_back(b);
		}
		for(int i=1;i<=n;i++)
		{
			if(vi[i]==false){
				dfs(i);
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<vis[i]<<' ';
		}cout<<endl;
		for(int i=1;i<=n;i++)
		{
			v[i].clear();
		}
	}
	return 0;
}




