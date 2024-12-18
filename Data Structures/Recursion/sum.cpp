
#include<iostream>
using namespace std;

int sum(int x)
{
    if(x == 0) return 0;
    return sum(x-1) + x;

}

int main()
{
    int number;

    cout << "Enter the n Natural Number : ";
    cin >> number;

    cout << "Sum of N natural number is : " << sum(number)<<endl;
}