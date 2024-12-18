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

bool IsHeap(node * root)
{
    if(!root) return true; 
    return IsHeap(root->left) && ((!root->left && root->right) ? false : true) && IsHeap(root->right);
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
      
    bool val = IsHeap(root);
    if(val == true) 
        cout << "Tree is heap. "<< endl;
    else 
        cout << "Tree is not heap. "<< endl;   

    return 0;
}

