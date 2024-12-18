
#include<iostream>
using namespace std;

class node{
    public :
    int value;
      node * next;
};


class Circular_linked{

    private:
    node* head;
    public:
    Circular_linked(){
        head = new node;
    }
    ~Circular_linked();
    void create(int arr[],int size);
    void display();
    void check_loop();
    int  length();
    void Delete(int position);
    void insert(int position,int x);

};

Circular_linked::~Circular_linked()
{
    node *temp = head;
    while(temp->next != head) temp= temp->next; // taking it a the node where it repeat 
    while(temp != head)
    {
        temp->next = head->next; // each item move head one node forword
        delete head;
        head = temp->next;
    }
    if (head == temp){
        delete head;
        head = nullptr;
    }
}

void Circular_linked::create(int arr[], int size)
{

    head->value = arr[0];
    head->next = head;
    node *point = head;

    node * temp;

    for (int i = 1 ; i < size ; i++){
        
        temp = new node ;
        temp->value = arr[i];
        temp->next = point->next;

        point->next = temp;
        point = temp;

    }
}

 void Circular_linked::display()
 {  
    node *temp = head;
    int i = 0;
    cout << "Linked List : "<< endl;
do{
    cout << "["<< i <<"]"<< "-> "<<  temp->value << endl; 
    temp = temp->next; 
    i++;  
  } while(temp != head);

}

void Circular_linked::check_loop()
{
    node * temp1,*temp2;

    temp1= temp2 = head;

    do {
        temp1 = temp1->next;
        if (temp2->next != nullptr && temp2->next->next != nullptr) {
            temp2 = temp2->next->next;
        } else {
            temp2 = nullptr;
        }
    } while (temp1 && temp2 && temp1 != temp2);

    if(temp1 == temp2) cout << "this is a loop linked list.\n";
    if(!temp1 || !temp2) cout << "Linear Linked list.\n";    
}

int Circular_linked::length()
{
    node *temp = head;
    int i = 0;

do{
    temp = temp->next; 
    i++;  
  } while(temp != head);  
  return i;  
}

void Circular_linked::Delete(int position)
{
    if (position < 0 || position >= length() ) return;

    if (position == 0){
        
        node * temp;
        temp = head;

        while (temp->next != head) temp = temp->next;
        if (temp == head){ // is there is only one node 
            delete head;
            head = nullptr;
        } else {
            temp->next = head->next;
            delete head;
            head = temp->next;
        }


    }  else {

        node * temp,*temp1;
        temp = head;
        for (int i = 0; i < position - 1 ; i++ ) temp = temp->next;
        temp1 = temp;
        temp = temp->next;
        temp1->next = temp->next;
        delete temp; 
        
    }    
}

void Circular_linked::insert(int position,int x)
{
    node *t = new node;
    node *temp = head; 
    t->value = x;
    if(position == 0){

        if(head == NULL){
            t->next = t;
            head = t;
        } else {
           while (temp->next != head) temp = temp->next;
           t->next = head;
           temp->next = t;
           head = t;
        }
    } else {

        for(int i = 0; i < position - 1 ; i++) temp = temp->next;
        t->next = temp->next;
        temp->next = t; 
    }
}

int main() {

    int size;
    cout << "Enter the size of Linked list: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size!" << endl;
        return 1; // Exit the program with an error code
    }

    int *arr = new int[size]; // Dynamically allocate array
    cout << "Enter its values: \n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    Circular_linked obj;
    obj.create(arr, size);
    obj.check_loop();
    // int value;
    int  position;
    // cout << "Enter position to insert: ";
    // cin >> position;
    // cout << "Enter value to insert: ";
    // cin >> value;
    // obj.insert(position,value);
    cout << "Enter position to delete : ";
    cin >> position;    
    obj.Delete(position);
    obj.display();
    delete[] arr; 
}    