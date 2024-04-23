// Q2. Create a class Fraction containing data members as Numerator and Denominator.
// Write a program to overload operators ++ , -- and * to increment, decrement a Fraction and
// multiply two Fraction respectively. (Use constructor to initialize values of an object)//not understand program and logic
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }

    Fraction operator++() {
        numerator += denominator;
        return *this;
    }

    Fraction operator--() {
        numerator -= denominator;
        return *this;
    }

    Fraction operator*(const Fraction& f) {
        int n = numerator * f.numerator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    void print() {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3 = ++f1;
    Fraction f4 = --f2;
    Fraction f5 = f1 * f2;

    cout << "f1 after increment: ";
    f1.print();

    cout << "f2 after decrement: ";
    f2.print();

    cout << "f1 * f2 = ";
    f5.print();

    return 0;
}
