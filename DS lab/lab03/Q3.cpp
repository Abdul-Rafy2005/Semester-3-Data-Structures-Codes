
#include<iostream>
using namespace std;

int main()
{
   int m,n;

   cout << "Enter size of rows : ";
   cin >> m;

   cout << "Enter size of columns : ";
   cin >> n;   
    
   int ** arr_2D = new int*[m];

   for (int i = 0 ; i < m ; i++)
   {
      arr_2D[i] = new int[n];
   }

   cout << "Fill the arr : " << endl;

   for (int i = 0 ; i < m ; i++)
   {
    for(int j = 0 ; j < n ; j++)
    {
        cin >> arr_2D[i][j];
    }
   }

   for (int i = 0 ; i < m ; i++)
   {
    for(int j = 0 ; j < n ; j++)
    {
        cout <<  arr_2D[i][j];
   }
       cout << endl;

   }

   for (int i = 0 ; i < m ; i++)
   {
        delete [] arr_2D[i];
   }

   delete [] arr_2D;
   arr_2D = nullptr;
}