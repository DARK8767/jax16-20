// Q2. Create a class called LIST with two pure virtual function store() and retrieve(). To store a
// value call store and to retrieve call retrieves function. Derive two classes stack and queue
// from it and override store and retrieve.//not understand program and logic and question
#include <iostream>
using namespace std;

class LIST {
public:
    virtual void store(int val) = 0;
    virtual int retrieve() = 0;
};

class Stack : public LIST {
private:
    int arr[100];
    int top;
public:
    Stack() {
        top = -1;
    }
    void store(int val) {
        arr[++top] = val;
    }
    int retrieve() {
        return arr[top--];
    }
};

class Queue : public LIST {
private:
    int arr[100];
    int front, rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }
    void store(int val) {
        arr[++rear] = val;
    }
    int retrieve() {
        return arr[front++];
    }
};

int main() {
    LIST *ptr;
    Stack s;
    Queue q;

    ptr = &s;
    ptr->store(10);
    ptr->store(20);
    cout << ptr->retrieve() << endl;
    cout << ptr->retrieve() << endl;

    ptr = &q;
    ptr->store(30);
    ptr->store(40);
    cout << ptr->retrieve() << endl;
    cout << ptr->retrieve() << endl;

    return 0;
}
