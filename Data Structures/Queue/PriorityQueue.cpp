
#include<iostream>
using namespace std;

class node
{
public:
    int value;
    node* next;
    node(int Value) : value(Value), next(nullptr) {}  
};

class priorityQueue{

    node * front;

public:
    priorityQueue() : front(nullptr) {}
    ~priorityQueue() {  while (!Isempty()) dequeue(); }

    void enqueue(int value);
    void dequeue();
    void display();
    int  Isempty();
    int first_elememt();

};

   

void priorityQueue::enqueue(int value)
{
    node* temp = new node(value);


    if (front == nullptr || front->value > value)
    {
        temp->next = front;
        front = temp;  
    } 
    else 
    {
        node* temp1 = front;

        while (temp1->next != nullptr && temp1->next->value <= value) 
            temp1 = temp1->next;

        temp->next = temp1->next;
        temp1->next = temp;
    }


    
}

void priorityQueue::dequeue()
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
        delete temp;
    }    
}

void priorityQueue::display()
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

int priorityQueue::Isempty()
{
     return (front == nullptr);
}


int priorityQueue::first_elememt()
{
    if(front) return front->value;
    else return -1;
}


int main()
{
    
    priorityQueue obj;
    int value;
    int i = 1;
    do {

    cout << "Enter value in Queue: ";
    cin >> value;  

    obj.enqueue(value);

    cout << "Again (1 -> yes/0 -> NO) : ";
    cin >> i;

    }  while (i != 0 );

    cout << "Queue is : " << endl;
    obj.display();
    
    cout << "after deleting elements. \n";
    cout << "Queue is : " << endl;    
    obj.dequeue();
    obj.dequeue();
    obj.display();

}
