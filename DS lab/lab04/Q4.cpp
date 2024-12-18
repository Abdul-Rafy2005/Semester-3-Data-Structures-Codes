#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;

    Node(int value) : info(value), next(nullptr) {}
};

class LL
{

    Node *head, *tail;

public:
    LL();
    ~LL();
    void insertAtTail(int value);
    void display();
    Node *merge(Node *list1, Node *list2);  
    Node* getHead()
    {
    return head;
    }
};

LL::LL()
{
    head = tail = nullptr;
}

LL::~LL()
{
    Node *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void LL::insertAtTail(int value)
{
    Node *temp = new Node(value);

    if (head == nullptr)
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
    Node *temp = head;

    cout << "Linked list is: ";

    while (temp != nullptr)
    {
        cout << temp->info;
        if (temp->next != nullptr)
            cout << " -> " << flush;
        temp = temp->next;
    }

    cout << endl;
}

Node *LL::merge(Node *list1, Node *list2) 
{

    Node *temp = new Node(list1->info);
    list1 = list1->next;

    Node *list3_head = temp;

    while (list1)
    {
        Node *temp1 = new Node(list1->info);
        list1 = list1->next;
        temp->next = temp1;
        temp = temp1;
    }


    while (list2)
    {
        Node *temp1 = new Node(list2->info);
        list2 = list2->next;
        temp->next = temp1;
        temp = temp1;
    }


    Node *Temp1, *Temp2;
    int Temp;
    for (Temp1 = list3_head; Temp1->next != nullptr; Temp1 = Temp1->next)
    {
        for (Temp2 = Temp1->next; Temp2 != nullptr; Temp2 = Temp2->next)
        {
            if (Temp1->info > Temp2->info)
            {
                Temp = Temp1->info;
                Temp1->info = Temp2->info;
                Temp2->info = Temp;
            }
        }
    }

    return list3_head;
}

int main()
{
    LL list1;
    LL list2;

    int value, Continue;

    do
    {
        cout << "Enter value: ";
        cin >> value;

        list1.insertAtTail(value);

        cout << "Wanna continue adding. Press 1: ";
        cin >> Continue;

    } while (Continue == 1);

    list1.display();

    
    do
    {
        cout << "Enter value: ";
        cin >> value;

        list2.insertAtTail(value);

        cout << "Wanna continue adding? Press 1: ";
        cin >> Continue;

    } while (Continue == 1);

    list2.display();

    
    Node *mergedList = list1.merge(list1.getHead(), list2.getHead());  


    cout << "Merged and sorted list: ";
    while (mergedList)
    {
        cout << mergedList->info;
        if (mergedList->next != nullptr)
            cout << " -> ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}
