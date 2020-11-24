#include<iostream>
#include<algorithm>
#define int long long int
using namespace std;
int mod=1e9+7;
int acp;
typedef struct node
{
	node *lft;
	node *rgt;
	int val;
	int hgt;
	int subt;
	int cnt;
	int hash;
}node;
node *init(int value)
{
	node *p=new node;
	p->lft=NULL;
	p->rgt=NULL;
	p->val=value;
	p->hgt=1;
	p->subt=1;
	p->cnt=1;
	p->hash=(value *acp)%mod;
	return p;
}
int hgt(node *root)
{
	if(root==NULL)
		return 0;
	return root->hgt;
}
int powerof(int a,int b)
{
	int r=1;
	a=a%mod;
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
int hashvalue(node *root)
{
	if(root==NULL)
		return 0;
	return root->hash;
}
int subsize(node *root)
{
	if(root==NULL)
		return 0;
	return root->subt;
}
int hashnode(node *root)
{
	int hash=0;
	if(root==NULL)
	{
		return hash;
	}
	int pnod=powerof(acp,root->cnt + subsize(root->lft));
	hash=((root->cnt * root->val))%mod;
	hash=(hash * pnod)%mod;
	if(root->lft!=NULL)
		hash=(hash + hashvalue(root->lft))%mod;
	if(root->rgt!=NULL)
		hash=(hash + (hashvalue(root->rgt) * pnod)%mod)%mod;
	return hash;
}

node *rgtrotate(node *root)
{
	node *a=root->lft;
	node *b=a->rgt;
	a->rgt=root;
	root->lft=b;
	root->subt=root->subt - a->subt + subsize(b);
	a->subt=a->subt - subsize(b) + root->subt;
	root->hash=hashnode(root);
	a->hash=hashnode(a);
	root->hgt=max(hgt(root->lft),hgt(root->rgt))+1;
	a->hgt=max(hgt(a->lft),hgt(a->rgt))+1;
	return a;
}
node *lftrotate(node * root)
{
	node *a=root->rgt;
	node *b=a->lft;
	a->lft=root;
	root->rgt=b;
	root->subt=root->subt - a->subt + subsize(b);
	a->subt=a->subt - subsize(b) + root->subt;
	root->hash=hashnode(root);
	a->hash=hashnode(a);
	root->hgt=max(hgt(root->lft),hgt(root->rgt))+1;
	a->hgt=max(hgt(a->lft),hgt(a->rgt))+1;
	return a;
}
int checkbal(node *root)
{
	if(root==NULL)
		return 0;
	return hgt(root->lft)-hgt(root->rgt);
}
node *insertnode(node* root, int value)
{
	if(root==NULL)
	{
		return(init(value));
	}
	if(value < root->val)
	{
		root->lft=insertnode(root->lft,value);
	}
	else if(value > root->val)
	{
		root->rgt=insertnode(root->rgt,value);
	}
	else if(value == root->val)
	{
		root->cnt++;
	}
	root->subt++;
	root->hash=hashnode(root);
	root->hgt=max(hgt(root->lft),hgt(root->rgt))+1;
	int bal=checkbal(root);
	if(bal>1 && value < root->lft->val)
		return rgtrotate(root);
	if(bal<-1 && value > root->rgt->val)
		return lftrotate(root);
	if(bal>1 && value > root->lft->val)
	{
		root->lft=lftrotate(root->lft);
		return rgtrotate(root);
	}
	if(bal<-1 && value < root->rgt->val)
	{
		root->rgt=rgtrotate(root->rgt);
		return lftrotate(root);
	}
	return root;
}

node *after(node *head)
{
	node *root=head;
	while(root->lft!=NULL)
	{
		root=root->lft;
	}
	return root;
}
int searchnode(node *head,int value)
{
	node *root=head;
	while(root!=NULL && value!=root->val)
	{
		if(value<root->val)
		{
			root=root->lft;
		}
		else if(value>root->val)
		{
			root=root->rgt;
		}
	}
	if(root==NULL)
	{
		return 0;
	}
	if(value==root->val)
	{
		int a=root->cnt;
		return a;
	}
}


node * deletenode(node *root,int value,int minct)
{
	if(root==NULL)
	{
		return root;
	}
	if(value < root->val)
	{
		root->lft=deletenode(root->lft,value,minct);
		root->subt-=minct;
	}
	else if(value > root->val)
	{
		root->rgt=deletenode(root->rgt,value,minct);
		root->subt-=minct;
	}
	else
	{
		if(root->cnt==1)
		{
			if(root->lft==NULL || root->rgt==NULL)
			{

				if(root->lft==NULL && root->rgt==NULL)
				{
					root=NULL;
				}
				else
				{
					if(root->rgt!=NULL)
					{
						node *temp=root->rgt;
						*root=*temp;
						free (temp);
					}
					else if(root->lft!=NULL)
					{
						node *temp=root->lft;
						*root=*temp;
						free(temp);
					}
				}
			}
			else
			{
				node * minval=after(root->rgt);
				root->val=minval->val;
				root->cnt=minval->cnt;
				minval->cnt=1;
				root->rgt=deletenode(root->rgt,minval->val,root->cnt);
				root->subt-=minct;
			}
		}
		else if(root->cnt>1)
		{

			root->cnt--;
			root->subt--;
		}
	}
	if(root==NULL)
	{
		return root;
	}
	root->hash=hashnode(root);
	root->hgt=max(hgt(root->lft),hgt(root->rgt))+1;
	int bal=checkbal(root);
	if(bal>1 && checkbal(root->lft)>=0)
	{
		return rgtrotate(root);
	}
	if(bal>1 && checkbal(root->lft)<0)
	{
		root->lft=lftrotate(root->lft);
		return rgtrotate(root);
	}
	if(bal<-1 && checkbal(root->rgt)<=0)
	{
		return lftrotate(root);
	}
	if(bal<-1 && checkbal(root->rgt)>0)
	{
		root->rgt=rgtrotate(root->rgt);
		return lftrotate(root);
	}
	return root;
}
/*void inorder(node *root)
{
        if(root!=NULL)
        {
                inorder(root->lft);
                cout<<"value :"<<root->val<<endl;
                cout<<"multiplicity :"<<root->cnt<<endl;
                cout<<"subtree : "<<root->subt<<endl;
                cout<<"height :"<<root->hgt<<endl;
                cout<<"hash : "<<root->hash<<endl<<endl;
                inorder(root->rgt);
        }
}*/
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->lft);
		cout<<"value"<<' '<<root->val<<' '<<"subtree"<<' '<<root->subt<<' '<<"hash"<<' '<<root->hash<<endl;
		//cout<<root->hash<<endl;
		inorder(root->rgt);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,X;
	cin>>q>>acp>>X;
	char type;
	int num,count,totalhash=1;
	node * head=NULL;
	for(int i=0;i<q;i++)
	{
		cin>>type;
		if(type=='A')
		{
			cin>>num;
			head=insertnode(head,num);
		//	inorder(head);
		}
		else if(type=='D')
		{
			cin>>num;
			if(searchnode(head,num)>0)
				head=deletenode(head,num,1);
		//	inorder(head);
		}
		else if(type=='H')
		{
			totalhash=(totalhash * powerof(X,hashvalue(head)))%mod;
		//	inorder(head);
		}
	}
	cout<<totalhash<<endl;
}



