#include<iostream>
#include<queue>
using namespace std;

bool palindrome(queue<int>&list,int Current_size,int size)
{
    if(size == 0 || size == 1) return true;
    
    int top = list.front();
    list.pop();

    if (Current_size == size/2 + size % 2) return true;

    bool result = palindrome(list, Current_size - 1 , size);
    if(!result) return false; 


    if (list.front() != top) return false;
    list.pop();

    return true;
}

int main()
{
    queue<int>list;

    int i = 0;
    int val;

    do
    {
       cin >> val;
       list.push(val);
       i++;
        
    } while(i < 7);

    bool result = palindrome(list, list.size(), list.size());

    if(result) cout << "Palindrome. " << endl;
    else cout << "No . " << endl;
    
}

