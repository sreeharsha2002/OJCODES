#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> v[100007];
bool vi[100007];
//int maxp=0,minp=100020;
int c[100007];
void dfs(int p)
{
	//int c=0;
	vi[p]=true;
	//cout<<p<<endl;
	for(int i=0;i<v[p].size();i++)
	{
		if(i==0)
		{
			//if(vi[v[p][0]]!=vi[v[p][1]])
				c[p]++;
		}
		else if((v[p][i-1]!=v[p][i]))
			c[p]++;
		if(vi[v[p][i]]==false)
			dfs(v[p][i]);
	/*	if(c>maxp)
		{
			maxp=c;
			minp=p;
		}
		else if(c==maxp)
		{
			if(p<minp)
				minp=p;
		}*/
	}
}



int main()
{
	int n,e;
	cin>>n>>e;
	int a[n+1];
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<e;i++)
	{
		int c,b;
		cin>>c>>b;
		if(a[c]!=a[b]){
		v[a[c]].push_back(a[b]);
		v[a[b]].push_back(a[c]);}
	}
	for(int i=0;i<100007;i++)
	{
		sort(v[i].begin(),v[i].end());
	}
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		cout<<v[i][j]<<' ';
		cout<<endl;
	}cout<<endl;*/
	for(int i=1;i<=n;i++)
	{
		if(vi[a[i]]!=true)
	               dfs(a[i]);
	}
	for(int i=1;i<100007;i++)
	{
		if(vi[i]!=true)
			c[i]=-1;
	}
	int mx=0,mn=100020;
	for(int i=1;i<100007;i++)
	{
		if(mx<c[i])
		{
			mx=c[i];
			mn=i;
		}
		else if(mx==c[i])
		{
			if(mn>i)
			{
				mn=i;
			}
		}
	}
	/*for(int i=1;i<=4;i++)
	{
		cout<<c[i]<<' ';
	}
	cout<<endl;*/
	cout<<mn<<endl;
	return 0;

}
