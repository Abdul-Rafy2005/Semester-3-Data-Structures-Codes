
#include<iostream>
using namespace std;

class list{  

    int *array;  // head pointer through which array will be created, and will point to starting address 
    int array_size;  // max size of list 
    int list_size;   // current size of list
    int *current;  // pointer which will traverse through list

    public:
    list () : array(nullptr) , array_size(0) , list_size(0) , current(nullptr) {}
    list(int size);
    ~list();
    bool IsFull();
    bool IsEmpty();
    int* start();
    int* End();
    void back();
    void Next();
    int maxListSize();
    int list_length();
    int get();
    void updated(int positon , int value);
    void add(int value, int position);
    bool Remove(int value);
    void ClearList();
    void display();
    void operator=(list &list1);
};


list::list(int size)
{   
    // setting initial values and creating dynamic array
    array_size = size;
    list_size = 0; 
    array = new int[array_size];
    current = nullptr;
}

list::~list()
{
    // after deallocating memory, setting pointers to null
    delete [] array; 
    array = nullptr;
    current = nullptr;
}

bool list::IsFull()
{
    return list_size == array_size; // when list size reaches it limit
}


bool list::IsEmpty()
{
    return list_size == 0;  // when list size is at its initial position 
}

int*  list::start()
{
    return array;  // return head pointer, which will return address of Oth index
}

int *list::End()
{
    return (array + list_size - 1);  // returing address of the last element of list
}

void list::back()
{
    // checking whether current position is within the list, if yes , then moving it one position back
   if(current > array) --current; 
}

void list::Next()
{
    // checking whether the current position is at the last element of the list
    // if No, then moving it one position forward
    if (current < End() ) current++;  
}

int list::maxListSize()
{
    // return max size of list
    return array_size;
}

int list::list_length()
{
    // return current size of list
    return list_size;
}

int list::get()
{
      // first checking list is empty , if not then returning value from at current pointer
       if (current != nullptr) return *current;
       else return -1;
    
}

void list::updated(int position, int value)
{
    if (position >= 0 && position < list_size)
    {
        int * temp = (start() + position); // assigning the address of given position
        // after reaching a given position, updating its value with the new given value
        *temp = value; 
        current = temp;

    } else
    {
        cout << "\nGiven Position is invalid. " << endl;
    }    
}

void list::add(int value, int position)
{
    if(IsFull()) 
    {
        cout << "\nList is Full. "<< endl;
        return;
    }

    if (position < 0 || position > list_size)
    {
        cout << "\nPosition is not within List. " << endl;
        return;
    }

    int* check = start();

    while (check <= End()) 
    {  
         //loop for checking whether value is already present in list or not 
        if (*check == value)
        {
            cout << "\nSame value is already in list. " << endl;
            return;
        } 
        check++;
    }

    int *temp = (start() + position);  // assigning given position address to temp
    int *temp1 = (End() + 1); // assigning address of after the last alement of list to temp2
    int *temp2 = (temp1 - 1);

    while (temp1 > temp) // shifting value to right, from the End of list up to provided position 
    {
        *temp1 = *temp2;
        temp1--;
        temp2--;
    }

    *temp = value; // adding a new value at new given position
    current = temp;
    list_size++; // increasing the size of list by one 
    

}

bool list::Remove(int position)
{

    if(IsEmpty())
    {
        cout << "\nList is empty." << endl;
        return false;
    }

    if (position < 0 || position > list_size)
    {
        cout << "\nPosition is not within List. " << endl;
        return false;
    } 

        int * temp = ( start() + position);
        

        int* temp1 = (temp + 1); // assigning the adress of one position forward of temp  

        while(temp < End() ) // shifting value to left from that position to End of list
        {
          *temp = *temp1;
          temp++;
          temp1++;
        }

        list_size--;  // decreament in  size of list
        return true;
     
}

void list::ClearList()
{
    list_size = 0;  // setting list size to zero 
    current = nullptr;
}

void list::display() 
{
    if(IsEmpty() ) cout << "List is Empty."<<endl;

    cout << "List elements: ";     // for displaying elements of list upto last element
    
    int* temp = start();

    for ( ; temp <= End() ; temp++)
    {
        cout << *temp << " ";
    } 

}

void list::operator=(list &list1)  // recieving two list of same type as arguement 
{
    if (array != nullptr ) delete [] array;  // if coping list is not empty , make it empty 

    array_size = list1.array_size; // assigning sizes of recieved list to coping list
    list_size = list1.list_size;  

    array = new int [array_size];
    
    // created 2 temp pointer and assign the addresses of both list to these temp pointers
    int * temp = array;
    int * temp2 = list1.array;

    // coping value from recieved list to coping list
    for(int i = 0; i < list_size ; i++) *temp++ = *temp2++;

    // setting the current position same as of list2 
    current = ( (list1.current - list1.array) + array );
    
}

int main() 
{
    int size;  
    cout << "Enter the max size of the list: ";
    cin >> size;  

    list List(size);  // list for all opeartion 
    list temp(size);  // list for only coping opeartion

    int choice , position, value;

    do {
 
        cout << "\n Main Menu \n";
        cout << "1. Add an element.\n";        
        cout << "2. Remove an element.\n";
        cout << "3. Update an element.\n";
        cout << "4. Get the current value of list.\n";
        cout << "5. Check whether list is full.\n";
        cout << "6. Check whether list is empty.\n";
        cout << "7. Get the length of list.\n";
        cout << "8. Get the maximum size of list.\n";
        cout << "9. Clear the list.\n";
        cout << "10. Copy the list.\n";
        cout << "11. Display list.\n";
        cout << "0. Exit.\n";

        cout << "Enter your choice: ";
        cin >> choice;

        bool check;

        switch (choice) {

            case 1:

                cout << "Enter value to add: ";
                cin >> value;

                cout << "Enter position to add:  ";
                cin >> position;

                List.add(value, position);
                break;

            case 2:

                cout << "Enter position to remove element : ";
                cin >> position;

                check = List.Remove(position);
                
                if(check != false) cout  << "Remove Successfully. ";
                break;

            case 3:

                cout << "Enter position to update value: ";
                cin >> position;

                cout << "Enter the new value: ";
                cin >> value;

                List.updated(position, value);
                break;

            case 4:

                value = List.get();

                if (value == -1)   cout << "List is empty. " << endl;
                else cout << "Value at current pointer is : " << value << endl;
                break;

            case 5:

                if (List.IsFull())  cout << "The list is full.\n";
                else cout << "The list is not full.\n";
                break;

            case 6:

                if (List.IsEmpty())   cout << "The list is empty.\n";
                else    cout << "The list is not empty.\n";
                break;

            case 7:

                cout << "List length is: " << List.list_length() << endl;
                break;

            case 8:

                cout << "Maximum list size is: " << List.maxListSize() << endl;
                break;

            case 9:

                List.ClearList();
                cout << "List cleared.\n";
                break;

            case 10:

                temp = List;
                cout << "New copied List : " << endl;
                temp.display();
                cout << endl;
                break;

            case 11:

                List.display();
                cout << endl;
                break;

            case 0:

                cout << "Successfully Exited.\n";
                break;

            default:

                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
