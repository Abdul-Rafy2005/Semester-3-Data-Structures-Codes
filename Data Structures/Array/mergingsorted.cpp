
#include<iostream>
using namespace std;

void sort(int* &arr , int size)
{
    int temp;
    for(int i = 0 ; i < size - 1 ; i++)
    {
        for(int j = 0 ; j < size - 1 - i ; j++)
        {
            if(*(arr + j) > *(arr + j + 1))
            {
                temp = *(arr + j + 1);
                *(arr + j + 1) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

void merge(int* &merge_arr,int* arr1 ,int* arr2,int F_size, int size1,int size2)
{
    F_size = size1+size2;
}

void display(int* arr , int size)
{
    for(int i = 0; i < size ; i++) cout << *(arr + i) << " ";
    cout << endl;
}

int main()
{
    int size1, size2;

    cout << "Enter size of arr1 : ";
    cin >> size1;

    int *arr1 = new int[size1];

    cout << "Fill the arr1 : ";
    for(int i =0 ; i< size1;i++) cin >> *(arr1+i);

    cout << "Arr1 is : " << endl;
    display(arr1,size1);

    cout << "Enter size of arr2 : ";
    cin >> size2;

    int *arr2 = new int[size2];

    cout << "Fill the arr2 : ";
    for(int i = 0 ; i < size2 ; i++)   cin >> *(arr2+i);

    cout << "Arr2 is : " << endl;
    display(arr2,size2);

    sort(arr1,size1);
    sort(arr2,size2);
 
    int *merge_arr,F_size;

    merge(merge_arr,arr1 ,arr2,F_size,size1,size2);
    cout << "Merge combine sorted array is : ";
    display(merge_arr,F_size)
    delete [] arr1;
    delete [] arr2;
}