// or Q2. Write a C++ program to create a text file which stores employee information as emp_id,
// emp_name, emp_sal). Write a menu driven program with the options
// a. Append
// b. Modify
// c. Display
// d. Exit
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee {
    int emp_id;
    string emp_name;
    double emp_sal;
};

void appendEmployee(fstream& file) {
    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.emp_id;
    cout << "Enter Employee Name: ";
    cin >> emp.emp_name;
    cout << "Enter Employee Salary: ";
    cin >> emp.emp_sal;

    file.write((char*)&emp, sizeof(Employee));
    cout << "Employee Added Successfully!" << endl;
}

void modifyEmployee(fstream& file) {
    int emp_id;
    cout << "Enter Employee ID to Modify: ";
    cin >> emp_id;

    Employee emp;
    bool found = false;

    file.seekg(0, ios::beg);
    while (file.read((char*)&emp, sizeof(Employee))) {
        if (emp.emp_id == emp_id) {
            cout << "Enter New Employee Name: ";
            cin >> emp.emp_name;
            cout << "Enter New Employee Salary: ";
            cin >> emp.emp_sal;

            file.seekp(-sizeof(Employee), ios::cur);
            file.write((char*)&emp, sizeof(Employee));
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Employee Modified Successfully!" << endl;
    } else {
        cout << "Employee Not Found!" << endl;
    }
}

void displayEmployees(fstream& file) {
    Employee emp;
    cout << "Employee ID\tEmployee Name\tEmployee Salary" << endl;
    cout << "------------------------------------------------" << endl;

    file.seekg(0, ios::beg);
    while (file.read((char*)&emp, sizeof(Employee))) {
        cout << emp.emp_id << "\t\t" << emp.emp_name << "\t\t" << emp.emp_sal << endl;
    }
}

int main() {
    fstream file("employees.txt", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "File Creation Error!" << endl;
        return 0;
    }

    while (true) {
        cout << endl << "1. Append Employee" << endl;
        cout << "2. Modify Employee" << endl;
        cout << "3. Display Employees" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                appendEmployee(file);
                break;
            }
            case 2: {
                modifyEmployee(file);
                break;
            }
            case 3: {
                displayEmployees(file);
                break;
            }
            case 4: {
                file.close();
                exit(0);
            }
            default: {
                cout << "Invalid Choice!" << endl;
            }
        }
    }

    return 0;
}
