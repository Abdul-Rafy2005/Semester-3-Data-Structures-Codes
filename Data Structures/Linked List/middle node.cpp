#include <iostream>
using namespace std;
 
class node{
public:
    int data;
    node* next;
};
 
node* head = new node;

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

void middle(){

    node * temp1 = head,*temp2 = head;
    while(temp2){

        temp2 = temp2->next;
        if(temp2) temp2 = temp2->next;
        if (temp2) temp1 = temp1->next;
    }

    cout << "Middle node is : " << temp1->data;

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

    create(arr, size);
    middle();
    delete [] arr;
}