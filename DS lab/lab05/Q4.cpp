
#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node * next;
    Node* prev;
    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class list{
    
    Node * head, *current;
    int size;

    public:

    list();
    ~list();
    void insert(int position, int value);
    void Display();
    int findNode(int value);
};

list :: list()
{
    size = 0;
    head = current =  nullptr;
}

list::~list()
{
    if(head != nullptr)
    {
        current = head;

        while(current != nullptr)
        {
           head = head->next;
           delete current;
           current = head;
        }        
    }    
}



void list::insert(int position, int value)
{

    if(position < 0 || position > size)
    {
        cout << "Invalid statment. " << endl;
        return;
    }

    Node* new_node = new Node(value);
    
    if(position == 0)
    {
        if(head != nullptr) {
            new_node->next = head;
            head->prev = new_node;
        }
        head = new_node;
        size++;

    } else

    {

        current = head;

        for(int i = 0 ; i < position - 1 ; i++) current = current->next;
    
        new_node->next = current->next;
         if(current->next != nullptr) current->next->prev = new_node;

        new_node->prev = current;
        current->next = new_node;

        current = new_node;
        size++;

    }
}


void list::Display()
{
   Node* temp = head;

   cout << "Linked list is : ";
   
   while (temp != nullptr)
   {
        cout << temp->value ;
        if(temp->next != nullptr) cout << " -> " << flush;
        temp = temp->next;

   }
   cout << endl;
}


int  list::findNode(int value)
{
    if(head == nullptr)  return -1;

    int position = 1;

    current = head;

    while(current != nullptr)
    {
        if(current->value == value) return position;
        else {
            current = current->next;
            position++;
        }
    }

    return -1;
}


int main()
{
    list ll;

    int value , position;

    do
    {
        cout << "Enter value : ";
        cin >> value;

        cout << "Enter inserting position : ";
        cin >> position;

        ll.insert(position,value);

        cout << "wanna continue adding press -> 1 :  ";
        cin >> value;

    } while(value == 1);

    ll.Display();

    cout << "Enter value to Find Node : ";
    cin >> value;

    int Found_position = ll.findNode(value);

    if(Found_position != -1)
    {
        cout << "Found Node value is : " << value << "\nIt's Position is : " << Found_position << endl;
    } else
    {
        cout << "Node is Not Found. " << endl;
    }


}


