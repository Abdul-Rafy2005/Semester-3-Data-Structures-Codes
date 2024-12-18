#include<bits/stdc++.h>
using namespace std;

class node
{
    public:

    int info;
    node* left;
    node* right;
    node(int value) : info(value), left(nullptr), right(nullptr) {}
};

int MaxElement(node * root)
{
    if(!root) return INT_MIN;

    int left = MaxElement(root->left);
    int right = MaxElement(root->right);

    return max(max(left,right),root->info);
}

int main()
{
    node * root   = new node (23);
    node * left   = new node (56);
    node * right  = new node (22);
    node * Lleft  = new node (4);   
    node * Lright = new node (66);
    node * Rleft  = new node (14);   
    node * Rright = new node (26); 
   
 
    root->left = left;
    root->right = right;
    root->left->left = Lleft;
    root->left->right = Lright;
    root->right->left = Rleft;
    root->right->right = Rright;
      
    cout << "Max Element in Tree : " << MaxElement(root) << endl;  
    return 0;
}

