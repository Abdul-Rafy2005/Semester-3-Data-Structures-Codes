#include<iostream>
using namespace std;

class node {
    public:
    int value;
    node * next;
};

node * first = nullptr;
node * Second = nullptr;
node * third= nullptr;


void create(int arr[],node* &head,int size){

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


void display(node * list){

    node * temp = list;
    int i= 0;
    while (temp != nullptr){

        cout << "["<< i <<"]"<< "-> "<<  temp->value << endl;
        temp = temp->next;
        i++;
    }

}


void merging(node* &first,node* &Second){

    node * last = nullptr; 
    if (first->value > Second->value){

        third=last=Second;
        Second = Second->next;
        last->next = nullptr;

    }  else {

        third=last=first;
        first = first->next;
        last->next = nullptr;
  
    }

    while (first && Second){

        if (first->value > Second->value){
            last->next = Second;
            last =Second;
            Second = Second->next;
        } else {
            last->next = first;
            last = first;
            first = first->next;
        }
            last->next = nullptr;         
    }
    

    if (first != nullptr)    last->next = first;

    if (Second != nullptr)   last->next = Second; 
   

}


int main()
{
    int size1,size2;
    cout << "Enter the size of Linked list 1 and 2: ";
    cin >> size1 >> size2;

    if (size1 <= 0 && size2 <= 0) {
        cout << "Invalid size!" << endl;
        return 1; 
    }

    int *arr = new int[size1]; 
    cout << "Enter values of 1st list: \n";
    for (int i = 0; i < size1; i++) {
        cin >> arr[i];
    }
        create(arr,first, size1);
        delete [] arr;  



    arr = new int[size2]; 

    cout << "Enter values of 2nd list: \n";
    for (int i = 0; i < size2; i++) {
        cin >> arr[i];
    }    
        create(arr,Second, size2);


    cout << "Merge sorted Linked list : "<<endl;
    merging(first,Second);
    display(third);




    while (third != nullptr) { // first and second are cnow part of third
        node *temp = third;
         third = third->next;
        delete temp;
    } 
}