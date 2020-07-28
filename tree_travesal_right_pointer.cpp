#include "bits/stdc++.h"
using namespace std;

#define ll long long 
//Amazone interview problem SDE
class Node
{
  public:
  int data; 
  Node* left;
  Node* right;
  
  Node(int d)
  {
    data = d;
    left= nullptr;
    right= nullptr;
  }
};
Node* modify(Node* root )
{
    Node* r = root->right;
    Node* rmost = root;

    if(root->left)
    {
       rmost = modify(root->left);
       root->right= root->left;
       root->left = nullptr;
    }
    if(!r)
    return rmost;

    rmost->right = r;
    rmost = modify(r);
    return rmost;

}

void preOrder(Node* root )
{
  if(root==nullptr) return ;
  cout<<root->data<<" ";
  preOrder(root->right);
}

int main()
{
	 Node* root = new Node(10);
   root->left = new Node(8);
   root->right = new Node(2);
   root->left->left = new Node(3);
   root->left->right = new Node(5);
   modify(root);
   preOrder(root);
   return 0;
}
