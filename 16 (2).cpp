// Q2. Create two base classes Learn_Info(Roll_No, Stud_Name, Class, Percentage) and
// Earn_Info(No_of_hours_worked, Charges_per_hour). Derive a class Earn_Learn_info from
// above two classes. Write necessary member functions to accept and display Student
// information. Calculate total money earned by the student. (Use constructor in derived class)
#include<iostream>
#include<string>
using namespace std;

class Learn_Info {
    protected:
        int rollNo;
        string studName, cls;
        float percentage;
    
    public:
        void acceptLearnInfo() {
            cout << "Enter roll number: ";
            cin >> rollNo;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, studName);
            cout << "Enter class: ";
            getline(cin, cls);
            cout << "Enter percentage: ";
            cin >> percentage;
        }
        
        void displayLearnInfo() {
            cout << "Roll number: " << rollNo << endl;
            cout << "Student name: " << studName << endl;
            cout << "Class: " << cls << endl;
            cout << "Percentage: " << percentage << "%" << endl;
        }
};

class Earn_Info {
    protected:
        int noOfHours;
        float chargesPerHour;
    
    public:
        void acceptEarnInfo() {
            cout << "Enter number of hours worked: ";
            cin >> noOfHours;
            cout << "Enter charges per hour: ";
            cin >> chargesPerHour;
        }
        
        void displayEarnInfo() {
            cout << "Number of hours worked: " << noOfHours << endl;
            cout << "Charges per hour: " << chargesPerHour << endl;
        }
        
        float calcMoneyEarned() {
            return noOfHours * chargesPerHour;
        }
};

class Earn_Learn_Info: public Learn_Info, public Earn_Info {
    private:
        float totalMoneyEarned;
    
    public:
        Earn_Learn_Info() {
            acceptLearnInfo();
            acceptEarnInfo();
            totalMoneyEarned = calcMoneyEarned();
        }
        
        void displayEarnLearnInfo() {
            displayLearnInfo();
            displayEarnInfo();
            cout << "Total money earned: " << totalMoneyEarned << endl;
        }
};

int main() {
    Earn_Learn_Info obj1;
    obj1.displayEarnLearnInfo();
    
    return 0;
}
