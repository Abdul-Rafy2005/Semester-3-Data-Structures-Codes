#include <iostream>
using namespace std;

class node {
public:
    int coff;
    int expo;
    node* next;
};

class poly {
    node* head;
public:
    poly() {
        head = nullptr;
    }
    ~poly();
    void create(int size);
    void display();
    void sort_add(const poly& obj);
    int length();
};

poly::~poly() {
    node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void poly::create(int size) {
    node* temp = nullptr;

    for (int i = 1; i <= size; i++) {
        node* arr = new node;

        cout << "Enter the coefficient of " << i << " variable: ";
        cin >> arr->coff;

        cout << "Enter the exponent power of " << i << " variable: ";
        cin >> arr->expo;

        arr->next = nullptr;

        if (head == nullptr) {
            head = arr;
            temp = arr;
        } else {
            temp->next = arr;
            temp = arr;
        }
    }
}

int poly::length() {
    node* temp = head;
    int count = 0;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

void poly::display() {
    node* temp = head;
    while (temp) {
        cout << temp->coff << "x^" << temp->expo;
        if (temp->next != nullptr) cout << " + ";
        else cout << endl;
        temp = temp->next;
    }
}

void poly::sort_add(const poly& obj) {
    node* temp1 = head;
    node* temp2 = obj.head;
    node* third = nullptr;
    node* last = nullptr;

    while (temp1 != nullptr && temp2 != nullptr) {
        node* newNode = new node;
        if (temp1->expo == temp2->expo) {
            newNode->coff = temp1->coff + temp2->coff;
            newNode->expo = temp1->expo;
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->expo > temp2->expo) {
            newNode->coff = temp1->coff;
            newNode->expo = temp1->expo;
            temp1 = temp1->next;
        } else {
            newNode->coff = temp2->coff;
            newNode->expo = temp2->expo;
            temp2 = temp2->next;
        }
        newNode->next = nullptr;

        if (third == nullptr) {
            third = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    while (temp1 != nullptr) {
        node* newNode = new node;
        newNode->coff = temp1->coff;
        newNode->expo = temp1->expo;
        newNode->next = nullptr;
        if (third == nullptr) {
            third = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
        node* newNode = new node;
        newNode->coff = temp2->coff;
        newNode->expo = temp2->expo;
        newNode->next = nullptr;
        if (third == nullptr) {
            third = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        temp2 = temp2->next;
    }

    cout << "Sum Polynomial Expression: ";
    node* temp = third;
    while (temp) {
        cout << temp->coff << "x^" << temp->expo;
        if (temp->next != nullptr) cout << " + ";
        else cout << endl;
        temp = temp->next;
    }

    while (third) {
        node* temp = third;
        third = third->next;
        delete temp;
    }
}

int main() {
    int size;

    cout << "Enter size of 1st Polynomial Expression: ";
    cin >> size;
    poly Obj;
    Obj.create(size);
    cout << "first Expression.\n";
    Obj.display();


    cout << "Enter size of 2nd Polynomial Expression: ";
    cin >> size;
    poly Object;
    Object.create(size);
    cout << "Second Expression.\n";
    Object.display();


    Obj.sort_add(Object);

    return 0;
}
