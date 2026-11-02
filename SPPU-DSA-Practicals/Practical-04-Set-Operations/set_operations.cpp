// Practical 4: Set operations using singly linked lists
// A = students who like Vanilla; B = students who like Butterscotch.
#include <iostream>
using namespace std;

struct Node {
    int rollNo;
    Node* next;
    explicit Node(int value) : rollNo(value), next(nullptr) {}
};

bool contains(Node* head, int value) {
    while (head != nullptr) {
        if (head->rollNo == value) return true;
        head = head->next;
    }
    return false;
}

void appendUnique(Node*& head, int value) {
    if (contains(head, value)) return;
    Node* node = new Node(value);
    if (head == nullptr) {
        head = node;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = node;
}

Node* readSet(const char* label) {
    int n, roll;
    Node* head = nullptr;
    cout << "Enter number of students in " << label << " set: ";
    cin >> n;
    if (n < 0) n = 0;
    cout << "Enter roll numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> roll;
        appendUnique(head, roll);
    }
    return head;
}

void displaySet(const char* label, Node* head) {
    cout << label;
    if (head == nullptr) {
        cout << "Empty";
    } else {
        while (head != nullptr) {
            cout << head->rollNo;
            if (head->next != nullptr) cout << " ";
            head = head->next;
        }
    }
    cout << "\n";
}

int countNodes(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* A = readSet("Vanilla");
    Node* B = readSet("Butterscotch");
    Node *both = nullptr, *either = nullptr, *allStudents = nullptr;

    // Intersection: A ∩ B
    for (Node* p = A; p != nullptr; p = p->next) {
        if (contains(B, p->rollNo)) appendUnique(both, p->rollNo);
    }

    // Symmetric difference: elements in A or B, but not in both.
    for (Node* p = A; p != nullptr; p = p->next) {
        if (!contains(B, p->rollNo)) appendUnique(either, p->rollNo);
    }
    for (Node* p = B; p != nullptr; p = p->next) {
        if (!contains(A, p->rollNo)) appendUnique(either, p->rollNo);
    }

    // Union: A ∪ B
    for (Node* p = A; p != nullptr; p = p->next) appendUnique(allStudents, p->rollNo);
    for (Node* p = B; p != nullptr; p = p->next) appendUnique(allStudents, p->rollNo);

    cout << "\n";
    displaySet("Students who like both flavours (intersection): ", both);
    displaySet("Students who like either flavour, but not both (symmetric difference): ", either);
    displaySet("Students who like at least one flavour (union): ", allStudents);

    int total;
    cout << "Enter total number of students in the class: ";
    cin >> total;
    int neither = total - countNodes(allStudents);
    if (neither < 0) {
        cout << "Warning: union contains more roll numbers than the stated class strength.\n";
        neither = 0;
    }
    cout << "Number of students who like neither flavour: " << neither << "\n";

    freeList(A);
    freeList(B);
    freeList(both);
    freeList(either);
    freeList(allStudents);
    return 0;
}
