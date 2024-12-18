
#include<iostream>
#include<stack>
#include "Queue.h"


class BinaryTree{

    Node * root;
    void Breaktree(Node* & root);

    public:
    BinaryTree();
    ~BinaryTree();
    void create();
    void preorder(Node * root);
    void Inorder(Node * root);
    void Postorder(Node * root);
    int count(Node * root);
    Node* getRoot();

    // iteartive traversal

    void Itear_preorder();
    void Itear_Inorder();
    void levelOrder();
};

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
    Breaktree(root);
}

void BinaryTree::Breaktree(Node *&root)
{
    if(root){
        Breaktree(root->left);
        Breaktree(root->right);
        delete root;
    }
}


void BinaryTree::create()
{
    int value;
    Queue list;

    cout << "Enter the value of root : ";
    cin >> value;

    root = new Node;
    root->value = value;
    root->left = root->right = nullptr;
    list.enqueue(root);

    Node* pointer = nullptr;
    Node* temp = nullptr;

    while (!list.Isempty())
    {
        pointer = list.dequeue();

        cout << "Enter Left child's value of " << pointer->value << " : ";
        cin >> value;

        if(value  != -1)
        {
            temp = new Node;
            temp->value = value;
            temp->right = temp->left = nullptr;
            pointer->left = temp;
            list.enqueue(temp);
        }

        cout << "Enter Right child's value of " << pointer->value << " : ";
        cin >> value;

        if(value  != -1)
        {
            temp = new Node;
            temp->value = value;
            temp->right = temp->left = nullptr;
            pointer->right = temp;
            list.enqueue(temp);
        }
    }
}


void BinaryTree::preorder(Node * root)
{

    if(root)
    {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }

}


void BinaryTree::Inorder(Node *root)
{
    if(root)
    {
        Inorder(root->left);
        cout << root->value << " "; 
        Inorder(root->right);
       
    }
}

void BinaryTree::Postorder(Node *root)
{
    if(root)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->value << " ";        
    }
}

int BinaryTree::count(Node *root)
{
    int x,y;
    while (root != NULL)
    {
        x = count(root->left);
        y = count(root->right);
        return x + y + 1;

    }
    return 0;
}

void BinaryTree::Itear_preorder()
{
    stack <Node*> list;
    Node *temp = root;
    
    while(temp || !list.empty())
    {
        if(temp)
        {
            cout << temp->value << " ";
            list.push(temp);
            temp = temp->left;

        } else {

            temp = list.top();
            list.pop();
            temp = temp->right;
        }
    }
}

void BinaryTree::Itear_Inorder()
{
    stack <Node*> list;
    Node *temp = root;
    while(temp || !list.empty())
    {
        if(temp)
        {
            list.push(temp);
            temp = temp->left;

        } else {

            temp = list.top();
            list.pop();
            cout << temp->value << " ";            
            temp = temp->right;
        }
    }    
}

void BinaryTree::levelOrder()
{
    Queue list;
    Node *temp = nullptr;

    cout << root->value << " ";
    list.enqueue(root);

    while(!list.Isempty())
    {
        temp = list.dequeue();

        if(temp->left)
        {
            cout << temp->left->value << " ";
            list.enqueue(temp->left);
        }
        
        if(temp->right)
        {
            cout << temp->right->value << " ";
            list.enqueue(temp->right); 
        }
    }
}

Node *BinaryTree::getRoot()
{
    return root;
}

int main()
{
    BinaryTree BT;
    BT.create();


    // cout << "PreOrder : ";
    // BT.preorder(BT.getRoot());
    // cout << "\nInOrder : ";
    // BT.Inorder(BT.getRoot());
    // cout << "\nPostOrder : ";
    // BT.Postorder(BT.getRoot());

    // cout << "PreOrder : ";
    // BT.Itear_preorder();

    // cout << "\nInOrder : ";
    // BT.Itear_Inorder();

    // cout <<"Level Order : ";
    // BT.levelOrder();

    cout << BT.count(BT.getRoot());
}