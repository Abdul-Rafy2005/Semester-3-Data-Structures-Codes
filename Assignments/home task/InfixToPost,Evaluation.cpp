
#include<iostream>
#include<string>
using namespace std;

class node{   // for converting INfix to Postfix Expression

    public:
    char character;
    node * next;

    node(char Character) : character(Character), next(nullptr) {}

};

class Node{  // for Evaluation of Posfix Expression

    public:

    int value;
    Node * next;

    Node(int Value) : value(Value), next(nullptr) {}
};



class conversion
{
    node * Stack; // to store operators during conversion from infix to postfix
    char * arr;  // to store final postfix expression 
    Node * stack_Evaluation; // stack for Evaluation

    public:

    conversion() : Stack(nullptr) , arr(nullptr) , stack_Evaluation(nullptr) {}

    ~conversion()
    {
        delete [] arr;
    }


    void push(char Character);  // for converting expression
    void push(int value); // for  Evaluation
    void pop();  // for converting expression
    void pop_Eva(); // for  Evaluation
    void convert_Expression(string array);
    char Peek_infix();  // for converting expression
    int peek_Eva(); // for  Evaluation
    int Is_operand(char Character);  // check whether digit
    int outprecidence(char Character); // for precedence of a opeartor before entering stack
    int inprecidence(char Character); // for precedence of a opeartor after entered stack    
    void display();
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


int conversion::Is_operand(char Character)
{
    if (Character >= '0' && Character <= '9') return 1;
    else return 0;
}


char conversion::Peek_infix()
{ 
    if(Stack) return Stack->character;
    else return '\0';
}


void conversion::convert_Expression(string array)
{
    int size = array.length() + 1; // +1 for storing '\0' in last of arr
    arr = new char[size];

    int i = 0,j = 0;

    while (array[i] != '\0') 
    {
        if(Is_operand(array[i])) // checking whether a digit is present there
        {
           while (Is_operand(array[i]))  arr[j++] = array[i++]; // storing digits in arr until a opeartor comes

            arr[j++] = ' ';  // spacing in arr for seperating digits

        } else {

            if (array[i] == ')')  
            {
                while (Stack && Peek_infix() != '(') 
                {
                   arr[j++] = Peek_infix(); // poping out every opeartor and storing them in Postfix Arr untill '(' comes
                   pop();
                }

            if (Stack && Peek_infix() == '(') pop(); // also poping out '(' from stack

            } else {

            if(Stack == nullptr)  push(array[i]); // if stack is empty , simply put in it

                else {
                    
            // if already opeartor is present in stack, pop out opeartors from it and store in arr
            // untill the precedence of opeartor going to be stored in stack is greater than from the top one from the stack
                    while (Stack && outprecidence(array[i])  <=  inprecidence(Peek_infix()) ) {
                        
                        arr[j++] = Peek_infix();
                        pop();

                    }
                            
                    push(array[i]);

                    }   
                } 
            i++;
        }
    }

    while (Stack){ //in last pop out every opeartor from stack and store them in Postfix arr
        arr[j++] = Peek_infix();
        pop();
    }

    arr[j] = '\0'; // in last of arr storing '\0' as a end point
}




int conversion::outprecidence(char Character)
{
    if (Character == '+' || Character == '-') return 1;
    else if (Character == '*' || Character == '/') return 3;
    else if (Character == '(') return 5;
    else return 0;   // ) -> operator precidence
}


int conversion::inprecidence(char Character)
{
    if (Character == '+' || Character == '-') return 2;
    else if (Character == '*' || Character == '/') return 4;
    else  return 0;   // ( -> operator precidence    
}



int conversion::peek_Eva()
{
    if(stack_Evaluation) return stack_Evaluation->value;
    else return 0;
}


int conversion::evaluation()
{
    int i = 0;
    int result = 0;
    int operand1,operand2;

    while (arr[i] != '\0')
    {
       if(Is_operand(arr[i])) 
       {
          int whole_number = 0;
          // converting whole individual number from char to int untill blank space comes 
          // because that is seperating numbers from each other
          while (Is_operand(arr[i]) && arr[i] != ' ')   whole_number = whole_number*10 + (arr[i++] - '0');
          push(whole_number); 

       } else {

          operand2 = peek_Eva();
          pop_Eva();
          operand1 = peek_Eva();
          pop_Eva();

          switch(arr[i])
          {
            case '+':
                    result = operand1 + operand2;
                    push(result);
                    break;
            case '-':
                    result = operand1 - operand2;
                    push(result);
                    break;
            case '*':
                    result = operand1 * operand2;
                    push(result);
                    break;
            case '/':
                    result = operand1 / operand2;
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


void conversion::display()
{
   
    cout << "Postfix Expression : " << endl;

    for(int i = 0; arr[i] != '\0'; i++) if(arr[i] != ' ') cout << arr[i];
        
    cout << endl;

}


int main()
{
    string expression;
    conversion obj;

    cout << "Enter Expression: ";
    getline(cin, expression);

    obj.convert_Expression(expression);
    obj.display();

    cout << "Postfix Evaluation : " ;
    cout << obj.evaluation() << endl;

    return 0;
}


