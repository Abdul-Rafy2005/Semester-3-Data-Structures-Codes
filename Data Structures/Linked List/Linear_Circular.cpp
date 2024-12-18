
#include<iostream>
using namespace std;

class Node{

    public:

    int info;
    Node* next;
    Node(int value) : info(value), next(nullptr) {}
};


class Circular_ll{

    Node* head, *current;
    int size;

    public:

    Circular_ll();
    ~Circular_ll();
    void insert(int position,int value);
    void remove(int position);
    void display();
    Node* reach(int position)
    {
        Node* temp = head;
        for(int i = 0; i < position - 1 ; i++) temp = temp->next;
        return temp;
    }
};

Circular_ll::Circular_ll()
{
        head = current = nullptr;
        size = 0;
}

Circular_ll::~Circular_ll()
{
    if(head)
    {
        Node*temp;
        current = head;
        while(current->next != head)
        {
            temp = current;
            current = current->next;
            delete temp;
        }

        delete current;
        delete head;
    }
}


void Circular_ll::insert(int position, int value)
{
     
    if(position < 0 || position > size){
        cout << "Invalid position . "<< endl;
        return;
    }

    
    Node* new_node = new Node(value);

    if(position == 0)
    {
      if(!head)
      {
        current = head = new_node;
        new_node->next = head;
      }
      
      else
      {
        Node* tail = reach(size);
        new_node->next = head;
        head = new_node;
        tail->next = head;
        current = head;
      }
        size++;  
    }

    else
    {
        current = reach(position );
        new_node->next = current->next;
        current->next = new_node;
        current = new_node;
        size++;
    }
}

void Circular_ll::remove(int position)
{
     
    if(position < 0 || position > size){
        cout << "Invalid position . "<< endl;
        return;
    }

    Node* temp;

    if(position == 0)
    {
        current = reach(size);
        temp = head;
        head = head->next;
        current->next = head;
        current = head;
        delete temp;
        size--;
    }

    else
    {
        current = reach(position);
        temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }

        
}


void Circular_ll::display()
{
   Node* temp = head;

   cout << "Linked list is : ";
   
   do
   {
        cout << temp->info ;
        if(temp->next != head) cout << " -> " << flush;
        temp = temp->next;

   }while (temp != head);
   cout << endl;
}

int main()
{
    Circular_ll ll;

    int value , position,choice;

    do
    {
        cout << "Enter value : ";
        cin >> value;

        cout << "Enter inserting position : ";
        cin >> position;

        ll.insert(position,value);

        cout << "wanna continue adding press 1 ";
        cin >> choice;

    } while(choice == 1);

    ll.display();

    do
    {

        cout << "Enter deletion position : ";
        cin >> position;

        ll.remove(position);
        ll.display();

        cout << "wanna continue removing press 1 ";
        cin >> choice;

    } while(choice == 1);



}