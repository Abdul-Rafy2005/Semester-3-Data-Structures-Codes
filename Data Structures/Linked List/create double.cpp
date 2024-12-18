
#include<iostream>
using namespace std;

class node{
    public:
    int value;
    node * next,*previous;
};

class Double{
    node * head;
    public:
    ~Double();
    void Create(int arr[],int size);
    void display();
    int length();
    void insert(int position, int x);
    void Delete(int position);
    void reverse();
};

Double::~Double()
{
    while (head != nullptr) {
        node *temp = head;
        head = head->next;
        delete temp;
    }     
}

void Double::Create(int arr[], int size)
{
    head = new node;
    head->value = arr[0];
    head->next = head->previous = NULL;
    node *temp = head;
    node *temp1;
    for(int i = 1; i <size ;i++){
        temp1 = new node;
        temp1->value  = arr[i];
        temp1->next = temp->next;
        temp1->previous = temp;
        temp->next = temp1;
        temp = temp1;

    }
}

void Double::display()
{
    node * temp = head;
    
    while (temp){
    cout << "["<< temp->value <<"]"<< "-> "; 
    temp = temp->next; 
    
    }
    cout << endl;
}

int Double::length()
{
    node * temp = head;
    int i = 1;
    while (temp){
    temp = temp->next; 
    i++; 
    }  
    return i;  
}

void Double::insert(int position, int x)
{
    if(position < 1 ||  position > length()) return ;

        node *temp = new node;
        temp->value = x;

    if (position == 1){

        temp->previous = NULL;

        if (head == NULL){
            temp->next = temp->previous = NULL;
            head = temp;

        } else {

        temp->next = head;
        head->previous = temp;
        head = temp;

        }


    } else if (position == length()){

        node * temp1 = head;
        while(temp1->next != nullptr) temp1 = temp1->next;
        temp->next = NULL;
        temp->previous = temp1;
        temp1->next = temp;

    }
    else {

        node *temp1 = head;
        for (int i = 0; i < position - 2; i++) temp1 = temp1->next;

        temp->next = temp1->next;
        temp1->next->previous = temp;
        temp->previous = temp1;
        temp1->next = temp;

    }
}

void Double::Delete(int position)
{
    if(position < 1 ||  position > length() - 1 ) return ;

    node *temp = head;
    int x;

    if (position == 1){

        if (temp->next){

            head = temp->next;
            temp->next->previous= NULL;            
            x = temp->value;
            delete temp;

        } else {

            x = temp->value;
            delete temp;
            temp = nullptr;
            head =temp;
        }

    } else {

            for (int i = 1 ; i < position ;i++) temp = temp->next;

            if (temp->next){

            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            x = temp->value;
            delete temp; 

            } else {

                temp->previous->next = NULL;
                x = temp->value;
                delete temp;
            }

    }

}

void Double::reverse()
{
    node * temp = head;
    node * ptr;

    while (temp != nullptr){
         
         ptr = temp->next;
         temp->next = temp->previous;
         temp->previous = ptr;
         temp = temp->previous;         
         if (temp && temp->next == NULL){
            head = temp;
         }

    }
}

int main(){

    int size;
    cout << "Enter the size of Linked list: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size!" << endl;
        return 1; 
    }

    int *arr = new int[size];
    cout << "Enter its values: \n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }    

    Double obj;
    obj.Create(arr,size);
    obj.display();

    // int  position;
    // int value;
    //  cout << "Enter position to insert: ";
    //  cin >> position;
    //  cout << "Enter value to insert: ";
    //  cin >> value;
    // obj.insert(position,value);
    // obj.display();
    // cout << "Enter position to delete : ";
    // cin >> position;    
    // obj.Delete(position);
    // obj.display();  
    cout << "Reverse Linked List: "<<endl;
    obj.reverse();
    obj.display();  


    delete [] arr;
}
