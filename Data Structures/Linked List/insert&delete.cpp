
#include<iostream>
using namespace std;

class Node {

    public:

    int info;
    Node * next;
    Node(int value)
    {
        info = value;
        next = nullptr;
    }
};


class ll{

    Node *head, *current;
    int size;

    public:
    ll() : head(nullptr), current(nullptr), size(0) {}
    bool insert(int position, int value);
    bool Delete(int position);
    void Display();

};

bool ll::insert(int position, int value)
{
    if(position < 0 || position > size) return false;

    Node* temp  = new Node(value); // allocating memory for node

    if(position == 0)  
    {
        temp->next = head;
        current = head = temp;
        size++;
        return true;

    } else {

        for(int i = 0; i < position - 1 ; i++) current = current->next;
        temp->next = current->next;
        current->next = temp;
        current = temp;
        size++;
        return true;
    }
}

bool ll::Delete(int position)
{
    if(position < 0 || position > size) return false;

    Node * temp;
    current = head;

    if(position == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    else
    {
        for(int i = 0; i < position - 1 ; i++) current = current->next;

        temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
        return true;
    }
}


void ll::Display()
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
    ll Ll;

    int value , position;
    bool check;

    do
    {
        cout << "Enter value : ";
        cin >> value;

        cout << "Enter inserting position : ";
        cin >> position;

        check = Ll.insert(position,value);

        if(check == false) cout << "Usuccesfull to add\n";

        cout << "wanna continue adding press 1 ";
        cin >> value;

    } while(value == 1);

   Ll.Display();

    do
    {
        cout << "Enter deletion position : ";
        cin >> position;
        
        check = Ll.Delete(position);
        if(check == false) cout << "Usuccesfull to remove\n";
                Ll.Display();

        cout << "wanna continue deleting press 1 ";
        cin >> value;

    } while(value == 1);
}