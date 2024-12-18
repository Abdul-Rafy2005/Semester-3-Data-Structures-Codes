#include<iostream>
#include<queue>
using namespace std;

static int count = 0;   // for Unique ID

class vehicle
{
    public:
    int ID;
    vehicle* next;
    vehicle() : ID(++count),next(nullptr) {}
    
};

class parking
{
    vehicle* head;
    int Parking_limit = 3; // set parking capacity
    int current_size;    
    queue<vehicle*> list;

    public:
    parking() : head(nullptr), current_size(0){}
    ~parking();

    void add();
    void remove(int val);
    void display();

};

parking::~parking()
{
    while(head)
    {
        vehicle* temp = head;
        head = head->next;
        delete temp;
    }

    while(!list.empty()) list.pop();     
}



void parking::add()
{

    vehicle * car = new vehicle();
    list.push(car);
    cout << "Vehicle"<< car->ID << "added. " << endl;

    while ((current_size < Parking_limit) && !list.empty())
    {
        vehicle* newone  = list.front();
        list.pop();
        
        if(head == nullptr) head = newone;
        else 
        {
            vehicle * current = head;
            while(current->next) current = current->next;
            current->next = newone;
        }
        current_size++;
    }    
}

void parking::remove(int ID)
{
    if(!head) return;

    vehicle * current = head;
    vehicle * prev;

    while(current->ID != ID)
    { 
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    cout << "Vehicle"<< current->ID << "removed. " << endl;
    delete current;
    current_size--;

    while ((current_size < Parking_limit) && !list.empty())
    {
        vehicle* newone  = list.front();
        list.pop();
        
        if(head == nullptr) head = newone;
        else 
        {
            vehicle * current = head;
            while(current->next) current = current->next;
            current->next = newone;
        }
        current_size++;
    }     

}

void parking::display()
{
    vehicle* parkingslot = head;

    cout << "parking Slot : [ ";
    while(parkingslot) 
    {
        cout << "vechile " << parkingslot->ID << ", ";
        parkingslot = parkingslot->next;
    }

    cout << "]" << endl;

    queue<vehicle*> list2;

    list2 = list;
    cout << "waiting Slot : [ ";
    while(!list2.empty())
    {
        cout << "vechile " << list2.front()->ID << ", ";
        list2.pop();
    }
    cout << "]" << endl;
}

int main()
{
    parking obj;
    obj.add();
    obj.add();
    obj.add();
    obj.add();
    obj.add();
    obj.add();

    obj.remove(2);
    obj.display();
}