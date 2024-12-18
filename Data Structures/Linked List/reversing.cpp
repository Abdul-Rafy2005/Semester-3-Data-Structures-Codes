#include<iostream>
using namespace std;

class node{
    public:

    int data ;
    node * next;

};

node * head = nullptr;

void create (int arr[], int size){

    head = new node;
    head->data = arr[0];
    head->next = nullptr;
    node *point = head;

    node * temp;

    for (int i = 1 ; i < size ; i++){
        
        temp = new node ;
        temp->data = arr[i];
        temp->next = nullptr;

        point->next = temp;
        point = temp;

    }   
}


void reversing()
{
    node *temp1 = head;
    node *temp2 = nullptr;
    node *temp3 = nullptr;
    
    while (temp1 != nullptr)
    {   
        temp3 = temp2;
        temp2 = temp1;
        temp1 = temp1->next;
        temp2->next = temp3;     
    }

    head = temp2;
}

void display(){

    node * temp = head;
    int i= 0;
    cout << "Linked List : "<< endl;    
    while (temp != nullptr){

        cout << "["<< i <<"]"<< "-> "<<  temp->data << endl;
        temp = temp->next;

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

    create(arr, size);
    display();
    
    reversing();
    cout << "\nUpdated ";
    display();



    delete[] arr; 

    while (head != nullptr) {
        node *temp = head;
        head = head->next;
        delete temp;
    }     
    }