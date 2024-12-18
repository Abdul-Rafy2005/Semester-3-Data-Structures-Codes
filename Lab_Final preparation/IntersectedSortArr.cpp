
#include<bits/stdc++.h>
using namespace std;

void sort(int* &arr, int size)
{
    int temp;
    for(int i = 0 ; i < size - 1 ; i++)
        for(int j = 0 ; j < size - 1 - i ; j++)
            if(*(arr + j) <= *(arr + j + 1))
            {
                temp = *(arr + j + 1);
                *(arr + j + 1) = *(arr + j);
                *(arr + j) = temp;
            }
}

int* SortedIntersect(int* arr1, int* arr2,int size , int& newsize)
{

    for(int i = 0; i < size ; i++)
    {
        for(int j = 0; j < size ; j++)
        {
            if(*(arr1+i) == *(arr2 + j))
            {
                newsize++;
                break;
            }
        }   
    }

    int* NewArr = new int[newsize];
    int k = 0;

    for(int i = 0; i < size ; i++)
    {
        for(int j = 0; j < size ; j++)
        {
            if(*(arr1+i) == *(arr2 + j))
            {
                NewArr[k++] = *(arr1+i);
                sort(NewArr,k);
                break;
            }
        }  
    }      
    return NewArr;
}



void display(int *arr,int size)
{
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " "; 
    cout << endl;    
}

int main()
{
    int size = 6;
    int *arr1 = new int[size];
    int *arr2 = new int[size];

    cout << "Enter values for arr1: " << endl;
    for (int i = 0; i < size; i++)
        cin >> *(arr1 + i);  

    cout << "Enter values for arr2: " << endl;
    for (int i = 0; i < size; i++)
        cin >> *(arr2 + i); 

    cout << "arr1: ";
    display(arr1,size);
    cout << "arr2: ";
    display(arr2,size);

    int newsize = 0;
    int* finalArr = SortedIntersect(arr1,arr2,size,newsize);

    cout << "Sorted-Intersect array : ";
    for(int i = 0 ; i < newsize  ; i++)
        cout << finalArr[i] << " ";
 
    delete [] arr1;
    delete [] arr2;

    return 0;
}
