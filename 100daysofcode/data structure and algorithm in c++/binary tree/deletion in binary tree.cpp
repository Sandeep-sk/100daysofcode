#include "bits/stdc++.h"
using namespace std;

struct node{
    int data;
    node *left,*right;
};
node *createnode(int data){
    node *newnode=new node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
}
void inorder_traversal(node *root){
    if(root==NULL){
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data;
    inorder_traversal(root->right);
}
void delete_deepestnode(node *root,node *lastnode){
    if(root==NULL)return;
    queue<node *>q;
    q.push(root);
    node *temp=new node();
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp==lastnode){
            temp=NULL;
            delete(lastnode);
            return;
        }
        if(temp->left){
            if(temp->left==lastnode){
                temp->left=NULL;
                delete(lastnode);
                return;
            }
            else{
            	q.push(temp->left);
            }
        }
        if(temp->right){
            if(temp->right==lastnode){
                temp->right=NULL;
                delete(lastnode);
                return;
            }
            else{
            	q.push(temp->right);
            }
        }
    }
}

node *delete_node_in_binary_tree(node *root,int key){
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL){
        if(root->data==key)
            return NULL;
        else
            return root;
    }
    node *temp=new node();
    node *holder=NULL;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp->data==key){
            holder=temp;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    if(holder !=NULL){
        int x=temp->data;
        holder->data=x;
        delete_deepestnode(root,temp);
        return root;
    }
}



int main(){
    node *root=createnode(1);
    root->left=createnode(2);
    root->right=createnode(3);
    root->left->left=createnode(4);
    root->left->right=createnode(5);
    root->right->left=createnode(6);
    root->right->right=createnode(7);
    cout<<"before deletion in binary tree inorder traversal"<<"\n";
    cout<<"\n";
    inorder_traversal(root);
    cout<<"\n";
    cout<<"after deletion inorder traversal"<<"\n";
    root=delete_node_in_binary_tree(root,3);
    inorder_traversal(root);
    return 0;
}