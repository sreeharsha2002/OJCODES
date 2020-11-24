#include<iostream>
#include<deque>
#define lli long long int
using namespace std;
int main()
{
	lli n;
	cin>>n;
	lli a[n];
	for(lli i=0;i<n;i++)
	{
		cin>>a[i];
	}
	deque <lli> dq;
	lli amin1[n],amin2[n];
	for(lli i=0;i<n;i++)
	{
		if(i==0)
		{
			amin1[i]=1;
			dq.push_back(i);
		}
		else
		{
			if(a[dq.back()]>a[i])
			{
				amin1[i]=i-dq.back();
				dq.push_back(i);
			}
			else if(a[dq.back()]<=a[i])
			{
				while(dq.size()!=0 && a[dq.back()]<=a[i])
				{
					dq.pop_back();
				}
				if(dq.size()==0)
				{
					amin1[i]=i+1;
				}
				else
				{
					amin1[i]=i-dq.back();
				}
				dq.push_back(i);
			}
		}
	}
	if(dq.size()!=0)
	dq.clear();
	for(lli i=n-1;i>=0;i--)
	{
		if(i==n-1)
		{
			amin2[i]=1;
			dq.push_back(i);
		}
		else
		{
			if(a[dq.back()]>a[i])
			{
				amin2[i]=dq.back()-i;
				dq.push_back(i);
			}
			else if(a[dq.back()]<=a[i])
			{
				while(dq.size()!=0 && a[dq.back()]<a[i])
				{
					dq.pop_back();
				}
				if(dq.size()==0)
				{
					amin2[i]=n-i;
				}
				else
				{
					amin2[i]=dq.back()-i;
				}
				dq.push_back(i);
			}
		}
	}
	if(dq.size()!=0)
	dq.clear();
	lli amax1[n],amax2[n];
	for(lli i=0;i<n;i++)
	{
		if(i==0)
		{
			amax1[i]=1;
			dq.push_back(i);
		}
		else
		{
			if(a[dq.back()]<a[i])
			{
				amax1[i]=i-dq.back();
                                dq.push_back(i);
                        }
                        else if(a[dq.back()]>=a[i])
                        {
                                while(dq.size()!=0 && a[dq.back()]>=a[i])
                                {
                                        dq.pop_back();
                                }
                                if(dq.size()==0)
                                {
                                        amax1[i]=i+1;
                                }
                                else
                                {
                                        amax1[i]=i-dq.back();
                                }
                                dq.push_back(i);
                        }
                }
        }
	if(dq.size()!=0)
        dq.clear();
       for(lli i=n-1;i>=0;i--)
        {
                if(i==n-1)
                {
                        amax2[i]=1;
                        dq.push_back(i);
                }
                else
                {
                        if(a[dq.back()]<a[i])
                        {
                                amax2[i]=dq.back()-i;
                                dq.push_back(i);
                        }
                        else if(a[dq.back()]>=a[i])
                        {
                                while(dq.size()!=0 && a[dq.back()]>a[i])
                                {
                                        dq.pop_back();
                                }
                                if(dq.size()==0)
                                {
                                        amax2[i]=n-i;
                                }
                                else
                                {
                                        amax2[i]=dq.back()-i;
                                }
                                dq.push_back(i);
                        }
                }
        }
	if(dq.size()!=0)
        dq.clear();
	lli smx=0,smn=0;
/*	for(int i=0;i<n;i++)
	{
		cout<<amin1[i]<<' ';
	}cout<<endl;
	for(int i=0;i<n;i++)
        {
                cout<<amin2[i]<<' ';
        }cout<<endl;
	for(int i=0;i<n;i++)
        {
                cout<<amax1[i]<<' ';
        }cout<<endl;
	for(int i=0;i<n;i++)
        {
                cout<<amax2[i]<<' ';
        }cout<<endl;*/

	for(lli i=0;i<n;i++)
	{
		smx=smx+((((amax1[i])*(amax2[i])))*a[i]);
		smn=smn+((((amin1[i])*(amin2[i])))*a[i]);
	}
	cout<<(smn-smx)<<endl;
	return 0;
}

				



