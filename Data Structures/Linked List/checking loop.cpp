#include<iostream>
using namespace std;

class node {
    public:
    int value;
    node * next;
};

node * head = nullptr;

void create (int arr[], int size){

    head = new node;
    head->value = arr[0];
    head->next = nullptr;
    node *point = head;

    node * temp;

    for (int i = 1 ; i < size ; i++){
        
        temp = new node ;
        temp->value = arr[i];
        temp->next = nullptr;

        point->next = temp;
        point = temp;

    }   
}


void check_loop(){

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

void display(){

    node * temp = head;
    int i= 0;
    cout << "Linked List : "<< endl;    
    while (temp != nullptr){

        cout << "["<< i <<"]"<< "-> "<<  temp->value << endl;
        temp = temp->next;
        i++;

    }

}



int main() {

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

    create(arr, size);
    node *test = head->next->next;
    node *test1 = head;
    while (test1->next != nullptr) {
        test1 = test1->next;
    }
        test1->next = test; 
    

    check_loop();
    test1->next = nullptr;
    display();

    delete[] arr; 

    while (head != nullptr) {
        node *temp = head;
        head = head->next;
        delete temp;
    }     
}