#include<iostream>
#include<vector>
#define int long long int
using namespace std;
int bgt[100005];
bool vi[100005];
int a0[100005];
int a1[100005];
int sum[100005];
int b0=0,b1=0;
int m=1e9+7;
typedef struct node
{
	int nxt;
	int cst;
}node;
vector <node> v[100005];

void dfs(int p,int c)
{
	vi[p]=true;
	if(bgt[p]==0)
		a0[p]=1;
	else if(bgt[p]==1)
		a1[p]=1;

//	cout<<a0[p]<<0<<endl;
//	cout<<a1[p]<<endl;
	for(int i=0;i<v[p].size();i++)
	{
		if(vi[v[p][i].nxt]==false)
		{

			dfs(v[p][i].nxt,v[p][i].cst);
		//	cout<<a0[v[p][i].nxt]<<11<<endl;
			a0[p]=(a0[p]+a0[v[p][i].nxt]);
			a1[p]=(a1[p]+a1[v[p][i].nxt]);
		}
	}
		sum[p]=(((b0*a0[p])+(b1*a1[p])-(a0[p]*a0[p])-(a1[p]*a1[p]))*c)%m;

}



signed main()
{
	int n,sum1=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>bgt[i];
		if(bgt[i]==0)
		{
			b0++;
		}
		else if(bgt[i]==1)
		{
			b1++;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		node p;
		p.nxt=b;
		p.cst=c;
		v[a].push_back(p);
		p.nxt=a;
		v[b].push_back(p);
	}
	dfs(0,0);
	/*for(int i=0;i<n;i++)
	cout<<a1[i]<<' ';
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a0[i]<<' ';
	}cout<<endl;
	cout<<sum<<endl;*/
	for(int i=0;i<n;i++)
	{
		sum1=(sum1+sum[i])%m;
	}
	cout<<sum1<<endl;
	return 0;
}


