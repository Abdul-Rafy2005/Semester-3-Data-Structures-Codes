
#include<iostream>
#include<random>
using namespace std;

class Node
{
    public:

    int processID;
    string processState;
    int priority;
    unsigned int stack_address;
    unsigned int heap_address;
    Node* Next;
    static int unique_number;
    int parent_ID;


    Node(string State = "New", int Priority = 0 , int ParentID = 0) : processID(++unique_number) , processState(State) , priority(Priority) , Next(nullptr), parent_ID(ParentID)
    {
         stack_address = Random_Address();
         heap_address = Random_Address();
    }
    
    unsigned int Random_Address() // This function will return a random unsigned number.
    {
         random_device R_N; // Create an object 'R_N' this will helps generate random number
         uniform_int_distribution<int> generator(4096,65535); // Defined a range for random numbers between 4096 and 65535.
          return generator(R_N);  // this will Generates and returns a random number within the given range.
    } 

};


int Node::unique_number = 0;


class PCB
{
    Node* process_list;

    public:

    PCB() : process_list(nullptr) {}
    ~PCB();

    void Adding_new_process(string state, int priority, int ID);
    void Remove_process(int ID);
    void kill_all_process();
    void Display();
    void Fork(int ID);
    Node* find_process_byID(int ID);
    void KillParent(int ID);
    void killChild(int ID);
    int GetParentId(int ID);
    int* GetChildId(int ID);

};

PCB::~PCB()
{
    kill_all_process();
} 


void PCB::Adding_new_process(string state, int priority, int ID)
{
    Node * process = new Node(state,priority,ID);

    if(process_list == nullptr) process_list = process;
    else 
    {
        Node * temp = process_list;
        while(temp->Next) temp = temp->Next;
        temp->Next = process;
    }

}

void PCB::Remove_process(int ID)
{
    if (!process_list)
    {
        cout << "List is Empty. \n" << endl;
        return;
    }

    Node * temp = process_list;
    Node * todelete = nullptr;    

    if (temp->processID == ID)
    { 
        process_list = process_list->Next;
        delete temp;
        return;
    }
    

    while (temp->Next)
    {
        if (temp->Next->processID == ID)
        {
            todelete = temp->Next;
            temp->Next = todelete->Next;
            delete todelete;
            return;
        }
        temp = temp->Next;
    }
}


void PCB::kill_all_process()
{
    while(process_list)
    {
        Node* toKill = process_list;
        process_list = process_list->Next;
        delete toKill;
    }
}



void PCB::Display()
{
    if(!process_list)
    {
        cout << "No Processes to Display. \n" << endl;
        return;
    }

    Node * temp = process_list;

    cout  << "Detail Of Processes. " << endl;

    while(temp)
    {
        cout << "Process ID : " << temp->processID << endl;
        cout << "State : " << temp->processState << endl;
        cout << "Priority : " << temp->priority << endl;
        cout << "Stack Address : 0x" << hex << temp->stack_address << endl;
        cout << "Heap Address : 0x" << hex << temp->heap_address << endl;
        cout << "\n" << endl;
        temp = temp->Next;
    }
}



void PCB::Fork(int ID)
{
    Node* parent_process = find_process_byID(ID);

    if(!parent_process)
    {
        cout << "ID doesn't match to any Process. \n" << endl;
        return;
    }
    
    Adding_new_process(parent_process->processState, parent_process->priority,ID);

}



Node *PCB::find_process_byID(int ID)
{   
    Node * temp = process_list;

    while (temp)
    {
        if (temp->processID == ID)   return temp;
        temp = temp->Next;
    }

    return nullptr; 

}

void PCB::KillParent(int ID)
{
    
    if(!process_list)
    {
        cout << "There is no Process to kill currently. \n" << endl;
        return;
    }

    Node* parent_process = find_process_byID(ID);

    if(!parent_process)
    {
        cout << "ID doesn't match to any Process. \n" << endl;
        return;
    }

    Remove_process(ID); // parent will be deleted from this

    Node* temp = process_list;

    while(temp)
    {
        if(temp->parent_ID == ID)  Remove_process(temp->processID);
        temp = temp->Next;
    }

}

void PCB::killChild(int ID)
{       
    if(!process_list)
    {
        cout << "There is no Process to kill currently. \n" << endl;
        return;
    }

    Node* parent_process = find_process_byID(ID);

    if(!parent_process)
    {
        cout << "ID doesn't match to any Process. \n" << endl;
        return;
    }

    Node* temp = process_list;
    Node * prev;

    while(temp)
    {
        if(temp->parent_ID == ID)
        {
           Node* todelete = temp;

           if(prev) prev->Next = temp->Next;
           else process_list = process_list->Next;

           temp = temp->Next;
           delete todelete;
        }
        else
        {
            prev = temp;
            temp = temp->Next;
        }
    }

}

int PCB::GetParentId(int ID)
{
    Node* temp = process_list;

    while (temp)
    {
        if (temp->processID == ID)   return temp->parent_ID;
        temp = temp->Next;
    }

    return 0; 
}


int* PCB::GetChildId(int ID)
{
    if(!process_list)
    {
        cout << "There is no Process currently. \n" << endl;
        return nullptr;
    }

    Node* temp = process_list;
    int size = 0;

    while(temp)
    {
        if(temp->parent_ID == ID) size++;
        temp = temp->Next;
    }

    int* ID_array = new int[size];
    size = 0;
    temp = process_list;

    while(temp)
    {
        if(temp->parent_ID == ID) ID_array[size++] = temp->processID;
        temp = temp->Next;
    }    

    return ID_array;
}

int main() 
{
    PCB obj; 


    obj.Adding_new_process("Waiting", 3 , 0); 
    obj.Adding_new_process("Ready", 6 , 0);   
    obj.Adding_new_process("Running", 4, 0); 
    obj.Display();

    cout << "Forking a Process of ID 2 : \n" << endl;
    obj.Fork(2); 
    obj.Display(); 


    cout << "Adding Another Process : \n" << endl;
    obj.Adding_new_process("New", 2 , 0);  
    obj.Display();

    cout << "Getting Parent ID of process of ID 4 : \n" << endl;
    cout << "Parent ID of process of ID 4 is  : " << obj.GetParentId(4) << endl;

    cout << "Killing a Process of ID 2  and Its Children. \n" << endl;
    obj.KillParent(2); 
    obj.Display();  
 

    obj.kill_all_process(); 
    cout << "Killing All processes. " << endl;
    obj.Display();

    return 0;
}
