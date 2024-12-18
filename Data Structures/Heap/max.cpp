#include<iostream>
using namespace std;

void swap(int arr[],int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int arr[],int n)
{
    int j;
    for(int i = (n/2) ; i >= 1 ; i--)
    {
        j = i*2;
        while(j <= n - 1)
        {
            if(j < n - 1 && arr[j] < arr[j+1])  j += 1;
            if(arr[i] < arr[j])
            {
                swap(arr,i,j);
                i = j;
                j = i*2;
            }
            else break;
        }
    } 
}

int Delete(int arr[],int n)
{
    int x = arr[1];
    int i = 1;
    int j = i*2;
    
    while(j < n - 1)
    {
        if(j < n - 2 && arr[j] < arr[j+1])  j += 1;
        if(arr[i] < arr[j])
        {
            swap(arr,i,j);
            i = j;
            j = i*2;
        }
        else break;
    }
    return x;
}

void print(int arr[],int n)
{
    for(int i = 1; i < n ; i++)
    {
        cout << arr[i];
        if(i != n-1) cout << ",";
    }
    cout << endl;
}

int main()
{
    int arr[] = {0,4,2,5,7,3,8,9,1,6};
    cout << "Original Heap: ";    
    print(arr,sizeof(arr)/sizeof(arr[0]));

    heapify(arr,sizeof(arr)/sizeof(arr[0]));
    cout << "Modiified Heap: ";
    print(arr,sizeof(arr)/sizeof(arr[0]));
}