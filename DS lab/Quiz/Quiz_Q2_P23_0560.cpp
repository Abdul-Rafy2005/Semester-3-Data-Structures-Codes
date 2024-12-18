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

int height(node * root)
{
    if(root)
    {
        int x,y;
        
        x = height(root->left);
        y = height(root->right);
        if(x>y) return x + 1;
        else return y + 1;
    }
    return 0;
}

void longest_substree(node* root)
{ 
     int left = height(root->left);
     int right = height(root->right);

     if(left >= right) cout << "Left subtree is longest" << endl;
     else cout << "right subtree is longest" << endl;
}

int main()
{
    node * root = new node (23);
    node * left = new node (15);
    node * right = new node (27);
    node * Lleft = new node (5);   
    node * Lright = new node (18);
    node * Rleft = new node (24);   
    node * Rright = new node (28);
    node *LLleft = new node (1);
   
 
    root->left = left;
    root->right = right;
    root->left->left = Lleft;
    root->left->right = Lright;
    root->right->left = Rleft;
    root->right->right = Rright;
    root->left->left->left = LLleft;

    longest_substree(root);





    
    return 0;
}
