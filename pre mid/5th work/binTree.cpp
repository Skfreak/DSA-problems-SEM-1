//simple binary tree
#include<iostream>
using namespace std;

struct node{
  int data;
  node* lc;
  node *rc;
};

node* newNode(int val){
  node* Node = new node();
  Node->data=val;
  Node->lc=NULL;
  Node->rc=NULL;
  return Node;
}
void preorder(node * node){
  if(node!=NULL){
    cout<<endl<<node->data<<endl;
    preorder(node->lc);
    preorder(node->rc);
  }
}
void inorder(node * node){
  if(node!=NULL){
    inorder(node->lc);
    cout<<endl<<node->data<<endl;
    inorder(node->rc);
  }
}
void postorder(node * node){
  if(node!=NULL){
    postorder(node->lc);
    postorder(node->rc);
    cout<<endl<<node->data<<endl;
  }
}
int main(){
  node* root = newNode(1);
  root->lc = newNode(2);
  root->rc = newNode(3);
  root->lc->lc = newNode(4);
  root->rc->lc = newNode(5);
  root->rc->rc = newNode(6);

  cout<<endl<<"Inorder"<<endl;
  inorder(root);
  cout<<endl<<"Postorder"<<endl;
  postorder(root);
  cout<<endl<<"Preorder"<<endl;
  preorder(root);
  return 0;
}
