#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};
node *buildTree()
{
	int d;
	cin >> d;
	if(d==-1)
	{
		return NULL;
	}
	node *root =new node(d);
	//cout << "Enter left data of "<<d<< " "<<endl;
	root->left=buildTree();
	//cout << "Enter right data of "<<d<< " "<<endl;
	root->right=buildTree();
	return  root;

}
void print(node *root) // PreOrder
{
	if (root==NULL)
	{
		return;
	}
	cout << root->data<<" ";
	print(root->left);
	print(root->right);
}
void printIN(node *root) // InOrder
{
	if (root==NULL)
	{
		return;
	}
	printIN(root->left);
	cout << root->data<<" ";
	printIN(root->right);
}

void printPost(node *root) // PostOrder
{
	if (root==NULL)
	{
		return;
	}
	printPost(root->left);
	printPost(root->right);
	cout << root->data<<" ";
}
int height(node *root)
{
	if (root==NULL)
	{
		/* code */
		return 0;
	}
	int x=height(root->left);
	int y=height(root->right);
	return max(x,y)+1;
}

void printKthlevel(node *root,int k)
{
	if (root==NULL)
	{
		return;
	}
	if (k==0)
	{
		cout << root->data<<" ";
		return;
	}
	printKthlevel(root->left,k-1);
	printKthlevel(root->right,k-1);
	return;
}
void printalllevel(node *root)
{
	int h=height(root);

	for (int i = 1; i <=h; ++i)
	{
		printKthlevel(root,i);
		cout << endl;
	}
	return;
}
void bfs(node *root) // Breadth first search for level order traversal O(n)
{
	queue<node *> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node *f=q.front();
		if(f==NULL)
		{
			cout << endl;
			q.pop();
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout << f->data <<" , ";
			q.pop();
			if (f->left!=NULL)
			{
				q.push(f->left);
			}
			if (f->right!=NULL)
			{
				q.push(f->right);
			}
		}

	}
	return;
}
int count(node *root)
{
	if (root==NULL)
	{
		return 0;
	}
	return count(root->left) +count(root->right)+1;
}

int sum(node *root)
{
	if (root==NULL)
	{
		return 0;
	}
	return (root->data +sum(root->left)+sum(root->right));
}


node *deleteNode(node *root, int key) 
{
    // your code goes here
    if(root==NULL)
	{
		return NULL;
	}
	else if(key<root->data)
	{
		root->left=deleteNode(root->left,key);
		return root;
	}
	else if(root->data==key)
	{
		// Found the node to delete 3 cases 
		// Case 1 : Node with 0 children - leaf node
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			return NULL;
		}
		// Case 2 : Only 1 child
		if(root->left!=NULL && root->right==NULL)
		{
			node *temp=root->left;
			delete root;
			return temp;
		}
		if(root->left==NULL && root->right!=NULL)
		{
			node *temp=root->right;
			delete root;
			return temp;
		}
		//*** Case 3 : Node with 2 children 
		if (root->left!=NULL && root->right!=NULL)
		{
			// find the inorder successor from right subtree
			node *replace=root->right;
			while(replace->left!=NULL)
			{
				replace=replace->left;
			}
			root->data=replace->data;
			root->right=deleteNode(root->right,replace->data);
			return root; 
		}
	}
	else
	{
		root->right=deleteNode(root->right,key);
		return root;
	}
	return root;
}


int diameter(node *root)
{
	if (root==NULL)
	{
		return 0;
	}
	int h1=height(root->left);
	int h2=height(root->right);
	int op1=h1+h2;
	int op2=diameter(root->left);
	int op3=diameter(root->right);
	return max(op1,max(op2,op3));
}

class Pair
{
	public:
		int height;
		int diameter;
};

Pair fastdiameter(node *root)
{
	Pair p;
	if (root==NULL)
	{
		p.diameter=p.height=0;
		return p;
	} 

	Pair left=fastdiameter(root->left);
	Pair right=fastdiameter(root->right);

	p.height=max(left.height,right.height)+1;
	p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
	return p;
}

