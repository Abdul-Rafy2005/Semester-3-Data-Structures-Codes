
#include<iostream>
using namespace std;

class node
{
public:
    int value;
    node* next;
    node* prev;
    node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class Queue
{
    node* front;
    node * rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    ~Queue();

    void F_enqueue(int value);
    void R_enqueue(int value);    
    void F_dequeue();
    void R_dequeue();    
    void display();
    int  Isempty();
    int first_elememt();
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

void Queue::R_enqueue(int value)
{
    node* temp = new node(value);

    if (!rear)            
        front = rear = temp;
    else
    {
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }
    
}


void Queue::F_enqueue(int value)
{
    node * temp = new node(value);

    if (!front) 
        front = rear = temp;
    else
    {
        temp->next =  front;
        front->prev = temp;
        front = temp;
    }
}
void Queue::F_dequeue()
{
    if(Isempty())
    {
        cout << "Queue is already empty. " << endl;
        return;
    }
    else
    {
        node * temp = front;
        front = front->next;
        front->prev = nullptr;
        delete temp;
    }
}

void Queue::R_dequeue()
{
    if(Isempty())
    {
        cout << "Queue is already empty. " << endl;
        return;
    }
    else
    {
        node * temp = rear;
        rear = rear->prev;
        rear->next = nullptr;
        delete temp;
    }
}

void Queue::display()
{
    node* temp = front;
    while (temp)
    {
        cout << temp->value << " " ;
        temp = temp->next;
        if(temp) cout << "<-";
    }
    cout << endl;
}

int Queue::Isempty()
{
    return (front == nullptr);
}


int Queue::first_elememt()
{
    if(front) return front->value;
    else return -1;
}


int main()
{
    Queue obj;

    int value;
    int i = 1;

    do 
    {
        cout << "EnQueue from Front: ";
        cin >> value;  

        obj.F_enqueue(value);    

        cout << "Again (1 -> yes/0 -> NO) : ";
        cin >> i;

    }  while (i != 0);


    obj.display();
    
    cout << "Dequeue from Front. " << endl;   
    obj.F_dequeue();
    obj.display();
    i = 1;

    do 
    {
        cout << "Enter value in Queue by Rear: ";
        cin >> value;  

        obj.R_enqueue(value);    

        cout << "Again (1 -> yes/0 -> NO) : ";
        cin >> i;

    }  while (i != 0 );

    obj.display();
    
    cout << "Dequeue from Rear. " << endl;   
    obj.R_dequeue();
    obj.display();

}