
#include<iostream>
#include<queue>
using namespace std;

void reverse(queue<int>& list)
{
    if((list.empty())) return;

    int val = list.front();
    list.pop();

    reverse(list);

    list.push(val);
}

int main()
{
    queue<int>list;

    int i = 0,val;
    
    do
    {
        cin >> val;
        list.push(val);
        i++;

    } while (i < 5);

    reverse(list);

    while(!list.empty())
    {
        cout << list.front(); << " ";
        list.pop();
    }
    
}