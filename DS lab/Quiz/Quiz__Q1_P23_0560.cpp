#include<iostream>
using namespace std;

class node
{
    public:

    int info;
    node* left;
    node* right;
    node(int value) : info(value), left(nullptr), right(nullptr) {}
};

int tree(node * root)
{
    if(root && (root->left || root->right))
    {
        if(root->left)
        {
            if(root->info > root->left->info) return tree(root->left);
            else  return -1;
        }

        if(root->right)
        {
            if(root->info < root->right->info) tree(root->right);
            else   return -1;  
        }
    } else return 1;
}

int main()
{
    node * root = new node (23);
    node * left = new node (15);
    node * right = new node (27);
    node * Lleft = new node (5);   
    node * Lright = new node (18);
    node * Rleft = new node (24);   
    node * Rright = new node (26); // this will break BST
   
 
    root->left = left;
    root->right = right;
    root->left->left = Lleft;
    root->left->right = Lright;
    root->right->left = Rleft;
    root->right->right = Rright;

    int i = tree(root);
    
    if (i == 1) cout << "Tree is BST. " << endl;
    else cout << "Tree is not  BST. " << endl;
    
    return 0;
}
