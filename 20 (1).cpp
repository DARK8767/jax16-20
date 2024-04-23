// Q1.Write a C++ program to sort integer and float array elements in ascending order by using
// function overloading
#include <iostream>
using namespace std;

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void sortArray(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {5, 2, 7, 1, 8};
    float arr2[] = {3.5, 2.0, 7.8, 1.2, 6.4};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    sortArray(arr1, n1);
    sortArray(arr2, n2);

    cout << "Sorted Integer Array: ";
    printArray(arr1, n1);

    cout << "Sorted Float Array: ";
    printArray(arr2, n2);

    return 0;
}
