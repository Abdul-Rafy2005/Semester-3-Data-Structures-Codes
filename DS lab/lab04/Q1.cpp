

#include<iostream>
using namespace std;

class Node{
    public:
    int info;
    Node* next;
    
    Node(int value) : info(value), next(nullptr) {}
};

class LL{

    Node* head, * tail;

    public:

    LL();
    ~LL();
    void insertAtTail(int value);
    void display();
};

LL::LL()
{
    head = tail = nullptr;
}

LL::~LL()
{
    Node* temp;
    while(head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void LL::insertAtTail(int value)
{
    Node* temp = new Node(value);

    if(head == nullptr)
    {
        head = tail = temp;
    }

    else 
    {
        tail->next = temp;
        tail = temp;
    }
}

void LL::display()
{
    Node* temp = head;

   cout << "Linked list is : ";
   
   while (temp != nullptr)
   {
        cout << temp->info ;
        if(temp->next != nullptr) cout << " -> " << flush;
        temp = temp->next;

   }
   cout << endl;
}


int main()
{
   LL ll;

    int value;

    do
    {
        cout << "Enter value : ";
        cin >> value;

        ll.insertAtTail(value);

        cout << "wanna continue adding press -> 1 :";
        cin >> value;

    } while(value == 1);

    ll.display();

    
}
