#include<bits/stdc++.h>
using namespace std;

void series(int number1, int number2, int number3,int n)
{
    if (n == 0) return;
    int number = number1 + number2 + number3;
    cout << number << " ";
    series(number2,number3,number,n-1);
}

int main()
{
    int n = 6;
    cout << 9 << " " << 6 << " " << 3 << " "; 
    series(9,6,3,n-3);
    return 0;
}