#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

class employee {
public:
    int employeeID;
    string name;
    double sales_score;
    double CS_score;
    double project_score;
    double overall_performance;

    void score_count() {  overall_performance = sales_score + CS_score + project_score; }
};

void swap(employee list[], int i, int j) 
{
    employee temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

void heapify(employee list[], int n) 
{
    for (int i = n / 2; i >= 1; i--) 
    {
        int parent = i;
        int child = 2 * i;

        while (child <= n-1) 
        {
            if (child < n-1 && list[child].overall_performance < list[child + 1].overall_performance) child++;
            
            if (list[parent].overall_performance < list[child].overall_performance) 
            {
                swap(list, parent, child);
                parent = child;
                child = 2 * parent;
            }
             else break;
        }
    }
}

employee Delete(employee list[], int& n) 
{
    employee top = list[1];
    list[1] = list[n--];
    heapify(list, n);
    return top;
}

void update_employee_score(employee list[], int list_size, int id, double new_sales, double new_CS, double new_project) 
{
    for (int i = 1; i <= list_size; i++) 
    {
        if (list[i].employeeID == id) 
        {
            list[i].sales_score = new_sales;
            list[i].CS_score = new_CS;
            list[i].project_score = new_project;

            list[i].score_count();
            heapify(list, list_size);

            cout << "Employee scores updated successfully.\n";
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}

void search_employee(employee list[], int list_size, int id) 
{
    for (int i = 1; i <= list_size; i++) 
    {
        if (list[i].employeeID == id) 
        {
            cout << "Employee Found:\n";
            cout << "Name: " << list[i].name << "\n";
            cout << "ID: " << list[i].employeeID << "\n";
            cout << "Sales Score: " << list[i].sales_score << "\n";
            cout << "CS Score: " << list[i].CS_score << "\n";
            cout << "Project Score: " << list[i].project_score << "\n";
            cout << "Overall Performance: " << list[i].overall_performance << "\n";
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}

int main() {
    employee list[MAX];
    int list_size = 0;
    int choice;

    do {
        cout << "Main Menu\n";
        cout << "1. Add Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Get Top-Ranking Employee\n";
        cout << "4. Update Employee Score\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            list_size++;
            cout << "Enter Employee name: ";
            cin.ignore();
            getline(cin, list[list_size].name);

            cout << "Enter Employee ID: ";
            cin >> list[list_size].employeeID;

            cout << "Enter Employee sales score %: ";
            cin >> list[list_size].sales_score;

            cout << "Enter Employee CS score %: ";
            cin >> list[list_size].CS_score;

            cout << "Enter Employee project score %: ";
            cin >> list[list_size].project_score;

            list[list_size].score_count();
            heapify(list, list_size);
            break;

        case 2: 
        {
            int id;
            cout << "Enter Employee ID to search: ";
            cin >> id;
            search_employee(list, list_size, id);
            break;
        }

        case 3:
            if (list_size == 0)   cout << "No employees available.\n";
            else 
            {
                employee top = Delete(list, list_size);
                cout << "Top Employee:\n";
                cout << "Name: " << top.name << "\n";
                cout << "ID: " << top.employeeID << "\n";
                cout << "Overall Performance: " << top.overall_performance << "\n";
            }
            break;

        case 4: 
        {
            int id;
            double new_sales, new_CS, new_project;
            cout << "Enter Employee ID to update: ";
            cin >> id;
            cout << "Enter new Sales Score: ";
            cin >> new_sales;
            cout << "Enter new CS Score: ";
            cin >> new_CS;
            cout << "Enter new Project Score: ";
            cin >> new_project;
            update_employee_score(list, list_size, id, new_sales, new_CS, new_project);
            break;
        }

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
        
        cout << "\n";
    } while (choice != 5);

    return 0;
}
