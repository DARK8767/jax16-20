// Q1. Write a C++ program to display factors of a number.//not understand logic
#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Factors of " << num << " are: ";
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            cout << i << " "<<endl;
        }
    }

    return 0;
}