int replacesum(node *root)
{
	if (root==NULL)
	{
		return 0;
	}

	if (root->left==NULL && root->right==NULL) // this for if leaf no do not change
	{

		return root->data;

	}

	int temp=root->data;
	root->data = replacesum(root->left) + replacesum(root->right);
	
	return temp+root->data;
}

class HBPair
{
	public:
		int height;
		bool balance;
	
};


HBPair  isHeightBalance(node *root)
{
	HBPair p;
	if (root==NULL)
	{
		p.height=0;
		p.balance=true;
		return p;
	}

	//Recursively
	HBPair left=isHeightBalance(root->left);
	HBPair right=isHeightBalance(root->right);

	p.height=max(left.height,right.height)+1;

	if (abs(left.height -right.height)<=1 && left.balance && right.balance)
	{
		p.balance=true;
	}
	else
	{
		p.balance=false;
	}
	return p;

}

node *bulidTreefromArray(int *a,int s,int e)
{
	if(s>e)
	{
		return NULL;
	}
	int mid=(s+e)/2;
	node *root=new node(a[mid]);
	root->left=bulidTreefromArray(a,s,mid-1);
	root->right=bulidTreefromArray(a,mid+1,e);
	return root;
}

static int idx=-1;
node * buildTreefrompreorder(int preorder[])
{
	idx++;
	if(preorder[idx]==-1)
	{
		return NULL;
	}
	node* root=new node(preorder[idx]);
	root->left=buildTreefrompreorder(preorder);
	root->right= buildTreefrompreorder(preorder);
	return root;
}


void printRightview(node *root,int level,int &maxlevel)
{
	if(root==NULL)
	{
		return; 
	}
	if (maxlevel<level)
	{
		cout << root->data<<" ";
		maxlevel=level; 
	}
	printRightview(root->right,level+1,maxlevel);
	printRightview(root->left,level+1,maxlevel);
}

void printLeftview(node *root,int level,int &maxlevel)
{
	if(root==NULL)
	{
		return;
	}
	if (maxlevel<level)
	{
		cout << root->data<<" ";
		maxlevel=level; 
	}
	printLeftview(root->left,level+1,maxlevel);
	printLeftview(root->right,level+1,maxlevel);

}

void PrintTopView(node *root)
{
	map<int,int> m;
	queue<pair<node*,int>> q;
	if (root==NULL)
	{
		return;
	}
	q.push({root,0});
	while(!q.empty())
	{
		node *t=q.front().first;
		int h=q.front().second;
		q.pop();
		if(!m[h])
		{
			m[h]=t->data;
		}
		if(t->left)
		{
			q.push({t->left,h-1});
		}
		if(t->right)
		{
			q.push({t->right,h+1});
		}
	}
	for(auto x:m)
	{
		cout << x.second<<" ";
	}
	cout << endl;
}


void PrintBottomView(node *root)
{
	map<int,int> m;
	queue<pair<node*,int>> q;
	if (root==NULL)
	{
		return;
	}
	q.push({root,0});
	while(!q.empty())
	{
		node *t=q.front().first;
		int h=q.front().second;
		q.pop();
		m[h]=t->data;
		if(t->left)
		{
			q.push({t->left,h-1});
		}
		if(t->right)
		{
			q.push({t->right,h+1});
		}
	}
	for(auto x:m)
	{
		cout << x.second<<" ";
	}
	cout << endl;
}


