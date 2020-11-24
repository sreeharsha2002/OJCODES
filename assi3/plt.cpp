#include<bits/stdc++.h>
#define int long long int
using namespace std;
int par[307],sum[307];
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else gcd(b,a%b);
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
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int m,k;
	cin>>m>>k;
	for(int i=0;i<m;i++)
        {
                par[i]=i;
                sum[i]=1;
        }
	vector<int>v[m];
	vector<int>v1[m];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<k;j++)
		{
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	}
/*	for(int i=0;i<m;i++)
	{
		cout<<i<<'_';
		for(int j=0;j<k;j++)
		{
			cout<<v[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int i=0;i<m;i++)
	{
		sort(v[i].begin(),v[i].end(),greater<int>());
	}
/*	cout<<"sort"<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<i<<'_';
		for(int j=0;j<k;j++)
		{
			cout<<v[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int i=0;i<m;i++)
	{
		v1[i].push_back(v[i][0]);
		for(int j=1;j<k;j++)
		{
			int kd=gcd(v1[i].back(),v[i][j]);
			if(kd!=v1[i].back())
			{
				v1[i].push_back(kd);
			}
		}
	}
/*	cout<<"gcd"<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<i<<'_';
		for(int j=0;j<v1[i].size();j++)
		{
			cout<<v1[i][j]<<' ';
		}
		cout<<endl;
	}*/
	vector<pair<int,pair<int,int>>>gr;
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			int min=1e9+7;
			//if(i!=j)
			{
	//			cout<<i<<endl;
				for(int p=0;p<v1[i].size();p++)
				{
					for(int q=0;q<v1[j].size();q++)
					{
						if(min>(v1[i][p]^v1[j][q]))
						{
							min=v1[i][p]^v1[j][q];
						}
					}
				}

				gr.push_back(make_pair(min,make_pair(i,j)));
			}
		}
	}
	sort(gr.begin(),gr.end());
	int minc=0;
        for(int i=0;i<(m*(m-1))/2;i++)
        {
                int x=gr[i].second.first;
                int y=gr[i].second.second;
                int cst=gr[i].first;
	//	cout<<x<<' '<<y<<' '<<cst<<endl;
                if(root(x)!=root(y))
                {
                        minc+=cst;
                        un(x,y);
                }
        }
        cout<<minc<<endl;
	return 0;
}





