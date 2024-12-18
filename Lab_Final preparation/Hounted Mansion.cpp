#include <bits/stdc++.h>
#include<queue>
#include<stack>
using namespace std;

void explore( queue<string> places,stack<string> ghosts)
{
    int choice;
    string ghost;
    cout << "Wanna start Exploration" << endl;
    cout << "1.Yes" << endl;
    cout << "0.NO" << endl;
    cin >> choice;
    if(choice == 0)
    {
        cout << "Successfully End" << endl;
        return;
    }

    while(!places.empty())
    {
        cout << "Currently at : "<< places.front() << endl;

        cout << "Did you encountered a ghost or an evil spirit" << endl;
        cout << "1.Yes" << endl;
        cout << "0.NO" << endl;
        cin >> choice; 
        if(choice == 1)
        {
            cout << "What did you see ?" << endl;
            cin.ignore();
            getline(cin,ghost);

            ghosts.push(places.front());
            ghosts.push(ghost);
            places.pop();
        }  
        places.pop();     
    }
    cout << "You left safe and sound!" << endl;
    cout << "Most recent ghosts or evil spirit encountered" << endl;
    while(!ghosts.empty())
    {
        cout << ghosts.top() << " at : ";
        ghosts.pop();
        cout << ghosts.top() << endl;
        ghosts.pop();
    }
}

int main()
{
    stack<string> ghosts;
    queue<string> places;
    places.push("The Gateway to Darkness");
    places.push("The Creeping Corrider");
    places.push("The abandoned lounge");
    places.push("The hounted gallery");
    places.push("The shadowed library");
    places.push("The broken window");

    
    explore(places,ghosts);

    
}