int printAtDistanceK(node *root,int target1,int k)
{
	if(root==NULL)
	{
		return -1;
	}

	// reach the target node
	if(root->data==target1)
	{
		printKthlevel(root,k);
		return 0;
	}

	//next step - Ancestor
	int dl=printAtDistanceK(root->left,target1,k);
	if(dl!=-1) // that means target node is present in left subtree
	{
		// Again there are 2 cases
		//Ancestor itself or you need to go the right ancestor
		if(dl+1==k)
		{
			cout << root->data<<" ";
		}
		else
		{
			printKthlevel(root->right,k-2-dl);
		}
		return 1+dl;
	}
	int dr=printAtDistanceK(root->right,target1,k);
	if(dr!=-1) // that means target node is present in right subtree
	{
		if(dl+1==k)
		{
			cout << root->data<<" ";
		}
		else
		{
			printKthlevel(root->left,k-2-dr);
		}
		return 1+dr;
	}
	// node was not present in left and right subtree
	return -1;
}

// Assumption both a and b are present in the tree ,all keys are unique
node *lca(node *root,int a,int b) // lowest common Ancestor
{
	if (root==NULL)
	{
		return NULL;
	}

	if (root->data==a or root->data==b)
	{
		return root;
	}
	node *leftans=lca(root->left,a,b);
	node *rightans=lca(root->right,a,b);

	if (leftans!=NULL && rightans!=NULL)
	{
		return root;
	}

	if (leftans!=NULL)
	{
		return leftans;
	}
	return rightans;
}
int maxsum(node *root,int &res)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=maxsum(root->left,res);
        int r=maxsum(root->right,res);
        int max_single=max(max(l,r)+root->data,root->data);
        int max_top= max(max_single,l+r+root->data);
        res=max(res,max_top);
        return max_single;
        
    }


int search(node *root,int key,int level)
{
	if (root==NULL)
	{
		return -1;
	}

	if (root->data==key)
	{
		return level;
	}

	int left=search(root->left,key,level+1);
	if (left!=-1)
	{
		return left;
	}
	return search(root->right,key,level+1);
}

//Function to find distance b/w 2 nodes

int findDistance(node *root,int a,int b)
{
	node *lca_node=lca(root,a,b);
	int l1=search(lca_node,a,0);
	int l2=search(lca_node,b,0);
	return l1+l2;
}
int main()
{
	//cout << "Enter -1 for NULL: "<<endl;
	//node *root=buildTree();
	// cout << "Height of Tree : "<< height(root)<<endl;

	// print(root);

	//printKthlevel(root,2);
	//cout << endl;
	// printalllevel(root); // Time Complexity: O(n^2) in worst case. Space Complexity: O(n)

   // bfs(root); // Time Complexity: O(n) in worst case. Space Complexity: O(n)

	// cout << count(root)<<endl;

	// cout << sum(root);
	
	// cout << diameter(root);
	
	// Pair p=fastdiameter(root);
	// cout << p.height<<endl;
	// cout << p.diameter<<endl;

	//bfs(root);
	//cout <<endl;
	// replacesum(root);
	// bfs(root);

	// if (isHeightBalance(root).balance)
	// {
	// 	cout <<"Balanced"<<endl;
	// }
	// else
	// {
	// 	cout << "Not a Balanced Tree"<<endl;
	// }
	// return 0;
	// int a[]={1,2,3,4,5,6,7,8};
	// int n=8;
	// node *root=bulidTreefromArray(a,0,n-1);
	// bfs(root);
	int a[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
	node *root=buildTreefrompreorder(a);
	bfs(root);
	// int maxlevel=-1,maxlevel1=-1;
	// printRightview(root,0,maxlevel);
	// cout <<endl;
	// printLeftview(root,0,maxlevel1);



	node *target=root->left->left;
	int target1=5;
	// int k;
	// cin >> k;
	//printAtDistanceK(root,target1,3);

	
	// cout << "Lca of 4 and 7 is = "<< lca(root,4,7)->data<<endl;
	// cout << "Lca of 6 and 9 is = "<< lca(root,6,9)->data<<endl;

	// int res=INT_MIN;
	// maxsum(root,res);
 //    cout <<  res<<endl;
	// cout << endl;
	// int res=findDistance(root,6,9);
	// cout << res<<endl;
	// cout << findDistance(root,4,7)<<endl;
	cout << endl;
	//PrintTopView(root);

}
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
// 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1