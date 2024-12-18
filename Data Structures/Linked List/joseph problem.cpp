#include <iostream>
using namespace std;

class Node 
{
public:
    int value;
    Node* next;
    Node(int val) value(val), next(nullptr) {}  
};

class list 
{
    Node* head;
    int size;

public:
    list() : head(nullptr), size(0) {}
    ~list();
    void insertAtPosition(int position, int value);
    void remove(int position);
    void Display();
    int JosephProblem(int k);
};

list::~list() 
{
    if (head != nullptr) 
    {
        Node* temp = head;
        while (temp->next != head) 
        {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete temp;
    }
}

void list::insertAtPosition(int position, int value) 
{
    if (position < 0 || position > size) {
        cout << "Invalid position." << endl;
        return;
    }

    Node* new_node = new Node(value);

    if (position == 0) 
    {   
        if (!head) 
        {
            new_node->next = new_node;  
            head = new_node;
        } 
        else 
        {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            new_node->next = head;
            temp->next = new_node;
            head = new_node;
        }
        size++;  

    } else 
    {
        Node* current = head;
        for (int i = 0; i < position - 1; i++) current = current->next;
        new_node->next = current->next;
        current->next = new_node;
        size++;  
    }
}

void list::remove(int position) 
{
    if (position < 0 || position >= size || head == nullptr) 
    {
        cout << "Invalid position or empty list." << endl;
        return;
    }

    Node* temp;

    if (position == 0) 
    {
        temp = head;
        while (temp->next != head) temp = temp->next;
        
        if (head == temp) 
        {  
            delete head;
            head = nullptr;

        } else {

            temp->next = head->next;
            delete head;
            head = temp->next;
        }

    } else {

        Node* current = head;
        for (int i = 0; i < position - 1; i++) current = current->next;
        
        temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    size--;   
}

void list::Display() 
{
    if (!head) 
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "Linked list is: ";

    do 
    {
        cout << temp->value;
        temp = temp->next;
        if (temp != head) cout << " -> ";
        
    } while (temp != head);
    cout << endl;
}

int list::JosephProblem(int k) 
{
    if (!head || k <= 0) return -1;  

    Node* current = head;

    while (current->next != current) 
    {  
        for (int i = 0; i < k - 1; i++) current = current->next;
        
        Node* temp = current->next;
        current->next = current->next->next;
        if (temp == head) head = head->next;   
        delete temp;
    }
    
    int lastValue = current->value;
    delete current;
    head = nullptr;   
    return lastValue;
}

int main() 
{
    list ll;

    int value, position;

    do {
        cout << "Enter value: ";
        cin >> value;

        cout << "Enter inserting position: ";
        cin >> position;

        ll.insertAtPosition(position, value);

        cout << "Want to continue adding? Press 1: ";
        cin >> value;

    } while (value == 1);

    ll.Display();

    int k;
    cout << "Enter K for Josephus Problem: ";
    cin >> k;

    int last_element = ll.JosephProblem(k);
    cout << "Last remaining element is: " << last_element << endl;

    return 0;
}
