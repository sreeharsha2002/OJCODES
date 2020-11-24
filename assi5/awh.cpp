#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define int long long int
using namespace std;
vector<int>v[100005];//temp[100005];
stack<int>st[100005];
vector<int>minv;
int n;
int costf(int p,int x)
{
	int mincst=0;
	for(int i=0;i<n;i++)
	{
		while( v[i].size()!=0 && v[i].size()>=p)
		{
			x++;
			mincst+=v[i][v[i].size()-1];
			st[i].push(v[i][v[i].size()-1]);
			v[i].pop_back();
		}
	}
	if(x>p)
	{
		for(int i=0;i<n;i++)
		{
			while(st[i].size()!=0)
			{
				v[i].push_back(st[i].top());
				st[i].pop();
			}
		}
		return -1;
	}
	if(x<p)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				minv.push_back(v[i][j]);
			}
		}
		sort(minv.rbegin(),minv.rend());
		while(minv.size()!=0 && x<p)
		{
			x++;
			mincst+=minv.back();
			minv.pop_back();
		}
		minv.clear();
		for(int i=0;i<n;i++)
		{
			while(st[i].size()!=0)
			{
				v[i].push_back(st[i].top());
				st[i].pop();
			}
		}
	}
	return mincst;
}
int tsearch(int mn,int max,int x)
{
	max=1e6+5;
	int mid1,mid2;
	while(max-mn>=3)
	{
		mid1=(2*mn+max)/3;
		mid2=(2*max+mn)/3;
		if(costf(mid1,x)==-1 && costf(mid2,x)==-1)
		{
			mn=mid2;
		}
		else if(costf(mid1,x)==-1 && costf(mid2,x)!=-1)
		{
			mn=mid1;
		}
		else if(costf(mid1,x)>costf(mid2,x))
		{
			mn=mid1;
		}
		else if(costf(mid1,x)<=costf(mid2,x))
		{
			max=mid2;
		}
	}
	int ans=1e15;
	while(mn<=max)
	{
		if(costf(mn,x)!=-1)
		{
			if(ans>costf(mn,x))
			{
				ans=costf(mn,x);
			}
		}
		mn++;
	}
	return ans;

}
signed main()
{
	int x;
	cin>>x>>n;
	int max=0;
	int nfa;
	for(int i=0;i<n;i++)
	{
		cin>>nfa;
		if(nfa>max)
			max=nfa;
		for(int j=0;j<nfa;j++)
		{
			int cst;
			cin>>cst;
			v[i].push_back(cst);
		}
	}
	for(int i=0;i<n;i++)
	{
		sort(v[i].rbegin(),v[i].rend());
	}
	cout<<tsearch(0,max,x)<<endl;
}

