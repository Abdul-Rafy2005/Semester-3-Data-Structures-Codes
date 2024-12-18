
#include<iostream>
using namespace std;

class Queue
{
    int size;
    int front;
    int rear;
    int *queue;

public:
    Queue(int Size) : size(Size), front(-1), rear(-1) { queue = new int [size]; }
    ~Queue(){  delete [] queue; }

    void enqueue(int value);
    void dequeue();
    void display();
    int  Isempty();
    int  Isfull();
    int  Peek();
};



void Queue::enqueue(int value)
{
    if(Isfull())
    {
        cout << "Queue is Overflowing. "<< endl;
        return;
    } 
    else  
        queue[++rear] = value;
}

void Queue::dequeue()
{
    if (Isempty())
    {
        cout << "Queue is Underflowing. "<< endl;
        return;
    } 
    else 
        front++; 
}

void Queue::display()
{
    int i = front;
    while (i != rear) 
        cout << queue[++i] << endl;
}

int Queue::Isempty()
{
    if (front == rear) return 1;
    else return 0;
}

int Queue::Isfull()
{
    if(rear == size - 1) return 1;
    else return 0;
}

int Queue::Peek()
{
    return (front != -1) ? queue[front + 1] : front;
}


int main()
{
    int size;
    cout << "Enter size of Queue: ";
    cin >> size;

    Queue obj(size);

    int value;
    int i = 1;
    do 
    {
        cout << "Enter new value in Queue: ";
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