
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

    if (head == nullptr) return;
    node *temp = head;
    temp = head->previous; // taking it a the node where it repeat 
   
    while(temp != head){
        temp->next = head->next; // each iteration move head one node forword
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
    head->previous = head;
    node *point = head;

    

    for (int i = 1 ; i < size ; i++){
        
        node* temp = new node ;
        temp->value = arr[i];
        temp->next = head;
        temp->previous = point;
        point->next = temp;
        head->previous = temp;
        point = temp;

    }
}

 void Circular_linked::display()
 {  
    if (head){
    node *temp = head;
    int i = 1;
    cout << "Linked List : "<< endl;
do{
    cout << "["<< i <<"]"<< "-> "<<  temp->value << endl; 
    temp = temp->next; 
    i++;  
  } while(temp != head);

 }
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

    if(temp1==temp2) cout << "this is a loop linked list.\n";
    if(!temp1 || !temp2) cout << "Linear Linked list.\n";    
}

int Circular_linked::length()
{
    node *temp = head;
    int i = 1;

do{
    temp = temp->next; 
    i++;  
  } while(temp != head);  
  return i;  
}

void Circular_linked::Delete(int position)
{
    if (position < 1 || position >= length() ) return;

    if (position == 1){
        
        node * temp;

        temp = head->previous;
        if (head->previous == head){ // is there only one node 
            delete head;
            head = nullptr;
            
        } else {
            temp->next = head->next;
            head->next->previous = temp;
            delete head;
            head = temp->next;
        }


    }  else {

        node * temp,*temp1;
        temp1 = head;
        for (int i = 1; i < position - 1 ; i++ ) temp1 = temp1->next;
        temp = temp1->next;
        temp1->next = temp->next;
        temp->next->previous = temp1;
        delete temp; 
        
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
            t->next = nullptr;
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

int main() {

    int size;
    cout << "Enter the size of Linked list: ";
    cin >> size;

    if (size < 1) {
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
    obj.display();
    obj.check_loop();
    int value;
    int  position;
    cout << "Enter position to delete : ";
    cin >> position;    
    obj.Delete(position);    
    obj.display();    
    cout << "Enter position to insert: ";
    cin >> position;
    cout << "Enter value to insert: ";
    cin >> value;
    obj.insert(position,value);
    obj.display();
    delete[] arr; 
}    