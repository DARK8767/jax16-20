// or Q2. Write a C++ program to read the contents of a “Sample.txt” file. Store all the uppercase
// characters in ”Upper.txt”, lowercase characters in ”Lower.txt” and digits in “Digit.txt” files.
// Change the case of each character from “Sample.txt” and store it in “Convert.txt” file.
#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int main() {
    ifstream fin;
    fin.open("Sample.txt");

    ofstream fout_upper;
    fout_upper.open("Upper.txt");

    ofstream fout_lower;
    fout_lower.open("Lower.txt");

    ofstream fout_digit;
    fout_digit.open("Digit.txt");

    ofstream fout_convert;
    fout_convert.open("Convert.txt");

    char ch;
    while (fin >> ch) {
        if (isupper(ch)) {
            fout_upper << ch;
        }
        else if (islower(ch)) {
            fout_lower << ch;
        }
        else if (isdigit(ch)) {
            fout_digit << ch;
        }

        if (isalpha(ch)) {
            if (islower(ch)) {
                ch = toupper(ch);
            }
            else {
                ch = tolower(ch);
            }
        }
        fout_convert << ch;
    }

    fin.close();
    fout_upper.close();
    fout_lower.close();
    fout_digit.close();
    fout_convert.close();

    return 0;
}
