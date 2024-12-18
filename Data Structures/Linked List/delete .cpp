#include<iostream>
using namespace std;

class node{
    public :
    int data;
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


int count() {
    int count = 0;
    node* Head = head;
    while (Head != nullptr) {
        count++;
        Head = Head->next;
    }
    return count;
}


void display(){

    node * temp = head;
    int i= 0;
    while (temp != nullptr){
        cout << "Actually Linked List : "<< endl;
        cout << "["<< i <<"]"<< "-> "<<  temp->data << endl;
        temp = temp->next;
        i++;

    }

}


void Delete (int position){

    if (position < 0 || position >= count() ) return;

    if (position == 0){
        
        node * temp;
        temp = head;
        head = head->next;
        delete temp;

    }  else {

        node * temp,*temp1;
        temp = head;
        for (int i = 0; i < position - 1 ; i++ ) temp = temp->next;
        temp1 = temp;
        temp = temp->next;
        temp1->next = temp->next;
        delete temp;
    
    /* // also good logic
    for (int i = 0; i < position - 1; i++) temp = temp->next;
        node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    */    
        
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
    
    int position;
    cout << "Enter Node position to delete :  ";
    cin >> position;

    Delete(position);
    cout << "Updated ";
    display();



    delete[] arr; 

    while (head != nullptr) {
        node *temp = head;
        head = head->next;
        delete temp;
    }     
    }