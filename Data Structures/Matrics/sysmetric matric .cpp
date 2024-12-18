


 // when (i,j) = (j,i);

#include<iostream> 
using namespace std;


class symetricTriangular
{
   int size;
   int *ptr;

   public:

   symetricTriangular(int Size) : size(Size) {
    // formular for storing only non zero elements from start to size
    ptr = new int [size*size]; 
   } 

   symetricTriangular(){
    delete [] ptr;
   } 

   void set(int i , int j, int x){
        
        if (i >= j) 
        ptr[i*(i - 1)/2 + j - 1] = x ;

   }

   void display(){

    for (int i = 1 ; i <= size ; i++){
        for (int j = 1 ; j <= size ; j++){
            if (i >= j) cout << ptr[i*(i - 1)/2 + j - 1] << " ";
            else cout << ptr[j*(j - 1)/2 + i - 1] << " ";
        }
         cout << "\n";
    }
    
   }


};

int main(){

    int dimension;
    cout << "Enter dimension : ";
    cin >> dimension;

    symetricTriangular object(dimension);

    int i,j,x;

    for (i = 1 ; i <= dimension ; i++){
        for (j =1 ; j <= dimension ; j++){
            if (i >= j ) {
                cout << "Enter value for index [" << i << "]["<<j<<"] : ";
                cin >> x;
                object.set(i,j,x);
            }
        }
    }

    object.display();

}