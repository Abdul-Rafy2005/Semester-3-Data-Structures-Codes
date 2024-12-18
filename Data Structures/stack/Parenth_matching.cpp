
#include<iostream>
#include<string>
using namespace std;


class Stack
{
    public:
    int size;
    int top;
    char * arr;
};

class Parenthesis_match
{
    Stack ptr;
    public:
    Parenthesis_match(int size)
    {
        ptr.size = size;
        ptr.top = -1;
        ptr.arr = new char [size];
    }

    void match(string array);
    void push(char character);
    void pop();
    int Empty();
};


void Parenthesis_match::match(string array)
{
    for (int i = 0 ; array[i] != '\0' ; i++)
    {
        if (array[i] == '(') push(array[i]);
        if(array[i] == ')') 
        { 
          if (ptr.top == -1) 
          {
            cout << "Unbalanced Parenthesis. " << endl;
            return;        
          }
        pop();          
        }
    }

    if(Empty())
        cout << "Parenthesis is Matching. "<< endl;
    else 
        cout << "Parenthesis is not Matching. "<< endl;
    
}

void Parenthesis_match::push(char character)
{
    ptr.arr[++ptr.top] = character;
}

void Parenthesis_match::pop()
{   
    ptr.top--;   
}

int Parenthesis_match::Empty()
{
   if(ptr.top == -1) return 1;
   return 0;
}


int main()
{

    string expression;

    cout << "Enter the String: ";
    cin >> expression;

    Parenthesis_match obj((int)expression.length());
    obj.match(expression);
}