
#include<iostream>
using namespace std;

int main()
{
   int m,n;

   cout << "Enter size of rows : ";
   cin >> m;

   cout << "Enter size of columns : ";
   cin >> n;   
    
   int ** arr_2D = new (nothrow) int*[m];

       if(arr_2D == nullptr)
       {
          cout << "Heap is full. " << endl;
          return 1;
       }
     

   for (int i = 0 ; i < m ; i++)
   {
      arr_2D[i] = new int[n];

       if(arr_2D[i] == nullptr)
       {
          cout << "Memory for coulum " << i << "not allocated" << endl;
       } 
          
   }

   cout << "Fill the arr : " << endl;

   for (int i = 0 ; i < m ; i++)
   {
    for(int j = 0 ; j < n ; j++)
    {
        if(arr_2D[i] != nullptr)
        {
             cin >> arr_2D[i][j];
        }
    }
   }

   for (int i = 0 ; i < m ; i++)
   {
    for(int j = 0 ; j < n ; j++)
    {
        if(arr_2D[i] != nullptr)
        {
            cout  << arr_2D[i][j] << " ";
        }
   }
       cout << endl;

   }

   for (int i = 0 ; i < m ; i++)
   {
        if(arr_2D[i] != nullptr)
        delete [] arr_2D[i];
   }

   delete [] arr_2D;
   arr_2D = nullptr;
}