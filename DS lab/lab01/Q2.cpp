#include<iostream>
using namespace std;

class Student{
    string name;
    int roll_number;
    char grade;

    public:
    
    Student();
    Student(string Name , int Roll, char Grade);
    void set_name(string Name);
    void set_roll(int Roll);
    void set_grade(char Grade);
    void UPdateGrade(char Grade);
    string get_name();
    int getRoll();
    char getGrade();  

};

Student::Student()
{
    name = " ";
    roll_number = 0;
    grade = 'f';
}

Student::Student(string Name, int Roll, char Grade)
{
    name = Name;
    roll_number = Roll;
    grade = Grade;
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

void Student::UPdateGrade(char Grade)
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


    string name;
    int roll_number;
    char grade;

    cout << "Enter student name :";
    cin >> name;


    cout << "Enter his/her roll number : ";
    cin >> roll_number;


    cout << "Enter his/her grade : ";
    cin >> grade;

    Student obj(name,roll_number,grade);

    cout <<  "\nStudent Information :"<< endl;
    cout  << "Studnet Name : " << obj.get_name() << endl; 
    cout  << "Roll number : " <<  obj.getRoll() << endl; 
    cout  << "Grade : " <<  obj.getGrade() << endl; 


    cout << "Enter new(updated) Grade : ";
    cin >> grade;

    obj.UPdateGrade(grade);
    cout << "\n Updated Student Information :"<< endl;
    cout  << "Studnet Name : " << obj.get_name() << endl; 
    cout  << "Roll number : " <<  obj.getRoll() << endl; 
    cout  << "Grade : " <<  obj.getGrade() << endl;

}


