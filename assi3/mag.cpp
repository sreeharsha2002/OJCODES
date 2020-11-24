#include<iostream>
#include<queue>
using namespace std;
#define int long long int
#define ff first 
#define ss second 
signed main()
{
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        int n,e,k;
        cin>>n>>e>>k;
	int a1[n]={0};
        vector <pair<int,int>> v[n+1];
        for (int i=0;i<e;i++)
        {
                int a,b,c;
                cin>>a>>b>>c;
                v[a].push_back(make_pair(b,c));
                v[b].push_back(make_pair(a,c));
        }
	for(int i=0;i<k;i++)
	{
		int x;
		cin>>x;
		a1[x]=1;
		pq.push(make_pair(0,x));
	}
	int pp=0;
        while(pq.size()!=0)
        {
                int a=pq.top().ff;
                int par=pq.top().ss;
                pq.pop();
                if (a1[par]!=2)
                {
			if(a1[par]==0){
                        a1[par]=1;
			continue;}
			a1[par]=2;
                        for(int i=0;i<v[par].size();i++)
                        {
                                int cost=v[par][i].ss;
                                int cp=v[par][i].ff;
                                if(a1[cp]!=2)
                                {
                                        pq.push(make_pair(a+cost,cp));
                                }

                        }
                }
		if(a1[par]==2 && par==0)
		{
			pp=1;
			cout<<a<<endl;
			break;
		}

        }
	if(pp==0)
	{
		cout<<-1<<endl;
	}
        return 0;
}

