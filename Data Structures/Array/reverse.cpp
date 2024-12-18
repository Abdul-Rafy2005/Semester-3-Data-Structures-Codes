
#include<iostream>
using namespace std;

void reverse(int* & arr,int size)
{
    int temp;

    for (int i = 0 ; i < size/2.0 ; i++)
    {
        temp = *(arr + i);
        *(arr + i) = *(arr + size - 1 - i);
        *(arr + size - 1 - i) = temp;
    }

}

void display(int*  arr,int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        cout << *(arr + i) << endl;
    }
}

int main()
{
    int arr_size;
    
    cout << "Enter size of array : " ; 
    cin >> arr_size;

    int *array = new int [arr_size];

    for (int  i = 0; i < arr_size; i++)
    {
        cin >> *(array + i);
    }
    
    reverse(array,arr_size);
    display(array,arr_size);
}