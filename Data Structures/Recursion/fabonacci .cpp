
#include<iostream>
using namespace std;

int * arr;
int series_itear(int n)
{

    if(n <= 1) return n;

    int t_0 = 0;
    int t_1 = 1;
    int sum = 0;

    for(int i = 2; i <= n;i++)
    {
        sum = t_0 + t_1;
        t_0 = t_1;
        t_1 = sum;
    }

    return sum;

}

int series_recursive(int n)   // time complexity of order(2^n) 
{
    if(n <= 1) return n;
    return series_recursive(n-2) + series_recursive(n-1);
}

int series_Recursive(int n)   // time complexity of order(n) 
{
    if(n < 0 ) return -1;
    if(n <= 1) 
    {
     arr[n] = n;
     return n;
    }
    else
    {
        if(arr[n-2] != -1) series_Recursive(n-2);
        if(arr[n-1] != -1) series_Recursive(n-1);
        return series_Recursive(n-2) + series_Recursive(n-1);
    }
}

int main()
{
    int n;
    cout << "Enter the end limit for series : ";
    cin >> n;
    arr = new int[n];
    int i= 0;
    while (i<=n)
    {
        arr[i++] = -1;
    }

    cout << "Sum of Fabonacci seris is at "<< n << " term is: " << series_Recursive(n); 
    delete [] arr;   
}