
#include<iostream>
using namespace std;

class Node
{
    public:

    int info;
    Node* next;

    Node(int integer) : info(integer), next(nullptr) {}
};

class Queue
{
    Node * front, * rear;

    public:

    Queue() : front(nullptr) , rear(nullptr) {}
    ~Queue();
    void Enqueue(int n);
    int Dequeue();    
    bool Isempty();
    void necklace(int k);
    void Display();
};


Queue::~Queue()
{
    Node * temp = front;
    while(temp){
        
        front = front->next;
        delete temp;
        temp = front;
    }
}


void Queue::Enqueue(int integer)
{
   
        Node* temp = new Node(integer);

        if(!front)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    
}

bool Queue::Isempty()
{
     return (front == nullptr);
}

void Queue::necklace(int k)
{
    for(int i  = 0 ; i < k ; i++)
    {
        int value = Dequeue();
        if(value != -1)
        {
            Enqueue(value);
        }
    }
}

void Queue::Display()
{
    Node* temp = front;

    while(temp)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }

    cout << endl;
}

int Queue::Dequeue()
{
    if(Isempty())
    {
        cout << "Queue is Empty.." << endl;
        return -1;
    }

    Node* temp = front;
    int first_value = temp->info;    

    if(front == rear)  front = rear = nullptr;

    else 
    {
        front = front->next;
    }

    delete temp;
    return first_value;
}

int main()
{
    int test_cases;
    int n , k;
    int value;

    cout << "Input " << endl;

    cin >> test_cases;
    Queue * obj = new Queue[test_cases];


    for(int i = 0 ; i < test_cases; ++i)
    {
        cin >> n >> k;
        if(k > n) k = k % n;

    for(int j = 0 ; j < n ; j++)
    {
        cin >>  value;
        obj[i].Enqueue(value);
    }
       
        obj[i].necklace(k);
        cout << endl;
    }

    cout << "Display " << endl;

    for(int i = 0 ; i < test_cases ; i++)   obj[i].Display();
    
    delete [] obj;
}
