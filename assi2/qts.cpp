#include<iostream>
#include<deque>
#define lli long long int
using namespace std;
int main()
{
	deque <lli> def;
	deque <lli> deb;
	lli q,x,a1,i=0,fs,bs,y=0;
	char c;
	cin>>q;
	while(i<q)
	{
		cin>>c;
		if(c=='a')
		{
			cin>>x;
			if(y==0)
			{
				deb.push_back(x);
				fs=def.size();
                		bs=deb.size();
                		a1=fs+bs;
				if(fs!=a1/2)
				{
					def.push_back(deb.front());
					deb.pop_front();
				}
			}
			else if(y==1)
			{
				def.push_back(x);
				fs=def.size();
                		bs=deb.size();
                		a1=fs+bs;
				if(bs!=a1/2)
				{
					deb.push_back(def.front());
					def.pop_front();
				}
			}
			i++;
		}
		else if(c=='t')
		{
			if(y==0)
			{
				deb.pop_back();
				fs=def.size();
                		bs=deb.size();
                		a1=fs+bs;
				if(fs!=a1/2)
				{
					deb.push_front(def.back());
					def.pop_back();
				}
			}
			else if(y==1)
			{
				def.pop_back();
				fs=def.size();
              	 		bs=deb.size();
               			a1=fs+bs;
				if(bs!=a1/2)
				{
					def.push_front(deb.back());
					deb.pop_back();
				}
			}
			i++;
		}
		else if(c=='e')
		{
			y=!y;
			if(y==0)
			{
				fs=def.size();
                                bs=deb.size();
                                a1=fs+bs;
                                if(fs!=a1/2)
                                {
                                        deb.push_front(def.back());
                                        def.pop_back();
                                }
			}
			else if(y==1)
			{
				fs=def.size();
                                bs=deb.size();
                                a1=fs+bs;
                                if(bs!=a1/2)
                                {
                                        def.push_front(deb.back());
                                        deb.pop_back();
                                }
			}
			i++;
		}
	/*	
	 	for(int j=0;j<def.size();j++)
			cout<<def[j]<<' ';
		cout<<endl;
		for(int j=0;j<deb.size();j++)
			cout<<deb[j]<<' ';
			*/


	}

	fs=def.size();
        bs=deb.size();
        a1=fs+bs;
	cout<<a1<<endl;
	if(a1!=0){
	if(y==0)
	{
		for(lli i=0;i<fs;i++)
		{
			cout<<def[i]<<' ';
		}
		for(lli i=0;i<bs-1;i++)
		{
			cout<<deb[i]<<' ';
		}
		cout<<deb[bs-1]<<endl;
	}
	else
	{
		for(lli i=0;i<bs;i++)
		{
			cout<<deb[i]<<' ';
		}
		for(lli i=0;i<fs-1;i++)
		{
			cout<<def[i]<<' ';
		}
		cout<<def[fs-1]<<endl;
	}}
	else
		cout<<'\n';
	return 0;
}
	





