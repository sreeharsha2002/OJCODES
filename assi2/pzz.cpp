#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#define int long long int
using namespace std;
typedef struct cost
{
	int nxt;
	int cst;
}cost;
typedef struct range
{
	int lb;
	int ub;
	int pt;
}range;
vector<cost> v[100005];
int a[100005];
range s[100005];
vector<range>vr;
deque<cost>dq[100005];
deque<range>dqr[100005];
bool vi[100005];
int m=1e9+7; 
bool sorts(cost &a1,cost &a2)
{
	if(a1.cst>a2.cst) return 0;
	else if(a1.cst<a2.cst) return 1;
	else
	{
		if(a1.nxt>a2.nxt) return 0;
		else  return 1;
	}
}
bool sortq(range &a1, range &a2)
{
	if(a1.lb>a2.lb) return 0;
	else return 1;
}
void dfs(int p,int temp,int tepe)
{
	vi[p]=true;
	cost tep;
	for(int i=0;i<v[p].size();i++)
	{
		if(vi[v[p][i].nxt]==false)
		{
			dq[p].push_back(v[p][i]);
		}

	}
	if(dq[p].size()!=0 && dq[p].front().cst<=temp){
	while(dq[p].size()!=0 && dq[p].front().cst<=temp)
	{
		tep=dq[p].front();
		dq[p].pop_front();
	}
	dq[p].push_front(tep);
	}
	while(dq[p].size()!=0)
	{
		range pa;
		if(dq[p].size()!=1){
		if(dq[p].front().cst<=temp)
		{
			pa.pt=dq[p].front().nxt;
			pa.lb=temp+1;
			pa.ub=dq[p][1].cst;
			dqr[p].push_back(pa);
		}
		else
		{
			pa.pt=dq[p].front().nxt;
			pa.lb=dq[p].front().cst+1;
			pa.ub=dq[p][1].cst;
			dqr[p].push_back(pa);
		}
		}
		else
		{
		if(dq[p].front().cst<=temp)
                {
                        pa.pt=dq[p].front().nxt;
                        pa.lb=temp+1;
                        pa.ub=m;
                        dqr[p].push_back(pa);
                }
                else
                {
                        pa.pt=dq[p].front().nxt;
                        pa.lb=dq[p].front().cst+1;
                        pa.ub=m;
                        dqr[p].push_back(pa);
                }
		}


		if(dqr[p].back().ub > tepe)
		{
			dqr[p].back().ub=tepe;
		}
	
		s[p].ub=dqr[p].front().lb-1;
	        s[dqr[p].back().pt].pt=dqr[p].back().pt;
		s[dqr[p].back().pt].lb=dqr[p].back().lb;
		s[dqr[p].back().pt].ub=dqr[p].back().ub;
		if(vi[dq[p].front().nxt]==false){
		int  temp1=dq[p].front().nxt;
		int temp2=dqr[p].back().lb;
		int temp3=dqr[p].back().ub;
		dq[p].pop_front();
		dfs(temp1,temp2-1,temp3);
		}
	}
}
                   
signed main()
{
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n-1;i++)
	{
		cost p;
		int a3,b,c;
		cin>>a3>>b>>c;
		p.nxt=b;
		p.cst=c;
		v[a3].push_back(p);
		p.nxt=a3;
		v[b].push_back(p);
	}
	for(int i=1;i<=n;i++)
	{
		sort(v[i].begin(),v[i].end(),sorts);
		vi[i]=false;
	}
	s[1].pt=1;
	s[1].lb=0;
	s[1].ub=m;;
	dfs(1,0,m);
/*	for(int i=1;i<=n;i++)
        {
                cout<<i<<' '<<"parent"<<'{'<<endl;
                cout<<s[i].pt<<' '<<s[i].lb<<' '<<s[i].ub<<endl;
                cout<<'}'<<endl;
        }*/

	for(int i=0;i<q;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i].ub>=s[i].lb && vi[i]==true)
		{
			vr.push_back(s[i]);
		}
	}
	sort(vr.begin(),vr.end(),sortq);
	for(int i=0;i<vr.size();i++)
        {
                cout<<vr[i].pt<<' '<<vr[i].lb<<' '<<vr[i].ub<<endl;
        }
	int sum=0;
	int an;
	for(int i=0;i<q;i++)
	{
		an=0;
		int min=0,max=vr.size()-1,mid;
		while(min<=max)
		{
			mid=min+(max-min)/2;
			if(vr[mid].lb<=a[i])
			{
				min=mid+1;
				an=mid;
			}
			else{
				max=mid-1;
			}
		}
		sum=sum+vr[an].pt;
	}
	cout<<sum<<endl;
	return 0;
}
