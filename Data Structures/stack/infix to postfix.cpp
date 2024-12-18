
#include<iostream>
using namespace std;

class node 
{
public:
    char character;
    node * next;
    node(char Character) : character(Character), next(nullptr) {}
};

class conversion
{
    node * Stack;
    char * arr;

public:
    conversion() : Stack(nullptr), arr(nullptr) {}
    ~conversion(){ delete [] arr;  }

    void push(char Character);
    void pop();
    char peek();    
    void convert(string array);
    int Isoperand(char Character);
    int outprecidence(char Character);
    int inprecidence(char Character);   
    void display();
};


void conversion::push(char Character)
{
    node * temp = new node(Character);

    temp->next = Stack;
    Stack = temp;

}

void conversion::pop()
{
    if(Stack)
    {
       node * temp = Stack;
       Stack = Stack->next;
       delete temp;
    }  
}

char conversion::peek()
{
    return (Stack) ? Stack->character : '\0';
}


void conversion::convert(string array)
{
    int size = array.length() + 1;  // +1 for '\0'
    arr = new char[size];

    int i = 0,j = 0;

    while (array[i] != '\0')
    { 
        if(Isoperand(array[i]))  arr[j++] = array[i];     
        else 
        {
            if (array[i] == ')') 
            {
                while (Stack && peek() != '(') 
                {
                    arr[j++] = peek();
                    pop();
                }

            if (Stack && peek() == '(') pop();

            } 
            else 
            {
                if(Stack == nullptr )  push(array[i]);
                else 
                {
                    while (Stack && outprecidence(array[i])  <  inprecidence(peek()) ) 
                    { 
                        arr[j++] = peek();
                        pop();
                    }            
                    push(array[i]);
                }   
            } 
        }
                    i++;
    }

    while (Stack)
    {
        arr[j++] = peek();
        pop();
    }

    arr[j] = '\0';     
}

int conversion::Isoperand(char Character)
{
    if (Character != '+' && Character != '-' && Character != '*' && Character != '/' && 
        Character != '^' && Character != '(' && Character != ')' )   return 1;
    else return 0;
}


int conversion::outprecidence(char Character)
{
    if (Character == '+' || Character == '-') return 1;
    else if (Character == '*' || Character == '/') return 3;
    else if (Character == '^' ) return 6;
    else if (Character == '(') return 7;
    else 
        return 0;       
}


int conversion::inprecidence(char Character)
{
    if (Character == '+' || Character == '-') return 2;
    else if (Character == '*' || Character == '/') return 4;
    else if (Character == '^' ) return 5;
    else
        return 0;   // ( -> operator precidence
}


void conversion::display()
{
    int i = 0;
    cout << "Post Expression : ";
    while (arr[i] != '\0') cout << arr[i++];
    cout << endl;
}

int main()
{
    conversion obj;
    string expression;

    cout << "Enter Exprssion. ";
    cin >> expression;

    obj.convert(expression);
    obj.display();
}