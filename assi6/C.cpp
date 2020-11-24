#include<iostream>
#define int long long int 
using namespace std;
int mod=1e9+7;
int prime[1048574];
int powerof(int a,int b)
{
	int r=1;
	while(b>0)
	{
		if(b%2==1)
		{
			r=(r*a)%mod;
		}
		a=(a*a)%mod;
		b=b/2;
	}
	return r;
}
void makeprime()
{
	for(int p=2; p*p<=1048573; p++)
	{
		if(prime[p]==0)
		{
			for(int i=p*p;i<=1048573;i+=p)
			{
				prime[i]=1;
			}
		}
	}
	int i=0;
	for(int p=2;p<=1048573;p++)
	{
		if(prime[p]==0)
		{
			prime[p]=i;
			i++;
		}
	}
}
int inverse(int a,int b,int *x,int *y)
{
	if(a==0)
	{
		*x=0;
		*y=1;
		return *x;
	}
	int x1,y1;
	inverse(b%a,a,&x1,&y1);
	*x=y1-(b/a)*x1;
	*y=x1;
	return ((*x)%b +b)%b;
}

int phi(int n) 
{
	int result = n;
	for(int i=2;i*i <= n;i++) 
	{
		if (n % i == 0) 
			result -= result / i;
		while (n % i == 0)
			n /= i;
	}
	if (n > 1) 
		result -= result / n;
	return result;
}


signed main()
{
	int q,height,T0;
	cin>>q;
	makeprime();
	int oldS,T,U,V,S,Pi,D,r,x,y,pow;
	for(int k=0;k<q;k++)
	{
		cin>>height>>T0;
		oldS=T0;
		r=1;
		pow=1<<(height-1);
		for(int kl=0;kl<height;kl++)
		{
			cout<<"DARE"<<' '<<r<<endl;
			cin>>S>>Pi>>D;
			T=(powerof(oldS,mod-2)*S)%mod;
			oldS=S;
			U=(powerof(prime[Pi],mod-2) * T)%mod;
			V=inverse(U,D,&x,&y);
			cout<<T<<' '<<U<<' '<<V<<endl;
			if(V==1)
			{
				cout<<"TRUTH"<<' '<<phi(r)<<endl;
				break;
			}
			else if( V>=2 && V<= pow)
			{
				r = 2*r;
			}
			else
			{
				r=2*r + 1;
			}
		}
	}
	return 0;
}
