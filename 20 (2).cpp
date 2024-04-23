// Q2. Write a C++ program to create a class Department which contains data members as
// Dept_Id, Dept_Name, H.O.D., Number_Of_staff. Write necessary member functions to
// a. Accept details from user for ‘n’ departments and write it in a file “Dept.txt”.
// b. Display details of department from a file.
#include <iostream>
#include <fstream>
using namespace std;

class Department {
private:
    int Dept_Id;
    string Dept_Name;
    string HOD;
    int Number_Of_Staff;

public:
    void acceptDetails() {
        cout << "Enter Department ID: ";
        cin >> Dept_Id;
        cout << "Enter Department Name: ";
        cin >> Dept_Name;
        cout << "Enter HOD Name: ";
        cin >> HOD;
        cout << "Enter Number of Staff: ";
        cin >> Number_Of_Staff;
    }

    void writeToFile() {
        ofstream fout;
        fout.open("Dept.txt", ios::app);
        fout << Dept_Id << " " << Dept_Name << " " << HOD << " " << Number_Of_Staff << endl;
        fout.close();
    }

    void displayDetails() {
        ifstream fin;
        fin.open("Dept.txt");
        int id, staff;
        string name, hod;
        cout << "Department Details: " << endl;
        while (fin >> id >> name >> hod >> staff) {
            cout << "Department ID: " << id << endl;
            cout << "Department Name: " << name << endl;
            cout << "HOD Name: " << hod << endl;
            cout << "Number of Staff: " << staff << endl;
            cout << endl;
        }
        fin.close();
    }
};

int main() {
    int n;
    cout << "Enter the number of departments: ";
    cin >> n;

    Department dept;
    for (int i = 1; i <= n; i++) {
        cout << "Enter Details for Department " << i << endl;
        dept.acceptDetails();
        dept.writeToFile();
    }

    dept.displayDetails();

    return 0;
}
