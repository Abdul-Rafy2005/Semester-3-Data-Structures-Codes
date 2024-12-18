#include<iostream>
using namespace std;

class node {
    public:
        int value;
        int column;
        node* next;
};

class sparse_matrix {
    node **arr;  // Array of pointers to node
    int row, column;
    public:
        sparse_matrix() : arr(nullptr), row(0), column(0) {}
        ~sparse_matrix();
        void create();
        void display();
};

sparse_matrix::~sparse_matrix() {

    for (int i = 0; i < row; i++) {
        node* ptr = arr[i];
        while (ptr != nullptr) {
            node* temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
    }
    delete[] arr; // Delete the array of pointers
}

void sparse_matrix::create() {
    
    cout << "Enter the Dimension of Sparse Matrix: (row by column) ";
    cin >> row >> column;

    arr = new node*[row]; // Allocate array of pointers
    for (int i = 0; i < row; i++) {
        arr[i] = nullptr; // Initialize each row to nullptr
        node *last = nullptr;
        for (int j = 0; j < column; j++) {
            int value;
            cout << "Enter the value at Index [" << i << "][" << j << "]: ";
            cin >> value;
            if (value != 0) {
                node *temp = new node;
                temp->value = value;
                temp->column = j;
                temp->next = nullptr;
                if (arr[i] == nullptr) {
                    arr[i] = temp; // Set the head of the row
                } else {
                    last->next = temp;
                }
                last = temp;
            }
        }
    }
}

void sparse_matrix::display() {
    for (int i = 0; i < row; i++) {
        node* temp = arr[i];
        for (int j = 0; j < column; j++) {
            if (temp != nullptr && temp->column == j) {
                cout << temp->value << " ";
                temp = temp->next;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}



int main() {
    sparse_matrix obj;
    obj.create();
    obj.display();
    return 0;
}
