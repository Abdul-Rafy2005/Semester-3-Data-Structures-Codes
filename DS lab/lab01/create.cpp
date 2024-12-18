#include<iostream>
using namespace std;

class Student{
    string name;
    int roll_number;
    char grade;

    public:
    
    Student();
    void set_name(string Name);
    void set_roll(int Roll);
    void set_grade(char Grade);
    string get_name();
    int getRoll();
    char getGrade();        
};

Student::Student()
{
    name = "N/A";
    roll_number = 0;
    grade = 'f';
}

void Student::set_name(string Name)
{
     name = Name;
}

void Student::set_roll(int Roll)
{ 
     roll_number = Roll;
}

void Student::set_grade(char Grade)
{
    grade = Grade;
}

string Student::get_name()
{
    return name;
}

int Student::getRoll()
{
    return roll_number;
}

char Student::getGrade()
{
    return grade;
}

int main()
{
    Student obj;

    string name;
    int roll_number;
    char grade;

    cout << "Enter student name :";
    cin >> name;


    cout << "Enter his/her roll number : ";
    cin >> roll_number;


    cout << "Enter his/her grade : ";
    cin >> grade;

    obj.set_name(name);
    obj.set_roll(roll_number);
    obj.set_grade(grade);

    cout << "Student Information :"<< endl;
    cout  << "Studnet Name : " << obj.get_name() << endl; 
    cout  << "Roll number : " <<  obj.getRoll() << endl; 
    cout  << "Grade : " <<  obj.getGrade() << endl; 
}