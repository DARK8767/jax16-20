// or  Q2. Create a base class Media. Derive two different classes Book (Book_id, Book_name,
// Publication, Author, Book_price) and CD (CD_title, CD_price) from Media. Write a program
// to accept and display information of both Book and CD. (Use pure virtual function)//not understand
#include <iostream>
#include <string>
using namespace std;

class Media {
public:
    virtual void accept() = 0;
    virtual void display() = 0;
};

class Book : public Media {
public:
    void accept() {
        cout << "Enter Book ID: ";
        cin >> book_id;
        cout << "Enter Book Name: ";
        cin.ignore();
        getline(cin, book_name);
        cout << "Enter Publication: ";
        getline(cin, publication);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Book Price: ";
        cin >> book_price;
    }

    void display() {
        cout << "Book ID: " << book_id << endl;
        cout << "Book Name: " << book_name << endl;
        cout << "Publication: " << publication << endl;
        cout << "Author: " << author << endl;
        cout << "Book Price: " << book_price << endl;
    }

private:
    int book_id;
    string book_name;
    string publication;
    string author;
    float book_price;
};

class CD : public Media {
public:
    void accept() {
        cout << "Enter CD Title: ";
        cin.ignore();
        getline(cin, cd_title);
        cout << "Enter CD Price: ";
        cin >> cd_price;
    }

    void display() {
        cout << "CD Title: " << cd_title << endl;
        cout << "CD Price: " << cd_price << endl;
    }

private:
    string cd_title;
    float cd_price;
};

int main() {
    Media* mediaPtr[2];
    mediaPtr[0] = new Book;
    mediaPtr[1] = new CD;

    for (int i = 0; i < 2; i++) {
        mediaPtr[i]->accept();
    }

    cout << "Information of Book and CD:\n\n";

    for (int i = 0; i < 2; i++) {
        mediaPtr[i]->display();
    }

    return 0;
}

