
#include <iostream>
using namespace std;

class node 
{
  public:
    node* left;
    int MovieID;
    int height;
    node* right;  
};

class AVL 
{
    node* root;
    int Node_height(node* p);
    int BalanceFactor(node* p);
    node* LLRotation(node* p);
    node* RRRotation(node* p);
    node* LRRotation(node* p);
    node* RLRotation(node* p);
    node* InPre(node* p);
    node* InSucc(node* p);    

  public:

    AVL() { root = nullptr; }

    node* Insert(node* p, int key);
    node* Delete(node* p, int key);
    node* getRoot() { return root; }
    void Inorder(node* p);
    void setRoot(node* p) { root = p; }

};

int AVL::Node_height(node* p) 
{
    int h_Lsubtree, h_Rsubtree;

    if (p && p->left) h_Lsubtree = p->left->height;     
    else   h_Lsubtree = 0;
    
    if (p && p->right)   h_Rsubtree = p->right->height;
    else   h_Rsubtree = 0;

    return h_Lsubtree > h_Rsubtree ? h_Lsubtree + 1 : h_Rsubtree + 1;
}

int AVL::BalanceFactor(node* p) 
{
    int h_Lsubtree, h_Rsubtree;

    if (p && p->left) h_Lsubtree = p->left->height;     
    else   h_Lsubtree = 0;
    
    if (p && p->right)   h_Rsubtree = p->right->height;
    else   h_Rsubtree = 0;

    return h_Lsubtree - h_Rsubtree;
}

node* AVL::LLRotation(node* p) 
{
    node* p_left = p->left;
    node* p_left_right = p_left->right;

    p_left->right = p;
    p->left = p_left_right;

    p->height = Node_height(p);
    p_left->height = Node_height(p_left);


    if (root == p)   root = p_left;
    return p_left;
}

node* AVL::RRRotation(node* p) 
{

    node* p_right = p->right;
    node* p_right_left = p_right->left;

    p_right->left = p;
    p->right = p_right_left;

    p->height = Node_height(p);
    p_right->height = Node_height(p_right);

    if (root == p)  root = p_right;

    return p_right;
}

node* AVL::LRRotation(node* p) 
{
    node* p_left = p->left;
    node* p_left_right = p_left->right;

    p_left->right = p_left_right->left;
    p->left = p_left_right->right;

    p_left_right->left = p_left;
    p_left_right->right = p;

    p_left->height = Node_height(p_left);
    p->height = Node_height(p);
    p_left_right->height = Node_height(p_left_right);

    if (p == root)   root = p_left_right;
    return p_left_right;
}

node* AVL::RLRotation(node* p) 
{
    node* p_right = p->right;
    node* p_right_left = p_right->left;

    p_right->left = p_right_left->right;
    p->right = p_right_left->left;    

    p_right_left->right = p_right;
    p_right_left->left = p;

    p_right->height = Node_height(p_right);
    p->height = Node_height(p);
    p_right_left->height = Node_height(p_right_left);

    if (root == p)  root = p_right_left;
    return p_right_left;

}

node* AVL::InPre(node* p) 
{
    while (p && p->right != nullptr)   p = p->right;
    return p;
}

node* AVL::InSucc(node* p) 
{
    while (p && p->left != nullptr)   p = p->left;
    return p;
}

node* AVL::Insert(node* p, int key) 
{
    node* t;

    if (p == nullptr) 
    {
        t = new node;
        t->MovieID = key;
        t->left = nullptr;
        t->right = nullptr;
        t->height = 1;  
        return t;
    }

    if (key < p->MovieID)   p->left = Insert(p->left, key);
    else if (key > p->MovieID)   p->right = Insert(p->right, key);
    
    p->height = Node_height(p);

    
    if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1)   return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1)  return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1)   return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1)  return RLRotation(p);
    
    return p;
}


node* AVL::Delete(node* p, int key) 
{
    if (p == nullptr)   return nullptr;


    if (p->left == nullptr && p->right == nullptr) 
    {
        if (p == root)   root = nullptr;

        delete p;
        return nullptr;
    }

    if (key < p->MovieID)  p->left = Delete(p->left, key);
    else if (key > p->MovieID)  p->right = Delete(p->right, key);
    else 
    {
        node* q;

        if (Node_height(p->left) > Node_height(p->right)) 
        {
            q = InPre(p->left);
            p->MovieID = q->MovieID;
            p->left = Delete(p->left, q->MovieID);

        } else 
        {
            q = InSucc(p->right);
            p->MovieID = q->MovieID;
            p->right = Delete(p->right, q->MovieID);
        }
    }

    p->height = Node_height(p);


    if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1)   return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1)  return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1)  return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1)  return RLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 0)  return LLRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 0)  return RRRotation(p);

    return p;
}


void AVL::Inorder(node* p) 
{
    if (p) 
    {
        Inorder(p->left);
        cout << p->MovieID << ", ";
        Inorder(p->right);
    }
}

int main() 
{
    AVL tree;

    int A[] = {10, 20, 30, 25, 28, 27, 5};

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
             tree.setRoot(tree.Insert(tree.getRoot(), A[i]));


    tree.Inorder(tree.getRoot());
    cout << endl;

    tree.Delete(tree.getRoot(), 28);

    tree.Inorder(tree.getRoot());
    cout << endl;

    return 0;
}
