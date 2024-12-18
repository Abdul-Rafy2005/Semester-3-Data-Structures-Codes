
#include<iostream>
using namespace std;

class node
{
public :
    int value;
    node * next;
};


class Circular_linked
{
    node* head;

public:
    Circular_linked(){ head = new node;  }
    ~Circular_linked();

    void create(int arr[],int size);
    void display();
    bool checkPrime(int number);
    int CountPrime();
};

Circular_linked::~Circular_linked()
{
    node *temp = head;

    while(temp->next != head) temp= temp->next; 

    while(temp != head)
    {
        temp->next = head->next; 
        delete head;
        head = temp->next;
    }
    if (head == temp){
        delete head;
        head = nullptr;
    }
}

void Circular_linked::create(int arr[], int size)
{

    head->value = arr[0];
    head->next = head;
    node *point = head;

    node * temp;

    for (int i = 1 ; i < size ; i++)
    {
        temp = new node ;
        temp->value = arr[i];
        temp->next = point->next;

        point->next = temp;
        point = temp;
    }
}

void Circular_linked::display()
{  
    node *temp = head;  
    do
    {
        cout << temp->value;
        temp = temp->next; 
        if(temp != head) cout << " -> "; 

    } while(temp != head);
    cout << endl; 
}




bool Circular_linked::checkPrime(int number)
{
    if(number <= 1) return false;
    if (number == 2) return true;

    for(int i = number/2 ; i > 1 ; i--)
    {
        if(number % i == 0)
            return false;
    }

    return true;         
}


int Circular_linked::CountPrime()
{
    node* temp1;
    node* temp2;
    int j,i = 1;
    int count = 0;

    for(temp1 = head ; temp1->next != head ; temp1 = temp1->next)
    {    
        if(checkPrime(i))
        { 
            j = i + 1;
            for(temp2 = temp1->next ; temp2 != head ; temp2 = temp2->next)
            {
                if(checkPrime(j))
                    if(checkPrime(temp1->value + temp2->value))
                    count++;
                j++;
            }
        }
        i++;
    }
    return count;
}



int main() 
{
    Circular_linked obj;
    int size = 6;

    int *arr = new int[size]; 

    cout << "Enter values: " << endl;
    for (int i = 0; i < size; i++)
        cin >> *(arr + i);

    
    obj.create(arr, size);
    obj.display();

    cout << "Number of Combination of nodes at Prime position result to Prime number : " << obj.CountPrime() << endl;


    delete[] arr; 
}









