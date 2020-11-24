#include<iostream>
#include<vector>
#include<algorithm>
#define int long long int
using namespace std;
int sum[200005],arr[200005], par[200005],maxa=1;
vector<pair<int,pair<int,int>> >v;
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
		if(maxa<sum[ra])
			maxa=sum[ra];
        }
        else
        {
                par[ra]=rb;
                sum[rb]+=sum[ra];
		if(maxa<sum[rb])
			maxa=sum[rb];
        }


}
signed main()
{
        int n,e,suma=0;
        cin>>n>>e;
        for(int i=1;i<=n;i++)
        {
                par[i]=i;
                sum[i]=1;
        }
	if(e==0 && n!=0)
	{
		suma=1;
	}
        for(int i=0;i<e;i++)
        {
                int a,b;
		cin>>a>>b;
		if(root(a)!=root(b))
		{
			un(a,b);
		}

		suma+=maxa;

        }
	cout<<suma<<endl;
        return 0;

}

