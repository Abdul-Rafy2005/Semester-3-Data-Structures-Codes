
// #include<iostream>
// using namespace std;

// class Node{
//     public:
//     int value;
//     Node * next;
//     Node(int value)
//     {
//         this->value = value;
//         next = nullptr;
//     }
// };

// class list{
    
//     Node * head, *current;
//     int size;

//     public:

//     list();
//     ~list();
//     void insertAtPosition(int position, int value);
//     void remove(int position);
//     bool check_palindrome(Node* current,Node*& head);
//     void Display();
//     Node* get_head(){ return head; }



// };

// list :: list()
// {
//     size = 0;
//     head = current =  nullptr;
// }

// list::~list()
// {
//     if(head != nullptr)
//     {
//         current = head;
//         while(current != nullptr)
//         {
//            head = head->next;
//            delete current;
//            current = head;
//         }
//     }
    

// }



// void list::insertAtPosition(int position, int value)
// {

//     if(position < 0 || position > size)
//     {
//         cout << "Invalid statment. " << endl;
//         return;
//     }

//     Node* new_node = new Node(value);
    
//     if(position == 0)
//     {
//         new_node->next = head;
//         current = head = new_node;
//         size++;

//     } else

//     {

//         current = head;

//         for(int i = 0 ; i < position - 1 ; i++) current = current->next;
    
//         new_node->next = current->next;
//         current->next = new_node;
//         current = new_node;
//         size++;

//     }
// }

// void list::remove(int position)
// {
//     if(position < 0 || position > size)
//     {
//         cout << "Invalid statment. " << endl;
//         return;
//     }

//     Node* temp;

//     if(position == 0)
//     {
//         temp = head;
//         head = head->next;
//         delete temp; 
//         size--;
 
//     } else {   

//     current = head;
//     for(int i = 0 ; i < position - 1 ; i++) current = current->next;
    
//     temp = current->next;
//     current->next = current->next->next;
//     delete temp;
//     size--;

//     }
// }



bool list::check_palindrome(Node *current, Node*& head)
{
    if(!current) return true;

    bool check =  check_palindrome(current->next,head);

    if (!check) 
        return false;

    bool matching = (head->value == current->value);

    head = head->next;

    return matching;
   
}



// void list::Display()
// {
//    Node* temp = head;

//    cout << "Linked list is : ";
   
//    while (temp != nullptr)
//    {
//         cout << temp->value ;
//         if(temp->next != nullptr) cout << " -> " << flush;
//         temp = temp->next;

//    }
//    cout << endl;
// }


// int main()
// {
//     list ll;

//     int value , position;

//     do
//     {
//         cout << "Enter value : ";
//         cin >> value;

//         cout << "Enter inserting position : ";
//         cin >> position;

//         ll.insertAtPosition(position,value);

//         cout << "wanna continue adding press 1 ";
//         cin >> value;

//     } while(value == 1);

//     ll.Display();



//     Node* dummy_head = ll.get_head();

//     if( ll.check_palindrome(ll.get_head() ,dummy_head) ) cout << "Palindrome. "<< endl;

//     else cout << "Not Palindrome. " << endl;
    
// }

