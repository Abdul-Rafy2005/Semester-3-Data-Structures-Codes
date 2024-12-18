
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


void reversing(node * temp, node * temp1){

    if (temp){

        reversing(temp->next,temp);
        temp->next = temp1;

    } else {

        head = temp1;
    }



}

void display(){

    node * temp = head;
    int i= 0;
    while (temp != nullptr){
        cout << "Linked List : "<< endl;
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


    
    reversing(head,NULL);
    cout << "\nUpdated ";
    display();



    delete[] arr; 

    while (head != nullptr) {
        node *temp = head;
        head = head->next;
        delete temp;
    }     
    }