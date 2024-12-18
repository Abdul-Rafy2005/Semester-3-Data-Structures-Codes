

#include<iostream>
#include<stack>
using namespace std;

class node {

    public:
    char character;
    node * next;

    node(char Character) : character(Character), next(nullptr) {}

};

class conversion
{
    stack <char> Stack;
    char * Postfix_arr;

    public:
    conversion()
    {
        Postfix_arr = nullptr;
    }

    ~conversion()
    {
        delete [] Postfix_arr;
    }

    int Isoperand(char Character);
    int outprecidence(char Character);
    int inprecidence(char Character);  
    void convert(string array);  
    void display();
};


int conversion::Isoperand(char Character)
{
    if (Character == '+' || Character == '-' || Character == '*' || Character == '/' || Character == '^'|| Character == '(' || Character == ')') return 0;
    else return 1;
}


void conversion::convert(string expression)
{
    int size = expression.length() + 1; 

    Postfix_arr = new char[size];

    int i = 0,j = 0;

    while (expression[i] != '\0'){

        if(Isoperand(expression[i])){

            Postfix_arr[j++] = expression[i];
             
        } else {

            if (expression[i] == ')') 
            {

                while (Stack.empty() != true && Stack.top() != '(') 
                {
                    Postfix_arr[j++] = Stack.top();
                    Stack.pop();
                }

            if (Stack.empty() != true && Stack.top() == '(') Stack.pop();

            } else {

            if(Stack.empty())  Stack.push(expression[i]);

                else {
            
                    while (Stack.empty() != true && outprecidence(expression[i])  <=  inprecidence(Stack.top()) ) 
                    {                    
                        Postfix_arr[j++] = Stack.top();
                        Stack.pop();
                    }
                            
                    Stack.push(expression[i]);

                    }   
                } 
            }
            i++;
        }

    while (!Stack.empty()){
        Postfix_arr[j++] = Stack.top();
        Stack.pop();
    }

    Postfix_arr[j] = '\0';        
}


int conversion::outprecidence(char Character)
{
    if (Character == '+' || Character == '-') return 1;
    else if (Character == '*' || Character == '/') return 3;
    else if (Character == '^' ) return 6;
    else if (Character == '(') return 7;
    else {
             return 0;   // ) -> operator precidence
    }
}


int conversion::inprecidence(char Character)
{
    if (Character == '+' || Character == '-') return 2;
    else if (Character == '*' || Character == '/') return 4;
    else if (Character == '^' ) return 5;
    else {
             return 0;   // ( -> operator precidence
    }  
    
}

void conversion::display()
{
    int i = 0;
    while (Postfix_arr[i] != '\0') cout << Postfix_arr[i++];
    cout << endl;

}


int main()
{
   int test_case;
   cin >> test_case;
   string expression;
   conversion obj;

   while(test_case != 0)
   {
        cin >> expression;
        obj.convert(expression);
        obj.display();
        test_case--;

   }
}