
#include<iostream>
#include<queue>
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
    void Inorder(node * root);
    void Search(int value);
    int height(node * root);
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
    while (root && root->right) root = root->right;
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
        if(current->info < value) current = current->right;
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
            int predecessor = max_element(current->left);
            deletenode(predecessor);
            current->info = predecessor;
        }

    }
}

int tree::height(node * root)
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

void tree::Inorder(node *root)
{
    if(root)
    {
        Inorder(root->left);
        cout << root->info  << " "; 
        Inorder(root->right);
       
    }
}



void tree::Search(int value)
{
    node* current = root;
    queue<int>path;
    while(current)
    { 
        path.push(current->info);
        if(current->info > value) current = current->left;
        else if (current->info < value) current = current->right;
        else 
        {
            while(!path.empty())
            {
                cout << path.front();
                path.pop();
                if(!path.empty()) cout << "->";
            }
            return;
        }    
    } 

    while(!path.empty()) path.pop();   // clearing queue
             
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
  

    cout << "Inorder traversal after insertion: ";
    BST.Inorder(BST.getroot());
    cout << endl;



    cout << "Inorder traversal after deleting node 30 (replaced by it's in-order predecessor): " << endl;
    BST.deletenode(30);
    BST.Inorder(BST.getroot());
    cout << endl;

    cout << "Height of BST is : " << BST.height(BST.getroot()) - 1;
    cout << endl;

    cout << "Path to node 60: ";
    BST.Search(60);
    cout << endl;


    return 0;
}
