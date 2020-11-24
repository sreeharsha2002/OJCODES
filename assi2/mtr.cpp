#include<iostream>
#include<deque>
#define int long long int
using namespace std;
signed main()
{
	int n;
	cin >>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin >>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	deque<int>dq;
	int an=0;
	for(int i=0;i<n;i++)
	{
			if(dq.size()!=0)
			{
				while(dq.size()!=0 && dq.front()>a[i])
				{
					dq.pop_front();
				}
				while(dq.size()!=0 && b[i]>dq.back())
				{
					dq.pop_back();
				}
				if(a[i]!=b[i])
				{

				if( dq.size()!=0 && b[i]<dq.back())
				{
					dq.push_back(b[i]);
					an++;
				}
				if(dq.size()==0)
				{
					dq.push_back(b[i]);
					an++;
				}

				}
			}
			else
			{
				if(a[i]!=b[i])
				{
				dq.push_back(b[i]);
				an++;
				}
			}		
	}
	cout<<an<<endl;
	return 0;
}






