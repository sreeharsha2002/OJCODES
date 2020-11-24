#include<iostream>
using namespace std;
int main()
{
	int a,n,f;
	string b1,b2,b3;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>n;
		f=0;
		cout<<"READ"<<' '<<0<<endl;
		cin>>b1;
		cout<<"READ"<<' '<<1<<endl;
		cin>>b2;
		cout<<"READ"<<' '<<2<<endl;
		cin>>b3;
		if(b1!=b2 && b2==b3)
		{
			cout<<"OUTPUT"<<' '<<0<<endl;
			f=1;
		}
		else if(b1!=b2 && b2!=b3)
		{
			cout<<"OUTPUT"<<' '<<1<<endl;
			f=1;
		}
		else if(b1==b2 && b2!=b3)
		{
			cout<<"OUTPUT"<<' '<<2<<endl;
			f=1;
		}
		if(f==0)
		{
			for(int j=3;j<n;j++)
			{
				cout<<"READ"<<' '<<j<<endl;
				cin>>b1;
				if(b1!=b3)
				{
					cout<<"OUTPUT"<<' '<<j<<endl;
					break;
				}
			}
		}

	}
}
