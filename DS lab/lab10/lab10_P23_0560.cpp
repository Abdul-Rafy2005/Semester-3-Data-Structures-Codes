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

class tree
{
    node* root;
    void delete_tree(node *&root);
    int max_element(node * root);

    public:
    tree() : root(nullptr) {}
    ~tree();
    void Insertion(int value);
    void deletenode(int value);
    void preorder(node * root);
    void Inorder(node * root);
    void Postorder(node * root);
    void Search(int value);
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

int tree::max_element(node *root)
{
    while (root && root->left) root = root->left;
    return root->info;
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
         if(current->info < value) 
         { 
            prev = current;
            current = current->right;
         }
         else if(current->info > value)
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

       if(prev->info > value) prev->left = newnode;
       else prev->right = newnode;

    }
}



void tree::deletenode(int value)
{

    if (root == nullptr) return;
    
    node* current = root;
    node * prev;

    while(current && current->info != value)
    {
        prev = current;
        if(current->info < value)   current = current->right;
        else  current = current->left;
    }

    if(!current)
    {
        cout << "No Such element Found. " << endl;
        return;
    } 

    else 
    {
       if(!current->left && !current->right)
       {
          if(current != root)
          {
            if(prev->left == current) prev->left = nullptr;
            else prev->right = nullptr;
          }   
           else root = nullptr;

           delete current;

       }

        else if(!current->left || !current->right) 
        {

        node* child = (current->left) ? current->left : current->right;

          if(current != root)
          {  
             if(current->left == current) current->left = child;
             else current->right = child;
          }
            else root = child;

            delete current; 

         }

        else
        {
            int successor = max_element(current->right);
            deletenode(successor);
            current->info = successor;
        }

    }
}



void tree::preorder(node * root)
{

    if(root)
    {
        cout << root->info << " ";
        preorder(root->left);
        preorder(root->right);
    }

}


void tree::Inorder(node *root)
{
    if(root)
    {
        Inorder(root->left);
        cout << root->info  << " "; 
        Inorder(root->right);
       
    }
}



void tree::Postorder(node *root)
{
    if(root)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->info  << " ";        
    }
}


void tree::Search(int value)
{
    node* current = root;

    while(current)
    {
        if(current->info > value) current = current->left;
        else if (current->info < value) current = current->right;
        else 
        {
            cout << "value found!" << endl;
            return;
        }    
    }   

    cout << "value not Found. " << endl; 
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


    cout << "Preorder traversal : ";
    BST.preorder(BST.getroot());
    cout << endl;    

    cout << "Inorder traversal : ";
    BST.Inorder(BST.getroot());
    cout << endl;

    cout << "Postorder traversal : ";
    BST.Postorder(BST.getroot());
    cout << endl;


    cout << "Searching value 20 : ";
    BST.Search(20);

    cout << "Searching  value 87: ";
    BST.Search(87);


    cout << "Deleting element 20" << endl;
    BST.deletenode(20);

    BST.Inorder(BST.getroot());
    cout << endl;

    BST.Inorder(BST.getroot());
    cout << endl;

    cout << "Deleting element 70" << endl;
    BST.deletenode(70);

    BST.Inorder(BST.getroot());
    cout << endl;

    return 0;
}
