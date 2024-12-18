
#include<iostream>
using namespace std;

class node{
    public :
    int value;
      node * next;
      node * previous;
};


class Circular_linked{

    private:
    node* head;

    public:
    Circular_linked() : head(nullptr) {};
    ~Circular_linked();
    void display();
    void insert(int position,int x);
    void delete_odd();


};

Circular_linked::~Circular_linked()
{

    if (head == nullptr) return;

    node *temp = head;
    node * to_delete;
   
    
    do{

       to_delete = temp;
       temp = temp->next;
       delete to_delete;

    }while(temp != head);

        head = nullptr;
     
}
   

void Circular_linked::display()
 {  
    if (head)
    {
    node *temp = head;
    int i = 1;
    cout << "Linked List : "<< endl;
do{
    cout << "["<< i <<"]"<< "-> "<<  temp->value << endl; 
    temp = temp->next; 
    i++;  
  } while(temp != head);

  } else 
  {
    cout << "List is Empty.."<< endl;
  }
}

void Circular_linked::insert(int position,int x)
{
    node *t = new node;
    node *temp = head; 
    t->value = x;

    if(position == 1){

        if(head == NULL){

            t->previous = t;
            t->next = t;
            head = t;

        } else {

           temp = head->previous;
           t->next = head;
           head->previous = t;
           t->previous =temp;
           temp->next = t;
           head = t;

        }

    } else {

        for(int i = 1; i < position - 1 ; i++) temp = temp->next;
        t->next = temp->next;
        temp->next->previous = t;
        temp->next = t; 
        t->previous = temp;
    }
}

void Circular_linked::delete_odd() {

    if (!head) return;  

    node* current = head;
    int position = 1;

  
        node* todelete;

       // for head, for 1st position     
        todelete = head;
        head = head->next;
        todelete->previous->next = head;
        head->previous = todelete->previous;
        delete todelete;

        current = head;
        position++;

    do
    { // traversing each node and checking whether this node is in odd position or not
        todelete = current;
        current = current->next;

        if (position % 2 == 1)
        {
            todelete->previous->next = current;
            current->previous = todelete->previous;
            delete todelete;
        }
        position++;
    } while (current != head);
}


int main() {

    int position, value;
    int choice;

    Circular_linked obj;

    do{
    cout << "Enter position to insert: ";
    cin >> position;

    cout << "Enter value to insert: ";
    cin >> value;

    obj.insert(position,value);


    cout << "Wanna Contiue adding press -> 1 : ";
    cin >> choice;

    } while(choice != 0);

    obj.display();

    cout << "Reverse ";
    obj.delete_odd();
    obj.display();
 
}    