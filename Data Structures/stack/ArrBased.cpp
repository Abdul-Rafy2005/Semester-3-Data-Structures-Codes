
#include<iostream>
using namespace std;

class STACK
{
public:
    int *arr;
    int size;
    int pointer;
};

class stack_operation
{
    STACK stack;

public:
    stack_operation() : stack.arr(nullptr), stack.size(0), stack.pointer(-1) {}
    stack_operation(int size) : stack.size(size), stack.pointer(-1)  { stack.arr  = new int [size]; }
    ~stack_operation() { delete [] stack.arr; }

    void push(int value);
    void pop();
    int peek();
    void display();
};


void stack_operation::push(int value)
{ 
    if(stack.pointer == stack.size - 1 ) 
    {   
        cout << "Stack is Overflowing. "<<endl;
        return;
    } 
    else 
        stack.arr[stack.pointer++] = value;


}

void stack_operation::pop(int position)
{
    if (stack.pointer == -1 )
        return; 
    else 
        stack.pointer--;
}

int stack_operation::peek()
{
    return (stack.pointer != -1) ? stack.arr[stack.pointer] : -1;
}

void stack_operation::display()
{
    int x = stack.pointer;
    while (x != -1)
        cout << stack.arr[x--] << endl;
}

int main(){

    int size ;
    cout << "Enter size of stack: ";
    cin >> size;

    stack_operation obj(size);
  
    obj.push(5);
    obj.push(7);
    obj.push(8);

    obj.display();
    cout << obj.peek() << endl;
    obj.pop();
    obj.display();
         
    }

