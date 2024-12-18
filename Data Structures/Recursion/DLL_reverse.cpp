
// #include<iostream>
// using namespace std;

// class Node{
//     public:
//     int value;
//     Node * next;
//     Node* prev;
//     Node(int value)
//     {
//         this->value = value;
//         next = nullptr;
//         prev = nullptr;
//     }
// };

// class list{
    
//     Node * head, *current;
//     int size;

//     public:

//     list();
//     ~list();
//     void insert(int position, int value);
//     void remove(int position);
//     void reverse();
//     void Display();
//     void ReverseDisplay();
//     void Reverse_recursion(Node* current);
//     Node* get_head() { return head; }



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



// void list::insert(int position, int value)
// {

//     if(position < 0 || position > size)
//     {
//         cout << "Invalid statment. " << endl;
//         return;
//     }

//     Node* new_node = new Node(value);
    
//     if(position == 0)
//     {
//         if(head != nullptr) {
//             new_node->next = head;
//             head->prev = new_node;
//         }
//         head = new_node;
//         size++;

//     } else

//     {

//         current = head;

//         for(int i = 0 ; i < position - 1 ; i++) current = current->next;
    
//         new_node->next = current->next;
//          if(current->next != nullptr) current->next->prev = new_node;

//         new_node->prev = current;
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
//     if(head == nullptr) return;
    
//     Node* temp;

//     if(position == 0)
//     {
//         temp = head;
//         head = head->next;
//         if (head != nullptr)head->prev = nullptr;
//         delete temp; 
//         size--;
 
//     } else {   

//     current = head;
//     for(int i = 0 ; i < position - 1 ; i++) current = current->next;
    
//     temp = current->next;
//     current->next = current->next->next;
//     if(current->next != nullptr ) current->next->prev = current;
//     delete temp;
//     size--;

//     }
// }

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

// void list::reverse()
// {
//     Node *temp = head;

//     while(temp->next != nullptr) temp = temp->next;
//     head = temp;
// }

void list::Reverse_recursion(Node* current)
{
    if(current == nullptr) return;

    if (current->next == nullptr) head = current;
      
    Reverse_recursion(current->next);

    Node* temp = current->next;
    current->next = current->prev;
    current->prev = temp;


}


// void list::ReverseDisplay()
// {
//     Node* temp = head;

//    cout << "Reverse Linked list is : ";
   
//    while (temp != nullptr)
//    {
//         cout << temp->value ;
//         if(temp->prev != nullptr) cout << " -> " << flush;
//         temp = temp->prev;

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

//         ll.insert(position,value);

//         cout << "wanna continue adding press 1 ";
//         cin >> value;

//     } while(value == 1);

//     ll.Display();

//     do
//     {
//         cout << "Enter deletion position : ";
//         cin >> position;
        
//         ll.remove(position);
//                 ll.Display();

//         cout << "wanna continue deleting press 1 ";
//         cin >> value;

//     } while(value == 1);

//     ll.Reverse_recursion(ll.get_head());
//     ll.Display();
//     // ll.reverse();
//     // ll.ReverseDisplay();
// }

