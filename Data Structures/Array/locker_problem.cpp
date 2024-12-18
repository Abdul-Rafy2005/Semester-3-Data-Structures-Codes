#include<iostream>
using namespace std;


void calculate(int arr[])
{
    for (int i = 1; i < 20;i++)
    for (int j = 1; j < 20;j++)
    {
        if(i*j<20)
        {
           if(arr[i*j] = 1) arr[i*j] = 0;
           else arr[i*j] = 1;
        }
        j++;
    }
}
int main()
{
    int locker[20];
    for (int i = 0 ; i < 20;i++) locker[i] = 1;
    
    calculate(locker);

    for (int i = 0 ; i < 20;i++)
    {
        if(locker[i] == 1) cout << 1 << flush;
        else cout << 0<< flush;

    }

}