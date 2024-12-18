
#include<iostream>
using namespace std;

class node
{
public:
    int value;
    node * next,*previous;
};

class Double
{
    node * head;
public:
    ~Double();
    void Create(int arr[],int size);
    void display();
    int length(node* headptr);
    node* gethead() {return head;}
};

Double::~Double()
{
    while (head != nullptr) 
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }     
}

void Double::Create(int arr[], int size)
{
    head = new node;
    head->value = arr[0];
    head->next = head->previous = NULL;

    node *temp = head;
    node *temp1;

    for(int i = 1; i < size ; i++)
    {
        temp1 = new node;
        temp1->value  = arr[i];

        temp1->next = temp->next;
        temp1->previous = temp;

        temp->next = temp1;
        temp = temp1;

    }
}

void Double::display()
{
    node * temp = head;
    
    while (temp)
    {
        cout << temp->value ;
        temp = temp->next; 
        if(temp) cout << " ->"; 
    }
    cout << endl;
}

int Double::length(node* headptr)
{
    if(!headptr) return 0;

    return length(headptr->next) + 1;   
}


 
int main(){

    int size = 8;
    int *arr = new int[size];

    cout << "Enter its values: \n";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }    

    Double obj;
    obj.Create(arr,size);
    obj.display();  

    cout << "Number of Nodes in LL : " << obj.length(obj.gethead()) << endl;
    
    delete [] arr;
}
