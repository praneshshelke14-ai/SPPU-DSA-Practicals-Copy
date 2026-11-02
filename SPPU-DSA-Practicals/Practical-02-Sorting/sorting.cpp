// Practical 2: Sorting student percentages
// Includes Bubble, Selection, Insertion and Shell Sort.
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void bubbleSort(vector<float>& a) {
    int n = static_cast<int>(a.size());
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                float temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(vector<float>& a) {
    int n = static_cast<int>(a.size());
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) minIndex = j;
        }
        if (minIndex != i) {
            float temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

void insertionSort(vector<float>& a) {
    int n = static_cast<int>(a.size());
    for (int i = 1; i < n; i++) {
        float key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void shellSort(vector<float>& a) {
    int n = static_cast<int>(a.size());
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            float temp = a[i];
            int j = i;
            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
    }
}

void display(const vector<float>& a) {
    for (float value : a) cout << fixed << setprecision(2) << value << " ";
    cout << "\n";
}

void displayTopFive(const vector<float>& a) {
    cout << "Top scores (highest first):\n";
    int shown = 0;
    for (int i = static_cast<int>(a.size()) - 1; i >= 0 && shown < 5; i--, shown++) {
        cout << shown + 1 << ". " << fixed << setprecision(2) << a[i] << "%\n";
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    if (n <= 0) {
        cout << "Number of students must be positive.\n";
        return 1;
    }

    vector<float> marks(n);
    cout << "Enter percentages:\n";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
        if (marks[i] < 0.0f || marks[i] > 100.0f) {
            cout << "Enter percentages between 0 and 100.\n";
            return 1;
        }
    }

    int choice;
    cout << "\nChoose sorting method:\n"
         << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Shell Sort\n"
         << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: bubbleSort(marks); break;
        case 2: selectionSort(marks); break;
        case 3: insertionSort(marks); break;
        case 4: shellSort(marks); break;
        default:
            cout << "Invalid choice.\n";
            return 1;
    }

    cout << "Sorted percentages (ascending): ";
    display(marks);
    displayTopFive(marks);
    return 0;
}
