
#include<iostream>
using namespace std;

class node
{

public:
    int info;
    node* next;

    node(int info)
    {
        this->info = info;
        this->next = nullptr;
    }
};

void rotateleft(node*& head,int k)
{
    node * temp = head;
    while(temp->next)   temp = temp->next;  

    node * current;
    for(int i = 0 ; i < k ; i++)
    {
        current = head;
        head = head->next;
        temp->next = current;
        temp = current;
        current->next = nullptr;
    }

}


void display(node * head)
{
    node * temp = head;
 
    cout  << "Linked list : ";

    while (temp != nullptr)
    {
        cout << temp->info ;
        if (temp->next != nullptr) cout << "->" ;
        temp = temp->next;
    }
    cout << endl;
}



int main()
{
    int size ;
    cout << "Enter size of linked list : ";
    cin >> size;

    int value;
    cout << "Enter info for next node : ";
    cin >> value;

    node * head = new node(value);
    node * current = head;

    for(int i = 1; i < size ; i++)
    {
       cout << "Enter info for next node : ";
        cin >> value;        

        node* temp = new node(value);
        current->next = temp;
        current = temp;
        
    }

    display(head);

     int k;
     cout << "Enter position for left rotation : ";
     cin >> k;
    rotateleft(head,k);
    cout << "Updated";
     display(head);

    return 0;
}