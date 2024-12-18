#include<iostream>
using namespace std;

bool check_palindrome(string* ptr, int size) {

    for (int i = 0; i < size / 2; i++) {

        if ((*ptr)[i] != (*ptr)[size - i - 1]) return false;

    }
    return true;
}

int frequency(char character, string* ptr, int size) { 

    int count = 0;

    for (int i = 0; i < size; i++) {

        if (character == (*ptr)[i]) count++;
    }

    return count;
}

int main() {

    string* name = new string(); 
    
    cout << "Enter your name: ";
    cin >> *name;

    int length = name->length();

    bool check = check_palindrome(name, length);

    if (check)   cout << "Your name is a palindrome." << endl;

    else  cout << "Your name is not a palindrome." << endl;
    

    char character;

    cout << "Enter character to check its frequency: ";
    cin >> character;

    int count = frequency(character, name, length);
    
    cout << character << " found " << count << " times." << endl;

    delete name; 
}
