
#include<iostream>
using namespace std;

class node
{
    public:
    char Character;
    node * next;
    node(char character) : Character(character), next(nullptr) {}
};

class Stack
{
    node* head;

    public:
    Stack(): head(nullptr) {} 
    ~Stack();
    void match(string array);
    void push(char Character);
    void display();
    void pop();
    int length();
    bool empty();
    char top();
    
};

Stack::~Stack()
{
    while (head != nullptr) 
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}


void Stack::push(char character)
{
    node* temp = new node(character);
    temp->next = head;
    head = temp;  
}

void Stack::display()
{
    node * temp = head;
    while(temp)
    {
        cout << temp->Character << endl;
        temp = temp->next;
    }

}

void Stack::pop()
{
    if(head)
    {
        node *current = head;
        head = head->next;
        delete current;
    } 
    else 
        cout << "Unbalanced Parenthesis. " << endl;
    
}

void Stack::match(string array)
{
    for(int i = 0 ; i < (int)array.length() ; i++)
    {
        if (array[i] == '{' ||  array[i] == '(' || array[i] == '[')  push(array[i]);
         
        if(array[i] == '}' ||  array[i] == ')'||  array[i] == ']')
        {

            if (!head)
            {
                cout << "Unbalanced Parentesis. "<<endl;
                return ;
            }

            char topchar = top();

            if((array[i] == '}' && topchar != '{') || (array[i] == ')' && topchar != '(') ||
               (array[i] == ']' && topchar != '[')) {
                cout << "Unbalanced Parenthesis. "<<endl;
                return;
            }
            pop();
        }
     }

     if(empty()) cout << "Balanced Parenthesis ."<<endl;
     else cout << "Unbalanced Parenthesis ."<<endl;
}

bool Stack::empty()
{
   return (!head);
}


char Stack::top() 
{
    return (head) ? head->Character : '\0';
}

int Stack::length()
{
    node *temp = head;
    int i = 1;

   while (temp)
   {
       i++;
       temp = temp->next;
   }  
  return i;  
}



int main(){

   string expression;
   cout << "Enter Expression: ";
   cin >> expression;

   Stack obj;
   obj.match(expression);


    
}


