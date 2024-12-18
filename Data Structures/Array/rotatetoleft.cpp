
#include<iostream>
using namespace std;

void rotate(int* & arr, int size,int k)
{
    if (k < 0 || k >= size)
        cout << "incorrect position. " << endl; 

    int temp;
    for(int i = 0 ; i < k ; i++)
    {
        temp = *arr;
        for(int j = 0; j < size - 1; j++)
        {
            *(arr + j) = *(arr + j + 1);
        }
        *(arr + size - 1) = temp;
    }
 }

void display(int*  arr,int size)
{
    cout << "List is : ";
    for (int i = 0 ; i < size ; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
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
    
    display(array,arr_size);

    int k;

    cout << "Enter position to rotate : ";
    cin >> k;

    rotate(array,arr_size,k);
    display(array,arr_size);
   

}