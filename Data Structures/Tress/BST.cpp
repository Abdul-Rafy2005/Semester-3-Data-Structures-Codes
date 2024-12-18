
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

class tree
{
    node* root;
    void delete_tree(node *&root);
    int Right_min(node * root);

public:
    tree() : root(nullptr) {}
    ~tree() {  delete_tree(root); }

    void Insertion(node* current,node* prev, int value);
    void deletion(node* current, node* prev, int value);
    void preorder(node* root);
    void Inorder(node* root);
    void Postorder(node* root);
    void itear_pre();
    void itear_inorder();
    void level_order();
    int count(node *Root);
    node* getroot() { return root; }
    
};


void tree::delete_tree(node *&root)
{
    if(root)
    {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}


int tree::Right_min(node *root)
{
    while (root && root->left) root = root->left;
    return root->info;
}

void tree::Insertion(node* current,node* prev, int value)
{
    if(current && current->info == value)
    {
        cout << "Duplicate Found!" << endl;
        return;
    }
    
    if(!current)
    {
        node* newnode = new node(value);

        if(!root)  root = newnode;
        else if (value < prev->info) prev->left = newnode;
        else prev->right = newnode;
        
        return;
    }
    
    if(current->info > value) Insertion(current->left,current,value);
    else Insertion(current->right,current,value);
       
}



void tree::deletion(node* current, node* prev, int value)
{

    if (current == nullptr)
    {
        cout << "No Such element Found!" << endl;
        return;
    }
    
    if(current->info > value) deletion(current->left,current,value);
    else if (current->info < value)  deletion(current->right,current,value);
    else 
    {
       if(!current->left && !current->right)
       {
           if(current != root)
           {
               if(prev->left == current) prev->left = nullptr;
               else prev->right = nullptr;
           }  

           else { root = nullptr; }
           delete current; 

        }

        else if(!current->left || !current->right) 
        {
            node* child = (current->left) ? current->left : current->right;

            if(current != root)
            {  
                if(prev->left == current) prev->left = child;
                else prev->right = child;
            }
            
            else { root = child; }

            delete current; 

        }

        else
        {
            int successor = Right_min(current->right);
            deletion(current->right,current,successor);
            current->info = successor;
        }
    }
}

void tree::preorder(node *root)
{
    if(root)
    {
        cout << root->info  << " "; 
        Inorder(root->left);
        Inorder(root->right); 
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

int tree::duplicates(node* root, int value)
{
    if (!root) return 0;

    if (root->info == value) 
        return root->count; 

    if (value < root->info) 
        return duplicates(root->left, value); 
    else    
        return duplicates(root->right, value);
}

void tree::itear_pre()
{
    stack<node*> list;
    node* current = root;

    while(current || list.empty())
    {
        if(current)
        {
            cout << current->info << " ";
            list.push(current);
            current = current->left;

        } else {

            current = list.top();
            list.pop();
            current = current->right;
        }      
    }
}

void tree::itear_inorder()
{
    stack<node*> list;
    node* current = root;

    while(current || !list.empty())
    {
        if(current)
        {
            list.push(current);
            current = current->left;

        } else {

            current = list.top();
            list.pop();
            cout << current->info << " ";
            current = current->right;
        }      
    }    
}

void tree::level_order()
{
    queue<node*>list;
    node* current;

    cout << root->info << " ";
    list.push(root);

    while(!list.empty())
    {
        current = list.front();
        list.pop(); 

        if(current->left)
        {
            cout << current->left->info << " ";
            list.push(current->left);
        }
        if(current->right)
        {
            cout << current->right->info << " ";
            list.push(current->right);
        }    
    }
}


int tree::count(node *Root)
{
    int x,y;
    while (Root)
    {
        x = count(Root->left);
        y = count(Root->right);
        return x + y + 1;

    }
    return 0;
}


int main() 
{
    tree BST;

    BST.Insertion(BST.getroot(),nullptr,50);
    BST.Insertion(BST.getroot(),nullptr,30);
    BST.Insertion(BST.getroot(),nullptr,60);  
    BST.Insertion(BST.getroot(),nullptr,40);  


    cout << "Inorder traversal : ";
    BST.Inorder(BST.getroot());
    cout << endl;


    cout << "Deleting element 20" << endl;
    BST.deletion(BST.getroot(),nullptr,20);

    BST.Inorder(BST.getroot());
    cout << endl;

    return 0;
}
