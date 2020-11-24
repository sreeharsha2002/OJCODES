#include<iostream>
#include<queue>
using namespace std;
#define int long long int
#define ff first 
#define ss second 
signed main()
{
	ios_base::sync_with_stdio(false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq2;
        int n,e;
        cin>>n>>e;
        vector <pair<int,int>> v[n+1];
        for (int i=0;i<e;i++)
        {
                int a,b,c;
                cin>>a>>b>>c;
                v[a].push_back(make_pair(b,c));
                v[b].push_back(make_pair(a,c));
        }
	int s,t,A,B;
	cin>>s>>t>>A>>B;
        pq1.push(make_pair(0,s));
        pq2.push(make_pair(0,t));
        int leva[n+1],levb[n+1];
        bool vis[n+1];
        for(int i=0;i<=n;i++) leva[i]=1e9+7,vis[i]=false;
        while(pq1.size()!=0)
        {
                int a=pq1.top().ff;
                int par=pq1.top().ss;
                pq1.pop();
                if (vis[par]==false)
                {
                        vis[par]=true;
                        leva[par]=a;
                        for(int i=0;i<v[par].size();i++)
                        {
                                int cost=v[par][i].ss;
                                int cp=v[par][i].ff;
                                if(vis[cp]==false && cost<=A)
                                {
                                        pq1.push(make_pair(leva[par]+cost,cp));
                                }
                        }
                }
        }
        for(int i=0;i<=n;i++) levb[i]=1e9+7,vis[i]=false;
	 while(pq2.size()!=0)
        {
                int a=pq2.top().ff;
                int par=pq2.top().ss;
                pq2.pop();
                if (vis[par]==false)
                {
                        vis[par]=true;
                        levb[par]=a;
                        for(int i=0;i<v[par].size();i++)
                        {
                                int cost=v[par][i].ss;
                                int cp=v[par][i].ff;
                                if(vis[cp]==false && cost>=B)
                                {
                                        pq2.push(make_pair(levb[par]+cost,cp));
                                }
                        }
                }
        }
	int min=1e9+7;
       for(int i=1;i<=n;i++)
       {
	      if(min>leva[i]+levb[i])
	      {
		      min=leva[i]+levb[i];
	      }
       }
       if(min==1e9+7)
       {
	       cout<<-1<<endl;
       }
       else
	       cout<<min<<endl;
	return 0;
}




