// Practical 1(a): Linear Search on student roll numbers
#include <iostream>
using namespace std;

int linearSearch(const int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return zero-based index when found
        }
    }
    return -1; // Element is not present
}

int main() {
    int n, arr[100], key;

    cout << "Enter number of students (1-100): ";
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid number of students.\n";
        return 1;
    }

    cout << "Enter roll numbers in any order:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter roll number to search: ";
    cin >> key;

    int position = linearSearch(arr, n, key);
    if (position != -1) {
        cout << "Student attended the training program.\n";
        cout << "Position in array (1-based): " << position + 1 << "\n";
    } else {
        cout << "Student did not attend the training program.\n";
    }
    return 0;
}
