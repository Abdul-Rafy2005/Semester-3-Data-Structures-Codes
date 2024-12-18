#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
};

node *First = nullptr;

void create(int arr[], int size) {
    if (size <= 0) return; // Handle case where size is zero or negative

    First = new node;
    First->data = arr[0];
    First->next = nullptr;

    node *temp, *last;
    last = First;

    for (int i = 1; i < size; i++) { // Start from 1 since first node is already created
        temp = new node;
        temp->data = arr[i];
        temp->next = nullptr;

        last->next = temp;
        last = temp;
    }
}

int count(node *ptr) {
    int count = 0;
    while (ptr != nullptr) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void insert(int x, int position) {
    if (position < 0 || position > count(First)) return; // Handle out of bounds positions

    node *temp = new node;
    temp->data = x;

    if (position == 0) {
        temp->next = First;
        First = temp;
    } else {
        node *point = First;
        for (int i = 0; i < position - 1; i++) {
            point = point->next;
        }
        temp->next = point->next;
        point->next = temp;
    }
}

void display(node *nodes) {
    cout << "Linked list is: ";
    while (nodes != nullptr) {
        cout << nodes->data << " ";
        nodes = nodes->next;
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of Linked list: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size!" << endl;
        return 1; // Exit the program with an error code
    }

    int *arr = new int[size]; // Dynamically allocate array
    cout << "Enter its values: \n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    create(arr, size);
    display(First);

    // Example of inserting a new value
    int value, position;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Enter position to insert: ";
    cin >> position;
    insert(value, position);
    display(First);

    delete[] arr; // Free allocated memory

    // Optionally free the linked list nodes
    while (First != nullptr) {
        node *temp = First;
        First = First->next;
        delete temp;
    }

    return 0;
}
