// Q2.Write a C++ program to read student information such as rollno, name and percentage of n
// students. Write the student information using file handling
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int roll_no;
    string name;
    float percentage;
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the information for student " << i+1 << ":\n";
        cout << "Roll No: ";
        cin >> students[i].roll_no;
        cout << "Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Percentage: ";
        cin >> students[i].percentage;
    }

    ofstream file("students.txt");

    for (int i = 0; i < n; i++) {
        file << "Roll No: " << students[i].roll_no << endl;
        file << "Name: " << students[i].name << endl;
        file << "Percentage: " << students[i].percentage << "%" << endl << endl;
    }

    file.close();

    cout << "Student information written to file successfully.\n";

    return 0;
}
