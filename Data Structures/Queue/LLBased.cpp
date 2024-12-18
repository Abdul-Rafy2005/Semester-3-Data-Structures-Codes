

#include<iostream>
using namespace std;

class node
{
public:
    int value;
    node* next;
    node(int val) : value(val), next(nullptr) {}
};

class Queue
{
    node* front;
    node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    ~Queue();
    void enqueue(int value);
    void dequeue();
    void display();
    int  Isempty();
    int  Peek();
};


Queue::~Queue()
{
    node * temp = front;
    while(temp)
    {   
        front = front->next;
        delete temp;
        temp = front;
    }
}

void Queue::enqueue(int value)
{
    node* temp = new node(value);


    if (front == nullptr) 
        front = rear = temp;
    
    rear->next = temp;
    rear = temp;

}

void Queue::dequeue()
{
    if(Isempty())
    {
        cout << "Queue is Underflow." << endl;
        return;
    }

    node * temp = front;
    front = front->next;
    delete temp; 
}

void Queue::display()
{
    node* temp = front;
    while (temp)
    {
        cout << temp->value;
        temp = temp->next;
        if(temp) cout << " <-";
    }
    cout << endl;
}

int Queue::Isempty()
{
    return (front == nullptr);
}


int Queue::Peek()
{
    return (front) ? front->value : -1;
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

    } while (i != 0 );

        obj.display();
    
        cout << "after Dequeue. \n";
        obj.dequeue();
        obj.display();

}