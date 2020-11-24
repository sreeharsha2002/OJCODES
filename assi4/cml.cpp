#include<bits/stdc++.h>
#define int long long int
using namespace std;
int sum[2000005],par[2000005],xorarr[2000005],mod=1e9+7;
vector<int>va,vb;
vector<pair<int,pair<int,int>>>vec;
map<int,int>mapa,mapb;

int poer(int a,int b, int c)
{
	int r=1;
	a=a%c;
	while(b>0)
	{
		if((b&1)==1)
		{
			r=(r*a)%c;
		}
	
	a=(a*a)%c;
	b=b>>1;
	}
	return r;
}

int root(int i)
{
	if(par[i]==i)
	{
		return i;
	}
	int rr=par[i];
	par[i]=root(par[i]);
	xorarr[i]=xorarr[i]^xorarr[rr];
	return par[i];
}

int un(int a,int b,int c)
{
	int ra=root(a);
	int rb=root(b);
	if(sum[ra]>sum[rb])
	{
		par[rb]=ra;
		sum[ra]+=sum[rb];
		xorarr[rb]=((xorarr[a]^xorarr[b])^c);
	}
	else
	{
		par[ra]=rb;
		sum[rb]+=sum[ra];
		xorarr[ra]=((xorarr[a]^xorarr[b])^c);
	}


}
signed main()
{
	int n,m,k,x,cn,ans=1,ians;
	cin>>n>>m>>k>>x;
	cn=n+m;
	for(int i=1;i<=2000005;i++)
	{
		par[i]=i;
		sum[i]=1;
	}
	for(int i=0;i<k;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		vec.push_back(make_pair(c,make_pair(a,b)));
		va.push_back(a);
		vb.push_back(b);
	}
	sort(va.begin(),va.end());
	sort(vb.begin(),vb.end());
	int kan=1;
	for(int i=0;i<va.size();i++)
	{
		if(i==0)
		{
			mapa.insert(pair<int,int>(va[i],kan));
		//	mapa[va[i]]=kan;
			kan++;
		}
		else if(va[i]!=va[i-1])
		{
			mapa.insert(pair<int,int>(va[i],kan));
		//	mapa[va[i]]=kan;
			kan++;
		}
	}
	kan=va.size()+1;
	for(int i=0;i<vb.size();i++)
	{
		if(i==0)
		{
			mapb.insert(pair<int,int>(vb[i],kan));
		//	mapb[vb[i]]=kan;
			kan++;
		}
		else if(vb[i]!=vb[i-1])
		{
			mapb.insert(pair<int,int>(vb[i],kan));
			//mapb[vb[i]]=kan;
			kan++;
		}
	}
	int nan=0;
	for(int i=0;i<k;i++)
	{
		int a,b,c;
		a=mapa[vec[i].second.first];
		b=mapb[vec[i].second.second];
		c=vec[i].first;
		if(root(a)!=root(b))
		{
			un(a,b,c);
			cn--;
		}
		else
		{
			if(((xorarr[a]^xorarr[b])^c)!=0)
			{
				nan=1;
			}
		}
		if(nan==0)
		{
			ians=poer(1073741824,cn-1,1e9+6);
//			cout<<"ians"<<ians<<"cnn"<<cn<<endl;
			ans=(ans*poer(x,ians,1e9+7))%mod;
		}
		else
		{
			cout<<ans<<endl;
			return 0;
		}
	}
//	cout<<poer(1073741824,4,1e9+6)<<endl;
	cout<<ans<<endl;
	return 0;
}


