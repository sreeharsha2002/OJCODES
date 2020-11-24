#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef struct node
{
	struct node *cha[26];
	bool enw;
}node;

node *init(void)
{
	node *p= new node;
	p->enw=false;
	for(int i=0;i<26;i++)
	{
		p->cha[i]=NULL;
	}
	return p;
}

void insert(node *head , string str)
{
	node *root=head;
	for(int i=0;i<str.length();i++)
	{
		int ind=str[i]-'a';
		if(root->cha[ind]==NULL)
		{
			root->cha[ind]=init();
		}
		root=root->cha[ind];
	}
	root->enw=true;
}

int  search(node *head , string str,int l)
{
	int k=0;
	node *root=head;
	for(int i=l;i<str.length();i++)
	{
		int ind=str[i]-'a';
		if(root->cha[ind]==NULL)
		{
			return l+k-1;
		}
		root=root->cha[ind];
		k++;
	}
	return l+k-1;
}
pair<int,int> secondtop( stack<pair<int,int>>& sta)
{
	pair<int,int>p,q;
	p=sta.top();
	sta.pop();
	q=sta.top();
	sta.push(p);
	return q;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string name;
	int q;
	cin>>name;
	cin>>q;
	string word[q];
	node *head=init();
	for(int i=0;i<q;i++)
	{
		cin>>word[i];
		insert(head,word[i]);
	}
	bool flag=false;
	stack<pair<int,int>>st;
	int h=0;
	for(int i=0;i<name.length();i++)
	{
		int q2=search(head,name,h);
		if(h==0 && q2==-1)
		{
			flag=true;
		}
		else if(q2!=-1 && h==0)
		{
			if(st.size()==0)
			{
				st.push(make_pair(h,q2));
				h++;
			}
		}
		else if(q2>h-1)
		{
			if(st.top().second+1>=h && st.top().second<q2)
			{

				while(st.size()!=1 && (secondtop(st).second+1>=h && st.top().second<q2))
				{
					st.pop();
				}
				st.push(make_pair(h,q2));


			}
			/*else if(st.top().second+1>=h && st.top().second<q2)
			{
				st.push(make_pair(h,q2));
			}*/
			else if(st.top().second+1<h)
				flag=true;
			h++;
		}
		else if(q2<=h-1)
		{
			h++;
		}
	}
	if(st.size()!=0 && st.top().second!=name.length()-1)
	{
		flag=true;
	}
	if(flag==true)
	{
		cout<<-1<<endl;
	}
	else
		cout<<st.size()<<endl;
	//cout<<search(head,name,2)<<endl;
	return 0;
}



