#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

struct node  // structure of node
{
	int data;
	node *left;
	node *right;
};

node *createnode(int value){  // utility node for creating a node with having data and both right and left pointer null.
	node *newnode=new node();
	newnode->data=value;
	newnode->left=newnode->right=NULL;
	return newnode;
}


void inorder_traversal(node *root){  // for inorder traversal
	if(root==NULL){
		return;
	}
	inorder_traversal(root->left);
	cout<<root->data<<" ";
	inorder_traversal(root->right);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	 node *root=createnode(1);
	 root->left=createnode(2);
	 root->right=createnode(3);
	 root->left->left=createnode(4);
	 root->right->right=createnode(5);
	 inorder_traversal(root);

	return 0;
}