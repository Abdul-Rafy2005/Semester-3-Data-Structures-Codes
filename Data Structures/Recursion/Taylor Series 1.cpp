#include<iostream>
using namespace std;

int series(int x ,int n)
{
    static int pow = 1, factorial = 1;
    int sum;

    if(n == 0) return 1;

    sum = series(x,n-1);
    // doing all stuff at returning time
    pow  *= x; 
    factorial *= n;
    return sum + (pow/factorial); 
}

int main()
{
    int x,pow;

    cout << "Enter the value of x : ";
    cin >> x;

    cout << "Enter the power : ";
    cin >> pow;
    
    cout << "Sum of Taylar Series is :  "<< series (x,pow);

}