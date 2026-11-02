// Practical 3: Telephone directory using a hash table
// Collision strategies: Linear Probing, Quadratic Probing, Double Hashing.
#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int TABLE_SIZE = 101; // Prime table size

struct Record {
    string name;
    string telephone;
    int status; // 0 = empty, 1 = occupied, 2 = deleted (tombstone)
    Record() : status(0) {}
};

class Hashing {
    Record table[TABLE_SIZE];
    int method; // 1 = linear, 2 = quadratic, 3 = double hashing

    int hash1(const string& name) const {
        unsigned long sum = 0;
        for (unsigned char ch : name) sum += ch;
        return static_cast<int>(sum % TABLE_SIZE);
    }

    int hash2(const string& name) const {
        unsigned long sum = 0;
        for (unsigned char ch : name) sum += ch;
        return 1 + static_cast<int>(sum % (TABLE_SIZE - 1));
    }

    int probeIndex(const string& name, int attempt) const {
        int h = hash1(name);
        if (method == 1) return (h + attempt) % TABLE_SIZE;
        if (method == 2) return (h + attempt * attempt) % TABLE_SIZE;
        return (h + attempt * hash2(name)) % TABLE_SIZE;
    }

    int findIndex(const string& name) const {
        for (int i = 0; i < TABLE_SIZE; i++) {
            int index = probeIndex(name, i);
            if (table[index].status == 0) return -1;
            if (table[index].status == 1 && table[index].name == name) return index;
        }
        return -1;
    }

public:
    explicit Hashing(int selectedMethod) : method(selectedMethod) {}

    void createRecord(const string& name, const string& telephone) {
        int firstDeleted = -1;
        for (int i = 0; i < TABLE_SIZE; i++) {
            int index = probeIndex(name, i);
            if (table[index].status == 1 && table[index].name == name) {
                table[index].telephone = telephone;
                cout << "Existing record updated.\n";
                return;
            }
            if (table[index].status == 2 && firstDeleted == -1) firstDeleted = index;
            if (table[index].status == 0) {
                int target = (firstDeleted == -1) ? index : firstDeleted;
                table[target].name = name;
                table[target].telephone = telephone;
                table[target].status = 1;
                cout << "Record created successfully.\n";
                return;
            }
        }
        if (firstDeleted != -1) {
            table[firstDeleted].name = name;
            table[firstDeleted].telephone = telephone;
            table[firstDeleted].status = 1;
            cout << "Record created successfully.\n";
        } else {
            cout << "Hash table is full; record could not be stored.\n";
        }
    }

    void searchRecord(const string& name) const {
        int index = findIndex(name);
        if (index == -1) {
            cout << "Record not found.\n";
        } else {
            cout << "Record found\nName: " << table[index].name
                 << "\nTelephone: " << table[index].telephone << "\n";
        }
    }

    void updateRecord(const string& name) {
        int index = findIndex(name);
        if (index == -1) {
            cout << "Record not found.\n";
            return;
        }
        cout << "Enter new telephone number: ";
        cin >> table[index].telephone;
        cout << "Record updated successfully.\n";
    }

    void deleteRecord(const string& name) {
        int index = findIndex(name);
        if (index == -1) {
            cout << "Record not found.\n";
            return;
        }
        table[index].name.clear();
        table[index].telephone.clear();
        table[index].status = 2; // Keep probe chain searchable
        cout << "Record deleted successfully.\n";
    }

    void displayRecords() const {
        bool any = false;
        cout << "\nNAME\t\tTELEPHONE\n";
        for (const Record& record : table) {
            if (record.status == 1) {
                cout << record.name << "\t\t" << record.telephone << "\n";
                any = true;
            }
        }
        if (!any) cout << "Directory is empty.\n";
    }
};

int main() {
    int method;
    cout << "Choose collision handling method:\n"
         << "1. Linear Probing\n2. Quadratic Probing\n3. Double Hashing\n"
         << "Enter choice: ";
    cin >> method;
    if (method < 1 || method > 3) {
        cout << "Invalid method.\n";
        return 1;
    }

    Hashing directory(method);
    int choice;
    string name, telephone;
    do {
        cout << "\n--- Telephone Book Database ---\n"
             << "1. Create Record\n2. Display Records\n3. Search Record\n"
             << "4. Update Record\n5. Delete Record\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter name (one word): ";
                cin >> name;
                cout << "Enter telephone number: ";
                cin >> telephone;
                directory.createRecord(name, telephone);
                break;
            case 2:
                directory.displayRecords();
                break;
            case 3:
                cout << "Enter name to search: ";
                cin >> name;
                directory.searchRecord(name);
                break;
            case 4:
                cout << "Enter name to update: ";
                cin >> name;
                directory.updateRecord(name);
                break;
            case 5:
                cout << "Enter name to delete: ";
                cin >> name;
                directory.deleteRecord(name);
                break;
            case 0:
                cout << "Exiting telephone directory.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
