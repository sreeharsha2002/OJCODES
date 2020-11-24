#include<iostream>
#include<vector>
using namespace std;
bool boo[10][10][10][10];
vector<int>v;
int cnt[5][5];
vector<pair<int,int>>maxpair;
void reset()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				for(int l=0;l<10;l++)
				{
					boo[i][j][k][l]=true;
					if(i==j || j==k || k==l || i==k || i==l ||j==l)
					{
						boo[i][j][k][l]=false;
					}
				}
			}
		}
	}
}
int givec(string s,int i, int j,int k,int l)
{
	int count=0;
	if(s[0]==(i+'0'))
		count++;
	if(s[1]==(j+'0'))
		count++;
	if(s[2]==(k+'0'))
		count++;
	if(s[3]==(l+'0'))
		count++;
	return count;
}

int gived(string s,int i,int j,int k,int l)
{
	int count=0;
	for(int p=0;p<4;p++)
	{
		if(s[p]==(i+'0') || s[p]==(j+'0') || s[p]==(k+'0') || s[p]==(l+'0'))
		{
			count++;
		}
	}
	return (4-count);
}

int num(int i,int j,int k,int l)
{
	int a=(i*1000) + (j*100) + (k*10) + (l);
	return a;
}
void checkvalid( string cha,int c, int d)
{
	if(v.size()!=0)
		v.clear();

	int newc,newd;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				for(int l=0;l<10;l++)
				{
					if(boo[i][j][k][l]==true)
					{
						newc=givec(cha,i,j,k,l);
						newd=gived(cha,i,j,k,l);
						if(newc!=c || newd!=d)
							boo[i][j][k][l]=false;
						else
							v.push_back(num(i,j,k,l));
					}
				}
			}
		}
	}

}
void resetcnt()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cnt[i][j]=0;
		}
	}
}
int givecguess(string s1,string s2)
{
	int count=0;
	if(s1[0]==s2[0])
		count++;
	if(s1[1]==s2[1])
		count++;
	if(s1[2]==s2[2])
		count++;
	if(s1[3]==s2[3])
		count++;
	return count;
}

int givedguess(string s1,string s2)
{
	int count=0;
	for(int p=0;p<4;p++)
	{
		if(s1[p]==s2[0] || s1[p]==s2[1] || s1[p]==s2[2] || s1[p]==s2[3])
		{
			count++;
		}
	}
	return 4-count;
}

string stringoutput(int a)
{
	string str="0000";
	for(int i=3;i>=0;i--)
	{
		str[i]=(a%10)+'0';
		a=a/10;
	}
	return str;
}
int guess()
{
	int max=0;
	int c,d;
	if(maxpair.size()!=0)
		maxpair.clear();
	if(v.size()!=0)
	{
		for(int i=0;i<v.size();i++)
		{
			max=0;
			resetcnt();
			for(int j=0;j<v.size();j++)
			{
				c=givecguess(stringoutput(v[i]) , stringoutput(v[j]));
				d=givedguess(stringoutput(v[i]) , stringoutput(v[j]));
				d=4-(c+d);
				cnt[c][d]++;
				if(max<cnt[c][d])
				{
					max=cnt[c][d];
				}
			}
			if(maxpair.size()==0)
			{
				maxpair.push_back(make_pair(v[i],max));
			}
			else
			{
				if(max<=maxpair.back().second)
				{
					maxpair.back().first=v[i];
					maxpair.back().second=max;
				}
			}
		}
	}
	return maxpair.back().first;
}	
int main()
{
	reset();
	int q;
	cin>>q;
	int c,d,ans,f;
	string cha;
	while(q--)
	{
		reset();
		f=0;
		cout<<"TIK"<<' '<<1234<<endl;
		cin>>c>>d;
		if(c==4 && d==0)
		{
			f=1;
			ans=1234;	
		}
		else
		{
			cha="1234";
			checkvalid(cha,c,d);
		}
		if(f==0)
		{
			cout<<"TIK"<<' '<<9873<<endl;
			cin>>c>>d;
			if(c==4 && d==0)
			{
				f=1;
				ans=9873;
			}
			else
			{
				cha="9873";
				checkvalid(cha,c,d);
			}
		}
		if(f==1)
		{
			cout<<"TOK"<<' '<<ans<<endl;
		}
		else
		{
			int g;
			while(true)
			{
				g=guess();
				cout<<"TIK"<<' '<<g<<endl;
				cin>>c>>d;
				if(c==4 && d==0)
				{
					cout<<"TOK"<<' '<<g<<endl;
					break;
				}
				cha=stringoutput(g);
				checkvalid(cha,c,d);
			}
		}

	}
	return 0;
}


