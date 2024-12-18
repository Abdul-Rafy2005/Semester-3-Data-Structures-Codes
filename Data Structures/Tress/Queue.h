
using namespace std;

class Node
{
  public:
  Node *left;
  int value;
  Node *right;
};

class node{  
    public:
    Node *address;
    node * next;

};

class Queue{

    node* front;
    node * rear;

    public:
    Queue();
    ~Queue();
    void enqueue(Node* x);
    Node* dequeue();
    int  Isempty();
};

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue()
{
    node * temp = front;
    while(temp){
        
        front = front->next;
        delete temp;
        temp = front;
    }
}

void Queue::enqueue(Node* x)
{
    node * temp = new node;

    if(temp == nullptr) 
    {
        cout << "Heap is Full. " << endl;
        return;

    } else 
    {
        temp->address = x;
        temp->next = nullptr;

        if (front == nullptr) 
        {
          front = rear = temp;
        } else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}

Node*  Queue::dequeue()
{
    Node* x = nullptr;
    if(Isempty())
    {
        cout << "Queue is already empty. " << endl;

    }
    else
    {
        node * temp = front;
        front = front->next;
        x = temp->address;
        delete temp;
    }
    return x;
}


int Queue::Isempty()
{
     return (front == nullptr);
}

