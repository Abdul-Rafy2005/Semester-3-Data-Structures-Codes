
#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

int main() {

     int size;

      cout << "Enter the number of nodes: ";
      cin >> size;

      int array[size];
       cout << "Enter the elements in nodes : ";
      for (int i =0 ; i < size ; i++){
        cin >> array[i];
      }


      struct node* head,*last,*temp;

      head = new node;

      head->data = array[0];
      head->next = nullptr;

      last = head;
      
      for (int i = 1; i < size ; i++){

        temp = new node;
        temp->data = array[i];
        temp->next = nullptr;

        last->next = temp;
        last = temp;


      }


      struct node* search = head;
      int max = search->data;

     while (search != nullptr){
        if (max < search->data ){
            max = search->data;
        }
            cout << search->data << endl;
            search = search->next;
     }

     cout << "Largest element in linked list is : " << max << endl;

}