
#include<iostream>
#include<string>
using namespace std;

class student
{
    string name;
    int age;

    public :
    
    student()
    {
        name = "N/A";
        age = 0;
    }

    void Set_name(string name)
    {
        this->name = name;
    }

    void Set_age(int age)
    {
        this->age = age;
    }

    int Get_age()
    {
        return age;
    }

    string Get_name()
    {
        return name;
    }   

};

int main()
{
    int size;

    cout << "Enter number of Students : ";
    cin >> size;

    cin.ignore();

    student * arr = new student [size];

    cout << "Enter the Name And Age of Students : " << endl;
  
    int age;
    string name;

    for (int i = 0 ; i < size ; i++)
    {
        getline(cin ,name);
        arr[i].Set_name(name);

        cin >> age;
        arr[i].Set_age(age);

        cin.ignore();
    }

    cout << "Students Information : " << endl;

    for (int i = 0 ; i < size ; i++)
    {
        cout << arr[i].Get_name() << endl;
        cout <<  arr[i].Get_age() << endl;
        cout << endl;
    }   

    delete [] arr; 
}