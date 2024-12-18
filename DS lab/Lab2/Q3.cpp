
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void assigning_temp(int** & month)
{
    for (int i = 0; i < 4 ; i++)
    {
        for(int j = 0 ; j < 7 ; j++)
        {
            month[i][j] = rand() % (30 - 10 + 1 ) + 10;
        }
    }
}

void display(int** month)
{
    cout << "Temperature of the week. "<< endl;

    for (int i = 0; i < 4 ; i++)
    {
        for(int j = 0 ; j < 7 ; j++)
        {
            cout << month[i][j] << " ";
        }
        cout  << endl;
    }
}    


void hottest_day(int** month)
{
    string days[7] = 
    {
        "Mnnday",
        "Tuesday"
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };
    
    int temp = 0;
    int hot_day = 0;


    for (int i= 0 ; i < 4 ; i++ )
    {
        temp = month[i][0];

        for(int j = 0; j < 7 ; j++)
        {
           if (temp < month[i][j] ) 
           {
            temp = month[i][j];
            hot_day = j;
           }
        }
        cout << "Hottest day of week: " << i + 1 << " is : " << days[hot_day] << " having a temperature is : " << temp << endl;

    }
     
}



int main()
{
    srand(time(0));
    int ** month = new int *[4];

    for (int i =0 ; i < 4 ; i++)  month[i] = new int [7];
    
    assigning_temp(month);

    display(month);
    hottest_day(month);


    for (int i =0 ; i < 4 ; i++)
    {
        delete [] month[i];
    }

    delete [] month;
    month = nullptr;
}
