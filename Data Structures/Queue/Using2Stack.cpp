
#include<iostream>
#include<stack>
using namespace std;

class Queue
{

    stack<int> front;
    stack<int> Stack;

public:
    void enqueue(int value);
    void dequeue();
    void display();
    int  Isempty();
};

void Queue::enqueue(int value)
{
   front.push(value);
}

void Queue::dequeue()
{
    if(Isempty())
    {
        cout << "Queue is Underflow. " << endl;
        return;
    }

    if (Stack.empty())
    {
        while (!front.empty()) 
        {
            Stack.push(front.top());
            front.pop();
        }
    }

    Stack.pop();
}

int Queue::Isempty()
{
    return front.empty() && Stack.empty();
}

void insertatbottom(stack<int>& temp,int val)
{
    if(temp.empty())
    {
        temp.push(val);
        return;
    }

    int top = temp.top();
    temp.pop();

    insertatbottom(temp,val);

    temp.push(top);
}

void reverse(stack<int>& temp)
{
    if(temp.empty()) return;

    int top = temp.top();
    temp.pop();

    reverse(temp);

    insertatbottom(temp,top);
}


void Queue::display()
{

    stack<int> temp1 = front;
    stack<int> temp2 = Stack;
    reverse(temp1);

    while (!temp2.empty()) 
    {
        cout << temp2.top();
        temp2.pop();   
        if(!temp1.empty() || !temp2.empty()) cout << "-> ";
    }

    while (!temp1.empty()) 
    {
        cout << temp1.top();
        temp1.pop();   
        if(!temp1.empty()) cout << "-> ";
    }

    cout << endl;
}


int main()
{

    Queue obj;

    int value;
    int i = 1;

    do 
    {
        cout << "Enter value in Queue: ";
        cin >> value;  

        obj.enqueue(value);

        cout << "Again (1 -> yes/0 -> NO) : ";
        cin >> i;

    }  while (i != 0 );

    obj.display();
    


    i = 1;
    do 
    {
        cout << "Want to Delete element :  (1 -> yes/0 -> NO) : ";
        cin >> i;
        if(i != 0)
        {
            obj.dequeue();
            obj.display();
        }
    }  while (i != 0 );    
    
    i = 1;
    do 
    {
        cout << "Enter value in Queue: ";
        cin >> value;  

        obj.enqueue(value);

        cout << "Again (1 -> yes/0 -> NO) : ";
        cin >> i;

    }  while (i != 0 );    

    obj.display();
}