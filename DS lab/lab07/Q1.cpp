
#include<iostream>
using namespace std;

class Node{

    public:
    char * arr;
    int size;
    int pointer;
    
};

class Stack_opeartion {

    Node Array;

    public:
    
    Stack_opeartion(int Size);
    ~Stack_opeartion();
    void push(char character);
    void pop();
    bool IsFull();
    bool IsEmpty();
    char peek();
};

Stack_opeartion::Stack_opeartion(int Size)
{
    Array.arr = new char [Size];
    Array.size = Size;
    Array.pointer = -1;
}

Stack_opeartion::~Stack_opeartion()
{
    delete [] Array.arr;
}

void Stack_opeartion::push(char character)
{
    if(IsFull())
    {
        cout << "Stack is Overflow. " << endl;
        return;
    }
    else 
    {
        Array.pointer++ ;
        Array.arr[Array.pointer] = character;
    }
}

void Stack_opeartion::pop()
{
    if(IsEmpty())
    {
        cout << "Stack is Empty. " << endl;
        return ;
    }
    else
    {
        Array.pointer--;
    }
}

bool Stack_opeartion::IsFull()
{
    return Array.pointer == Array.size - 1;
}

bool Stack_opeartion::IsEmpty()
{
    return Array.pointer == -1;
}


char Stack_opeartion::peek()
{
    if(!IsEmpty())
    {
     return Array.arr[Array.pointer];

    } else
    {
        return '\0';

    }
}

int main()
{
    string name = "Rafay";
    Stack_opeartion obj(name.length());

    for (int i = 0; i < name.length(); i++)
    {
        obj.push(name[i]);
    }

    for (int i = 0; !obj.IsEmpty(); i++)
    {
        name[i] = obj.peek();
        obj.pop();
    }

    cout << "Output is: " << name << endl;

    return 0;
}