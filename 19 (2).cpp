// Q2. Design a two base classes Employee (Name, Designation) and Project(Project_Id, title).
// Derive a class Emp_Proj(Duration) from Employee and Project. Write a menu driven
// program to
// a. Build a master table.
// b. Display a master table
// c. Display Project details in the ascending order of duration.
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Employee {
protected:
    string name;
    string designation;
public:
    Employee() {}
    Employee(string n, string d) {
        name = n;
        designation = d;
    }
    void input() {
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee Designation: ";
        cin >> designation;
    }
    void display() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee Designation: " << designation << endl;
    }
};

class Project {
protected:
    int project_id;
    string title;
public:
    Project() {}
    Project(int id, string t) {
        project_id = id;
        title = t;
    }
    void input() {
        cout << "Enter Project ID: ";
        cin >> project_id;
        cout << "Enter Project Title: ";
        cin >> title;
    }
    void display() {
        cout << "Project ID: " << project_id << endl;
        cout << "Project Title: " << title << endl;
    }
};

class Emp_Proj : public Employee, public Project {
private:
    int duration;
public:
    Emp_Proj() {}
    Emp_Proj(string n, string d, int id, string t, int dur) : Employee(n, d), Project(id, t) {
        duration = dur;
    }
    void input() {
        Employee::input();
        Project::input();
        cout << "Enter Project Duration: ";
        cin >> duration;
    }
    void display() {
        Employee::display();
        Project::display();
        cout << "Project Duration: " << duration << endl;
    }
    int get_duration() {
        return duration;
    }
};

bool compare_duration(Emp_Proj *a, Emp_Proj *b) {
    return a->get_duration() < b->get_duration();
}

int main() {
    Emp_Proj *emp_proj[100];
    int n = 0;

    while (true) {
        cout << endl << "1. Add Employee/Project" << endl;
        cout << "2. Display All" << endl;
        cout << "3. Display Project Details (Ascending Order of Duration)" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                emp_proj[n] = new Emp_Proj();
                emp_proj[n]->input();
                n++;
                break;
            }
            case 2: {
                for (int i = 0; i < n; i++) {
                    emp_proj[i]->display();
                }
                break;
            }
            case 3: {
                sort(emp_proj, emp_proj + n, compare_duration);
                for (int i = 0; i < n; i++) {
                    emp_proj[i]->display();
                }
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                cout << "Invalid Choice!" << endl;
            }
        }
    }

    return 0;
}
