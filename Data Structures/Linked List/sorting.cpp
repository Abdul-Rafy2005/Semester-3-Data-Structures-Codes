
#include<iostream>
using namespace std;

class node{
    public:
    int value;
    node * next;
};

node * head = new node;

void create (int arr[], int size){

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
    point->next = nullptr;
}

void display(){

    node * temp = head;
    int i= 0;
    while (temp != nullptr){
        cout << "Actually Linked List : "<< endl;
        cout << "["<< i <<"]"<< "-> "<<  temp->value << endl;
        temp = temp->next;

    }

}

void sort(){
     
    if (!head || !head->next) return; // if list is empty or has only one element, no need to sort
    
    node * temp1,*temp2; 
    int temp;

    for (temp1 = head; temp1->next != nullptr;temp1 = temp1->next){
        for (temp2 = temp1->next ; temp2 != nullptr ; temp2= temp2->next){

           if (temp1->value > temp2->value){
              temp = temp1->value;
              temp1->value = temp2->value;
              temp2->value = temp;
           }
        }
    }
}

int main()
{
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
    cout << "\n\nAfter sorting.\n";
    sort();
    display();

    delete [] arr;
}
