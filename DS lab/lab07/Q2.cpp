
#include<iostream>
using namespace std;

class Node{

    public:
    int value;
    Node * next;
    
    Node(int Value) : value(Value), next(nullptr) {}

};


class MinStack{

    Node* main_stack;
    Node* min_stack;
    
    public:

    MinStack(): main_stack(nullptr) , min_stack(nullptr) {}
    ~MinStack();
    void push(int value);
    void pop();
    int top();
    int min_top();
};

MinStack::~MinStack()
{
    Node * temp;

    if(main_stack)
    {
      temp = main_stack;
    while (temp != nullptr)
      { 
        Node *to_delete = temp;
        temp = temp->next;
        delete to_delete;
      }
    }

    if(min_stack)
    {
        temp = min_stack;
        while (temp != nullptr)
      { 
        Node *to_delete = temp;
        temp = temp->next;
        delete to_delete;
      }
    }
}


void MinStack::push(int value)
{
    Node* new_node = new Node(value);
    
     new_node->next = main_stack;
     main_stack = new_node;

    if (min_stack == nullptr || value < min_top())
    {

       Node * Min_new_node = new Node(value);
       Min_new_node->next = min_stack;
       min_stack = Min_new_node;

    }


}

int MinStack::min_top()
{
    if(min_stack) return min_stack->value;
    else return -1;
}

void MinStack::pop()
{
    int value;
    if(main_stack)
    {
        
        Node * todelete = main_stack;
        main_stack = main_stack->next;
        value = todelete->value;
        delete todelete;
    }

    if(min_stack && value == min_top())
    {  
        Node * todelete = min_stack;
        min_stack = min_stack->next;
        delete todelete;  
    }
}


int MinStack::top()
{
    if(main_stack) return main_stack->value;
    else return -1;
}

int main()
{   
    MinStack obj;

    obj.push(2);
    obj.push(5);
    obj.push(-22);
    obj.push(6);
    obj.push(1);
    obj.push(7);
    obj.pop();
    obj.pop();


    cout << obj.top() << endl;
    cout << obj.min_top() << endl;

}
