#include<iostream>
using namespace std;

class Teacher{
    protected : 
    string name;
    string subject;
    int experience;

    public :
    Teacher()
    {
       name = "N/A";
       subject = "N/A";
       experience = 0;
    }

    void set_name(string Name)
    {
        name = Name;
    }
    void set_subject(string Subject)
    {
       subject = Subject;
    }
    void set_experience(int Experience)
    {
        experience = Experience;
    }

    string get_name()
    {
        return name;
    }
    string getsubject()
    {
        return subject;
    }

    int getExpereince()
    {
        return experience;
    }        

};

class Principal : public Teacher {

    int yearsAsPrincipal;

    public :
    
    Principal(){
        yearsAsPrincipal = 0;
    }

    void set_yearsAsPrincipal(int years)
    {
         yearsAsPrincipal = years;
    }

    int get_yearsAsPrincipal()
    {
        return yearsAsPrincipal;
    }

};


int main()
{
    
    string name;
    string subject;
    int experience;
    int yearsAsPrincipal;

    cout << "Enter teacher name : ";
    cin >> name;

    cout << "Enter teacher's subject name : ";
    cin >> subject; 

    cout << "Enter teacher's experience : ";
    cin >> experience;  

    cout << "Enter Number of years as principal  : ";
    cin >> yearsAsPrincipal; 

    Principal obj;
    obj.set_name(name);
    obj.set_subject(subject);
    obj.set_experience(experience); 
    obj.set_yearsAsPrincipal(yearsAsPrincipal);
    
    cout << "Teacher Information :"<< endl;
    cout  << "teacher Name : " << obj.get_name() << endl; 
    cout  << "his/her Subject: " <<  obj.getsubject() << endl; 
    cout  << "His experience  : " <<  obj.getExpereince() << endl;    
    cout  << "His principal experience  : " <<  obj.get_yearsAsPrincipal() << endl;  
}


