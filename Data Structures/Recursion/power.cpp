
#include<iostream>
using namespace std;

int power(int x,int n)
{
    if(n == 0) return 1;
    return power(x , n-1) * x;
}

int Power(int x,int n)
{
    if(n == 0) return 1;

    if(n % 2 == 0)
    {
        return Power(x*x,n/2);

    } else {
        
          return x * Power(x*x,(n-1)/2);
    }
}

int main()
{
    int pow,exp;

    cout << "Enter exponent : ";
    cin >> exp;

    cout << "Enter power : ";
    cin >> pow;

    cout << "Result of power() is : " << power(exp,pow) << endl;
    cout << "Result of Power() is :  " << Power(exp,pow) << endl;
    
}