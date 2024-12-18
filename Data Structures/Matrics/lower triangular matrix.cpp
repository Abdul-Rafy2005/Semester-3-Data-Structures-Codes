#include<iostream>
using namespace std;

 class LowerTriangular
{
   int size;
   int *ptr;

   public:

   LowerTriangular(int Size) : size(Size) {
    // formular for storing only non zero elements from start to size
    ptr = new int [size*(size + 1)/2]; 
   } 

   ~LowerTriangular(){
    delete [] ptr;
   } 

   void set(int i , int j, int x){
        
        if (i >= j) 
        ptr[i*(i - 1)/2 + j - 1] = x ;

   }

   int get(int i , int j ){
    return ptr[i*(i - 1)/2 + j - 1] ;
   }

   void display(){

    for (int i = 1 ; i <= size ; i++){
        for (int j = 1 ; j <= size ; j++){
            if (i >= j) cout << get(i,j) << " ";
            else cout << "0 ";
        }
         cout << "\n";
    }
    
   }


};


int main(){
    
    int dimension;
    cout << "Enter dimension : ";
    cin >> dimension;

    LowerTriangular object(dimension);

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

    cout << object.get(2,1);
}