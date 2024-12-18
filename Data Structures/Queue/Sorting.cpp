
#include <iostream>
#include <queue>
using namespace std;


void insert_sort(queue<int>& list, int val) 
{
    queue<int> temp;

    while (!list.empty() && val > list.front()) 
    {
        temp.push(list.front());
        list.pop();
    }

    temp.push(val);

    while (!list.empty()) 
    {
        temp.push(list.front());
        list.pop();
    }

    list = temp;
}


void sort(queue<int>& list) 
{
 
    if (list.empty() || list.size() == 1) 
        return; 

    int top = list.front();
    list.pop();

    sort(list);
    insert_sort(list, top);
}

int main() 
{
    queue<int> list;

    list.push(2);
    list.push(5);
    list.push(3);
    list.push(7);
    list.push(1);


    sort(list);

    while (!list.empty()) 
    {
        cout << list.front() << " ";
        list.pop();
    }

    return 0;
}
