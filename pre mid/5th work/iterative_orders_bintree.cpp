// binary tree
//pre-,post-,inorder iterative way
#include<iostream>
#include<stack>
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

void preorder(node * n1){
  stack<node*> st;
  if(n1!=NULL)
      st.push(n1);
  else{
    cout<<"No nodes present";
    return;
  }
  node * n;
  while(!st.empty()){
    n=st.top();
    cout<<endl<<n->data<<endl;
    st.pop();
    if((n->rc)!=NULL)
      st.push(n->rc);
    if((n->lc)!=NULL)
      st.push(n->lc);
  }
}
void inorder(node *n1){
  if(n1==NULL){
    cout<<endl<<"No nodes"<<endl;
    return;
  }
  stack<node*> st;
  node *c,* n=n1;
  //st.push(n);
  while(n!=NULL){

    st.push(n);
    while(n->lc!=NULL){
      n=n->lc;
      st.push(n);
      }
    do{
      if(st.empty())
        break;
      n=st.top();
      cout<<endl<<n->data<<endl;
      st.pop();
      n=n->rc;
    }while(n==NULL);
  }
}
void postorder(node * n1){
  stack<node*> s1;
  stack <node*> s2 ;
  node * n=n1;
  s1.push(n1);
  while(!s1.empty()){
    n=s1.top();
    s1.pop();
    s2.push(n);
    n=s2.top();
    if(n->lc!=NULL)
      s1.push(n->lc);
    if(n->rc!=NULL)
      s1.push(n->rc);
  }
  while(!s2.empty()){
    n=s2.top();
    cout<<endl<<n->data<<endl;
    s2.pop();
  }

}
int main(){
  node* root = newNode(1);
  root->lc = newNode(2);
  root->rc = newNode(3);
  root->lc->lc = newNode(4);
  root->rc->lc = newNode(5);
  root->rc->rc = newNode(6);
  root->rc->rc->lc = newNode(7);
  //cout<<endl<<"Inorder"<<endl;
  //inorder(root);
  cout<<endl<<"Postorder"<<endl;
  postorder(root);
  //cout<<endl<<"Preorder"<<endl;
  //preorder(root);
  return 0;
}
