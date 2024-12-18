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

void display(){

    node * temp = head;
    int i= 0;
    while (temp != nullptr){
        cout << "Actually Linked List : "<< endl;
        cout << "["<< i <<"]"<< "-> "<<  temp->data << endl;
        temp = temp->next;

    }

}

void delete_duplicate(){

    node * temp1,*temp2;
    temp1 = head;
    temp2 = temp1->next;

    while (temp2 != nullptr){

        if (temp1->data != temp2->data){
            temp1 = temp2;
            temp2 = temp2->next;

        } else {

            temp1->next = temp2->next;
            delete temp2;
            temp2 = temp1->next;
        }
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
    
    delete_duplicate();
    cout << "\nUpdated ";
    display();



    delete[] arr; 

    while (head != nullptr) {
        node *temp = head;
        head = head->next;
        delete temp;
    }     
    }