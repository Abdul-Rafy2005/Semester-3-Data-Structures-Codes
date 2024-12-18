
#include<iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node * next;
};

class Stack{
    Node* root;
    public:
    Stack(){
        root = nullptr;
    } 
    ~Stack();
    void push();
    void display();
    void pop(int position);
    void peek(int position);
    int length();
    
};

Stack::~Stack()
{
        while (root != nullptr) { // first and second are cnow part of third
        Node *temp = root;
        root = root->next;
        delete temp;
    }
}


void Stack::push()
{
    Node *temp = new Node;
    cout << "Enter the value : ";
    cin >>  temp->value;

    if(root == nullptr) temp->next = nullptr;
    else temp->next = root;
    root = temp;
}

void Stack::display()
{
    Node * temp = root;
    while(temp){
        cout << temp->value << endl;
        temp = temp->next;
    }

}

void Stack::pop(int position)
{
    if (position < 1 || position > length()) {
        cout << "Invalid position." << endl;
        return;
    }

    Node *current = root;
    Node *temp = nullptr;

    for (int i = 1; i <= position && current != nullptr; ++i) {
        temp = current;
        current = current->next;
        delete temp;
    }


    root = current;
}


int Stack::length()
{
    Node *temp = root;
    int i = 1;

while (temp){
    i++;
    temp = temp->next;

}  
  return i;  
}

void Stack::peek(int position)
{
    if (position < 1 || position > length()) {
        cout << "Invalid position." << endl;
        return;
    }

    Node *temp = root;
    for (int i = 1; i < position; ++i){
        temp = temp->next;
    }

    cout << "Value at position [" << position << "] is: " << temp->value << endl;
}


int main(){

    Stack obj;
 int i =0 ; 
 do {
    obj.push();
    cout << "For Another input (1 for yes/0 for NO) : ";
    cin >> i;
 }  while (i != 0 );

   obj.display();
   cout << "Enter the position of node to delete: ";
   cin >> i;
   obj.pop(i); 
   cout << "update stack list : \n";
   obj.display();
   cout << "Enter node position for show : ";
   cin >> i;
   obj.peek(i);


    
}
