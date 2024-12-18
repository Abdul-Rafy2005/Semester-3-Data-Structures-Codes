
#include<iostream>
using namespace std;

class node
{
public:
    int value;
    node * next;
    node() : value(0), next(nullptr) {}
    node(int val) : value(val), next(nullptr) {}
};

node * head = new node;

void create (int arr[], int size)
{
    head->value = arr[0];

    node *point = head;
    node * temp;

    for (int i = 1 ; i < size ; i++)
    {   
        temp = new node(arr[i]);
        point->next = temp;
        point = temp;

    }   
    point->next = nullptr;
}

void deletion()
{
    node* temp = head;

    while(temp)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void display()
{

    node* temp = head;

    while (temp)
    {
        cout << temp->value;
        temp = temp->next;
        if(temp) cout <<  "-> ";
    }
    cout << endl;

}

int CombinationCount()
{ 
    if (!head || !head->next) return -1; 
    
    node *temp1,*temp2; 
    int count;

    for (temp1 = head; temp1->next != nullptr; temp1 = temp1->next){
        for (temp2 = temp1->next; temp2 != nullptr; temp2= temp2->next){
            if ((temp1->value + temp2->value) % 2 == 0) 
                count++;
        }
    }
    return count;
}

int main()
{
    int size = 6;
    int *arr = new int[size];

    cout << "Enter its values: " << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    

    create(arr, size);
    display();

    cout << "Total combination of Nodes generating even number by their addition are : " << CombinationCount() << endl;

    delete [] arr;
    deletion();
}
