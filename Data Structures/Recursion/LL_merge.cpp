
//  #include<iostream>
//  using namespace std;

//  class Node{
//      public:
//      int value;
//      Node * next;
//      Node(int value)
//      {
//          this->value = value;
//          next = nullptr;
//      }
//  };

//  class list{
    
//      Node * head, *current;
//      int size;

//      public:

//      list();
//      ~list();
//      void insertAtPosition(int position, int value);
//      void remove(int position);
//      Node* merge(Node* list1, Node* list2);
//      void Display();
//      Node* get_head(){ return head; }



//  };

//  list :: list()
//  {
//      size = 0;
//      head = current =  nullptr;
//  }

//  list::~list()
//  {
//      if(head != nullptr)
//      {
//          current = head;
//          while(current != nullptr)
//          {
//             head = head->next;
//             delete current;
//             current = head;
//          }
//      }
    

//  }



//  void list::insertAtPosition(int position, int value)
//  {

//      if(position < 0 || position > size)
//      {
//          cout << "Invalid statment. " << endl;
//          return;
//      }

//      Node* new_node = new Node(value);
    
//      if(position == 0)
//      {
//          new_node->next = head;
//          current = head = new_node;
//          size++;

//      } else

//      {

//          current = head;

//          for(int i = 0 ; i < position - 1 ; i++) current = current->next;
    
//          new_node->next = current->next;
//          current->next = new_node;
//          current = new_node;
//          size++;

//      }
//  }

//  void list::remove(int position)
//  {
//      if(position < 0 || position > size)
//      {
//          cout << "Invalid statment. " << endl;
//          return;
//      }

//      Node* temp;

//      if(position == 0)
//      {
//          temp = head;
//          head = head->next;
//          delete temp; 
//          size--;
 
//      } else {   

//      current = head;
//      for(int i = 0 ; i < position - 1 ; i++) current = current->next;
    
//      temp = current->next;
//      current->next = current->next->next;
//      delete temp;
//      size--;

//      }
//  }

Node *list::merge(Node *list1, Node *list2)
{
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    if(list1->value <= list2->value)
    {
        list1->next = merge(list1->next,list2);
        return list1;
    }
    else
    {
        list2->next = merge(list1,list2->next);
        return list2;
    }
}


//  void list::Display()
//  {
//     Node* temp = head;

//     cout << "Linked list is : ";
   
//     while (temp != nullptr)
//     {
//          cout << temp->value ;
//          if(temp->next != nullptr) cout << " -> " << flush;
//          temp = temp->next;

//     }
//     cout << endl;
//  }


//  int main()
//  {
//      list ll;

//      int value , position;
//      cout << "For 1st list. " << endl;

//      do
//      {
//          cout << "Enter value : ";
//          cin >> value;

//          cout << "Enter inserting position : ";
//          cin >> position;

//          ll.insertAtPosition(position,value);

//          cout << "wanna continue adding press 1 ";
//          cin >> value;

//      } while(value == 1);
     
//      ll.Display();

   
//      list LL;   
//      cout << "For 2nd list. " << endl;
    
//      do
//      {
//          cout << "Enter value : ";
//          cin >> value;

//          cout << "Enter inserting position : ";
//          cin >> position;

//          LL.insertAtPosition(position,value);

//          cout << "wanna continue adding press 1 ";
//          cin >> value;

//      } while(value == 1);
     
//      LL.Display();    

//      Node* list1 = ll.get_head();
//      Node* list2 = LL.get_head();

//      Node * list3 = ll.merge(list1,list2);
//      cout << "Merge Sorted Linked LIst: ";
//      Node * temp = list3;
//      while(temp)
//      {
//          cout << temp->value ;
//          if(temp->next != nullptr) cout << " -> " << flush;
//          temp = temp->next;
 
//      }

//      temp = list3;

//      if(list3 != nullptr)
//      {
//          temp = list3;
//          while(temp != nullptr)
//          {
//             list3 = list3->next;
//             delete temp;
//             temp = list3;
//          }
//      }
//      cout << endl;

//     Node *tempList1 = list1;
//     while (tempList1 != nullptr)
//     {
//         list1 = list1->next;
//         delete tempList1;
//         tempList1 = list1;
//     }

//     Node *tempList2 = list2;
//     while (tempList2 != nullptr)
//     {
//         list2 = list2->next;
//         delete tempList2;
//         tempList2 = list2;
//     }
//  }


