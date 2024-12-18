#include<iostream>
using namespace std;

class Queue
{

    int front;
    int rear;
    int size;
    int count;
    int *queue;

    public:
    Queue(int Size) : front(0), rear(0), count(0), size(Size) { queue = new int [size]; }
    ~Queue() { delete [] queue; }

    void enqueue(int value);
    void dequeue();
    void display();
    int  Isempty();
    int Isfull();
    int top();
};


void Queue::enqueue(int value)
{
    if(Isfull())
    {
        cout << "Queue is Overflowing. "<< endl;
        return;
    } 
    else 
    {  
        queue[rear] = value;
        rear = (rear + 1) % size;
        count++;
    }
}

void Queue::dequeue()
{
    if (Isempty())
    {
        cout << "Queue is Already Empty. "<< endl;
        return;
    } 
    else
        front = (front + 1) % size;
        count--;

}

int Queue::Isempty()
{
    return count == 0;
}

int Queue::Isfull()
{
    return rear == size;
}

int Queue::top()
{
    if (!Isempty())
        return queue[front]; 
    else
        return -1;
}


void Queue::display()
{
    if (Isempty()) 
        return;

    int i = front;
    while (i != rear) 
    {
        i = (i + 1) % size;
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter size of Queue: ";
    cin >> size;

    Queue obj(size);


    int value, i = 1;

    do 
    {

        cout << "Enter value in Queue: ";
        cin >> value;  

        obj.enqueue(value);

        cout << "Again (1 -> yes/0 -> NO) : ";
        cin >> i;

    }  while (i != 0 );

    obj.display();
    
    cout << "front element : " << obj.top() << endl;
    cout << "after Dequeue. " << endl;
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
   
    obj.display();

    i++;
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