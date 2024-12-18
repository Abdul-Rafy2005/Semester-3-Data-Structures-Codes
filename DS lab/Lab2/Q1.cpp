#include<iostream>
using namespace std;

void swap(int* &a , int* &b )
{
    int temp = *a;
    *a = *b;
    *b = temp;

}

int main()
{
   int A,B;
   int* ptr1;
   int *ptr2;



   cout << "Enter value of A : ";
   cin >> A;

   cout  << "Enter new value of B : ";
   cin >> B;

   
   ptr1= &A;
   ptr2 = &B;

   cout << "value before swaping \nA = " << *ptr1 << "\nB = " << *ptr2 << endl;
   swap(ptr1,ptr2);
   cout << "value After swaping \nA = " << *ptr1 << "\nB = " << *ptr2 << endl;

}