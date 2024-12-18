#include<iostream>
using namespace std;

class node
{
    public:

    int MovieID;
    node* left;
    node* right;
    node(int value) : MovieID(value), left(nullptr), right(nullptr) {}
};

class tree
{
    node* root;
    void delete_tree(node *&root);

    public:
    tree() : root(nullptr) {}
    ~tree();
    void Insertion(int value);
    void Inorder(node * root);
    int KthSmallest(node * root,int& k);
    node* getroot() { return root; }
    
};

tree::~tree()
{
   delete_tree(root);
   
}

void tree::delete_tree(node *&root)
{
    if(root){
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}


void tree::Insertion(int value)
{
    node* newnode = new node(value);

    if(!root) root = newnode;
    else
    {
       node* current,*prev;
       current = root;

       while(current)
       {
         if(current->MovieID < value) 
         { 
            prev = current;
            current = current->right;
         }
         else if(current->MovieID > value)
         {
            prev = current;
            current = current->left;
         }  
         else
         {
            delete newnode;
            cout << "Duplicate found." << endl;
            return;
         } 
         
       }

       if(prev->MovieID > value) prev->left = newnode;
       else prev->right = newnode;

    }
}


void tree::Inorder(node *root)
{
    if(root)
    {
        Inorder(root->left);
        cout << root->MovieID  << " "; 
        Inorder(root->right);
       
    }
}


int tree::KthSmallest(node *root, int& k)
{
   if (!root) return 0;

   int value = KthSmallest(root->left, k);
   if (k == 0) return value; // if already k == 0 

   k--;
   if (k == 0) return root->MovieID;

   return KthSmallest(root->right, k);
}



int main() {

    tree BST;

    BST.Insertion(50);
    BST.Insertion(30);
    BST.Insertion(70);
    BST.Insertion(20);
    BST.Insertion(40);
    BST.Insertion(60);
    BST.Insertion(80);


    cout << "Inorder traversal : ";
    BST.Inorder(BST.getroot());
    cout << endl;
    
    int k = 0;
    cout << "when k = 2\n" <<  BST.KthSmallest(BST.getroot(),k) << endl;

    k = 6;
    cout << "when k = 6\n" <<  BST.KthSmallest(BST.getroot(),k) << endl;
    return 0;
}
