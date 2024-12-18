
#include<iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node * next;
    Node(int val)
    { 
        value = val;
    }
};

class Stack
{
    Node* root;
    public:
    Stack()
    {
        root = nullptr;
    } 
    ~Stack();
    void push(int val);
    void pop();
    int peek(); 
    void storeprime();
    bool isempty() { return (root == nullptr); }
};

Stack::~Stack()
{
    while (root != nullptr) 
    { 
        Node *temp = root;
        root = root->next;
        delete temp;
    }
}


void Stack::push(int val)
{
    Node *temp = new Node(val);

    temp->next = root;
    root = temp;
}


void Stack::pop()
{
    if(root == nullptr)  return;

    Node * temp = root;
    root = root->next;
    delete temp;
}



int Stack::peek()
{
    if(root == nullptr) return -1;
    
    return root->value;
}

void Stack::storeprime()
{
    int prime = 0;
    push(1); // initial value
    for(int i = 2; i <= 100 ; i++)
    {
        prime = 1;
        for(int j = i-1; j > 1;j--)
        {
            if(i%j==0)
            {
                prime = 0;
                break;
            }
        }
        if(prime == 1) push(i);
    }
}

int main(){

    Stack obj;
    obj.storeprime();

    cout << "Prime Number Upto 100. " << endl;
    
    while(!obj.isempty())
    {
        cout << obj.peek() << " ";
        obj.pop();
    }
        
}
