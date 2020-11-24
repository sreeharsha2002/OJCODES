#include<iostream>
using namespace std;
int main()
{
	int n,t,x;
	cin>>n;
	int arr[n];
	bool boo[n];
	cin>>t;
	int minarr,maxarr;
	for(int p=0;p<t;p++)
	{
		for(int i=0;i<n;i++)
			boo[i]=false;
		cin>>x;
		cout<<"READ"<<' '<<0<<endl;
		cin>>minarr;
		arr[0]=minarr;
		boo[0]=true;
		cout<<"READ"<<' '<<n-1<<endl;
		cin>>maxarr;
		arr[n-1]=maxarr;
		boo[n-1]=true;
		if(maxarr==minarr)
		{
			if(x==minarr)
				cout<<"OUTPUT"<<' '<<0<<endl;
			else
				cout<<"OUTPUT"<<' '<<-1<<endl;
		}
		else if(maxarr>minarr)
		{
			int min=0,max=n-1,mid,midarr,f=0,minmid=-1;
			while(min<=max)
			{
				mid=max-((max-min)/2);
				if(boo[mid]==false)
				{
					cout<<"READ"<<' '<<mid<<endl;
					cin>>midarr;
					arr[mid]=midarr;
					boo[mid]=true;
				}
				if(arr[mid]>=x)
				{
					max=mid-1;
				}
				else if(arr[mid]<x)
				{
					min=mid+1;
				}
				if(arr[mid]==x)
				{
					f=1;
					minmid=mid;
				}
			}
			cout<<"OUTPUT"<<' '<<minmid<<endl;
		}
		else
		{ 
			int min=0,max=n-1,mid,midarr,f=0,minmid=-1;
			while(min<=max)
			{
				mid=max-((max-min)/2);
				if(boo[mid]==false)
				{
					cout<<"READ"<<' '<<mid<<endl;
					cin>>midarr;
					arr[mid]=midarr;
					boo[mid]=true;
				}
				if(arr[mid]<=x)
				{
					max=mid-1;
				}
				else if(arr[mid]>x)
				{
					min=mid+1;
				}
				if(arr[mid]==x)
				{
					f=1;
					minmid=mid;
				}
			}
			cout<<"OUTPUT"<<' '<<minmid<<endl;
		}
	}
	return 0;
}






