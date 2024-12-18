
#include<iostream>
#include<cmath>
using namespace std;


class node 
{
public:
    char character;
    node* next;
    node(char Character) : character(Character), next(nullptr) {}
};

class Node
{
public:
    int value;
    Node* next;
    Node(int Value) : value(Value), next(nullptr) {}
};


class conversion
{
    node * Stack;
    char * arr;
    Node * stack_Evaluation;

public:
    conversion() : Stack(nullptr), arr(nullptr), stack_Evaluation(nullptr) {}
    ~conversion()  { delete [] arr; }


    void push(char Character);
    void pop();
    char Peek_infix(); 
    int Isoperand(char Character);
    int outprecidence(char Character);
    int inprecidence(char Character); 
    void convert_Expression(string array);       
    void display();       

    void push(int value);    
    void pop_Eva();
    int peek_Eva();
    int evaluation();
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


char conversion::Peek_infix()
{
    return (Stack) ? Stack->character : '\0';
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


void conversion::convert_Expression(string array)
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
                while (Stack && Peek_infix() != '(') 
                {
                    arr[j++] = Peek_infix();
                    pop();
                }

            if (Stack && Peek_infix() == '(') pop();

            } 
            else 
            {
                if(Stack == nullptr )  push(array[i]);
                else 
                {
                    while (Stack && outprecidence(array[i])  <  inprecidence(Peek_infix()) ) 
                    { 
                        arr[j++] = Peek_infix();
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
        arr[j++] = Peek_infix();
        pop();
    }

    arr[j] = '\0';        
}


void conversion::display()
{
    int i = 0;
    cout << "Postfix Expression : ";
    while (arr[i] != '\0') cout << arr[i++];
    cout << endl;
}


void conversion::push(int value)
{
    Node * temp = new Node(value);

    temp->next = stack_Evaluation;
    stack_Evaluation = temp;    
}


void conversion::pop_Eva()
{
    if(stack_Evaluation)
    {
       Node * temp = stack_Evaluation;
       stack_Evaluation = stack_Evaluation->next;
       delete temp;
    }  
}


int conversion::peek_Eva()
{
    return (stack_Evaluation) ? stack_Evaluation->value : -1;
}


int conversion::evaluation()
{
    int i = 0;
    int result = 0;
    int operand1,operand2;

    while (arr[i] != '\0')
    {
        if(Isoperand(arr[i]))   push(arr[i] - '0');
        else 
        {
            operand2 = peek_Eva();
            pop_Eva();
            operand1 = peek_Eva();
            pop_Eva();

          switch(arr[i])
          {
            case '+':
                    result = (int)(operand1 + operand2);
                    push(result);
                    break;
            case '-':
                    result = (int)(operand1 - operand2);
                    push(result);
                    break;
            case '*':
                    result = (int)(operand1 * operand2);
                    push(result);
                    break;
            case '/':
                    result = (int)(operand1 / operand2);
                    push(result);
                    break;
            case '^':
                    result = (int)pow(operand1,operand2);
                    push(result);  
                    break;                              
          }
       }
       i++;
    }

    result = peek_Eva();
    pop();
    return result;
}


int main()
{
    conversion obj;
    string expression;

    cout << "Enter Exprssion. ";
    cin >> expression;

    obj.convert_Expression(expression);
    obj.display();

    cout << "Postfix Evaluation :  ";
    cout << obj.evaluation() << endl;
}

