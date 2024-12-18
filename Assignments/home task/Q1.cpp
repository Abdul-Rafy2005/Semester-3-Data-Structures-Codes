#include<iostream>
#include<string>
using namespace std;

class node { 
public:
    char character;
    node* next;

    node(char Character) : character(Character), next(nullptr) {}
};

class Node {
public:
    int value;
    Node* next;

    Node(int Value) : value(Value), next(nullptr) {}
};

class conversion {
    node* Stack;
    char* arr;
    Node* stack_Evaluation;

public:
    conversion() {
        Stack = nullptr;
        arr = nullptr;
        stack_Evaluation = nullptr;
    }

    ~conversion() {
        delete[] arr;
    }

    void push(int value);
    void push(char Character);
    void pop();
    void pop_Eva();
    void convert_Expression(string array);
    char Peek_infix();
    int peek_Eva();
    int Is_operand(char Character);
    int outprecidence(char Character);
    int inprecidence(char Character);
    void display();
    int evaluation();
};

void conversion::push(char Character) {
    node* temp = new node(Character);
    temp->next = Stack;
    Stack = temp;
}

void conversion::pop() {
    if (Stack) {
        node* temp = Stack;
        Stack = Stack->next;
        delete temp;
    }
}

void conversion::push(int value) {
    Node* temp = new Node(value);
    temp->next = stack_Evaluation;
    stack_Evaluation = temp;
}

void conversion::pop_Eva() {
    if (stack_Evaluation) {
        Node* temp = stack_Evaluation;
        stack_Evaluation = stack_Evaluation->next;
        delete temp;
    }
}

int conversion::Is_operand(char Character) {
    return (Character >= '0' && Character <= '9') ? 1 : 0; // Check if it's a digit (operand)
}

char conversion::Peek_infix() {
    return Stack ? Stack->character : '\0';
}

void conversion::convert_Expression(string array) {
    int size = array.length() + 1;
    arr = new char[size];
    int i = 0, j = 0;

    while (array[i] != '\0') {
        if (Is_operand(array[i])) { // If it's an operand
            while (Is_operand(array[i])) {
                arr[j++] = array[i++];
            }
            arr[j++] = ' '; // Add space to separate numbers
        } else {
            if (array[i] == ')') {
                while (Stack && Peek_infix() != '(') {
                    arr[j++] = Peek_infix();
                    pop();
                }
                if (Stack && Peek_infix() == '(') pop();
            } else {
                if (Stack == nullptr) {
                    push(array[i]);
                } else {
                    while (Stack && outprecidence(array[i]) <= inprecidence(Peek_infix())) {
                        arr[j++] = Peek_infix();
                        pop();
                    }
                    push(array[i]);
                }
            }
            i++;
        }
    }

    while (Stack) {
        arr[j++] = Peek_infix();
        pop();
    }

    arr[j] = '\0'; // Null-terminate the string
}

int conversion::outprecidence(char Character) {
    if (Character == '+' || Character == '-') return 1;
    else if (Character == '*' || Character == '/') return 3;
    else if (Character == '(') return 5;
    else return 0; // ) -> operator precedence
}

int conversion::inprecidence(char Character) {
    if (Character == '+' || Character == '-') return 2;
    else if (Character == '*' || Character == '/') return 4;
    else return 0; // ( -> operator precedence    
}

int conversion::peek_Eva() {
    return stack_Evaluation ? stack_Evaluation->value : 0;
}

int conversion::evaluation() 
{

    int i = 0;
    int result = 0;
    int operand1, operand2;

    while (arr[i] != '\0') 
    {
        if (Is_operand(arr[i])) 
        {
            int whole_number = 0;
            while (Is_operand(arr[i]) && arr[i] != ' ')   whole_number = whole_number*10 + (arr[i++] - '0');
            push(whole_number); 

        } else { 

            operand2 = peek_Eva();
            pop_Eva();
            operand1 = peek_Eva();
            pop_Eva();

            switch (arr[i]) 
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            push(result); // Push the result of the operation
        }
        i++;
    }

    result = peek_Eva();
    pop(); 
    return result;
}

void conversion::display() {
    int i = 0;
    cout << "PostFix Expression: ";
    while (arr[i] != '\0')
    {
        if(arr[i] != ' ') cout << arr[i];
        i++;
    }
    cout << endl;
}

int main() {

    conversion obj;
    string expression;

    cout << "Enter Expression: ";
    getline(cin, expression);

    obj.convert_Expression(expression);
    obj.display();

    cout << "Postfix Evaluation: ";
    cout << obj.evaluation() << endl;

    return 0;
}
