#include<iostream>
using namespace std;
int arr[100005];
int mod=1e9+7;
typedef struct node
{
	node *child[2];
	int nl;
	int enw;
}node;
node *init()
{
	node *p=new node;
	p->nl=0;
	p->enw=0;
	for(int i=0;i<2;i++)
	{
		p->child[i]=NULL;
	}
	return p;
}
long long int powerof(long long int a,long long int b)
{
	long long int r=1;
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
int findenw(node *head,int str,int lv,int what)
{
	node*root=head;
	int ind;
	while(lv>=0)
	{
		ind=(str>>lv)&1;
		if(root->child[ind]==NULL)
		{
			return 0;
		}
		root=root->child[ind];
		lv--;
	}
	/*	if (what==1)
		{
		int a=root->enw;
		root->enw++;
		return a;
		}
		if(what==2)
		{
		int a=root->enw;
		root->enw--;
		return a;
		}*/
	return root->enw;
}
void insertnode(node *head,int str,int lv)
{
	node *root=head;
	node *root1=head;
	int lv1=lv;
	int isenw=findenw(root,str,lv,1);
	int ind;
	if(isenw>0)
	{
		while(lv1>=0)
		{
			ind=(str>>lv1)&1;
			root1=root1->child[ind];
			lv1--;
		}
		root1->enw++;
	}
	else
	{
		while(lv>=0)
		{
			ind=(str>>lv)&1;
			if(root->child[ind]==NULL)
			{
				root->child[ind]=init();
			}
			root->nl++;
			root=root->child[ind];
			lv--;
		}
		root->nl++;
		root->enw++;
	}
}
int  findmin(node *head,int str,int lv)
{
	node*root=head;
	int ind,mn=0;
	while(lv>=0)
	{
		if(root==NULL)
		{
			return mn;
		}
		else
		{
			ind=(str>>lv)&1;
			if(root->child[ind]!=NULL && root->child[ind]->nl==1<<lv)
			{
				ind=1-ind;
				mn=mn|(1<<lv);
			}
			root=root->child[ind];
		}
		lv--;
	}
	return mn;
}
node *deletenode(node *head,int str,int lv)
{
	node *root=head;
	if(lv<0)
	{
		root->enw--;
		root->nl=0;
		return NULL;
	}
	int ind=(str>>lv)&1;
	root->child[ind]=deletenode(root->child[ind],str,lv-1);
	root->nl--;
	if(root->child[ind]==NULL && root->child[1-ind]==NULL)
	{
		free(root);
		return NULL;
	}
	return root;
}
void  enwdeletenode(node *head,int str,int lv)
{
	node *root=head;
	node *root1=head;
	int lv1=lv;
	int isenw=findenw(head,str,lv,2);
	int ind;
	if(isenw>1)
	{
		while(lv1>=0)
		{
			ind=(str>>lv1)&1;
			root1=root1->child[ind];
			lv1--;
		}
		root1->enw--;
	}
	else
	{
		deletenode(head,str,lv);
	}
}
int main()
{
	int n,q;
	cin>>n>>q;
	node *head=init();
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		insertnode(head,arr[i],30);
	}
	int prxor=0;
	long long int acmin=1;
	int type,x,y,z;
	for(int i=0;i<q;i++)
	{
		cin>>type;
		if(type==1)
		{
			cin>>x;
			prxor=prxor^x;
			acmin=(acmin*powerof(1e8,findmin(head,prxor,30)))%mod;
		}
		if(type==2)
		{
			cin>>z>>y;
			enwdeletenode(head,arr[z-1],30);
			arr[z-1]=prxor^y;
			insertnode(head,arr[z-1],30);
			acmin=(acmin*powerof(1e8,findmin(head,prxor,30)))%mod;
		}
	}
	//long long int output=powerof(10,8*acmin);
	cout<<acmin<<endl;
}






