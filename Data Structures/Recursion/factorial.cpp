
#include<iostream>
using namespace std;

int factorial(int x)
{
    if (x == 0) return 1;
    return  x * factorial(x-1);
}

int main(){

    int x;

    cout << "Enter the number  : ";
    cin >> x;

    cout << "Factorial of N number is  : " << factorial(x)<<endl;
}