// Practical 5: Cinemax seat booking using an array of doubly linked-list heads.
// 10 rows, 7 seats per row.
#include <iostream>
#include <string>
using namespace std;

const int ROWS = 10;
const int SEATS_PER_ROW = 7;

struct Node {
    int seat;
    bool booked;
    string customerId;
    Node* prev;
    Node* next;
    explicit Node(int number)
        : seat(number), booked(false), customerId(""), prev(nullptr), next(nullptr) {}
};

class CinemaMax {
    Node* head[ROWS];

    Node* getSeat(int row, int seat) const {
        if (row < 1 || row > ROWS || seat < 1 || seat > SEATS_PER_ROW) return nullptr;
        Node* current = head[row - 1];
        while (current != nullptr && current->seat != seat) current = current->next;
        return current;
    }

public:
    CinemaMax() {
        for (int row = 0; row < ROWS; row++) head[row] = nullptr;
        createRows();
        // Example pre-bookings, as suggested by the practical statement.
        setPreBooking(1, 3);
        setPreBooking(4, 6);
    }

    ~CinemaMax() {
        for (int row = 0; row < ROWS; row++) {
            Node* current = head[row];
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
    }

    void createRows() {
        for (int row = 0; row < ROWS; row++) {
            Node* tail = nullptr;
            for (int seat = 1; seat <= SEATS_PER_ROW; seat++) {
                Node* node = new Node(seat);
                if (head[row] == nullptr) {
                    head[row] = node;
                } else {
                    tail->next = node;
                    node->prev = tail;
                }
                tail = node;
            }
        }
    }

    void setPreBooking(int row, int seat) {
        Node* node = getSeat(row, seat);
        if (node != nullptr) {
            node->booked = true;
            node->customerId = "PREBOOKED";
        }
    }

    void displayStatus() const {
        cout << "\nCINEMAX – SCREEN THIS WAY\n";
        cout << "B = Booked, O = Available\n";
        for (int row = 0; row < ROWS; row++) {
            cout << "Row " << row + 1 << ": ";
            for (Node* p = head[row]; p != nullptr; p = p->next) {
                cout << "[" << p->seat << ":" << (p->booked ? 'B' : 'O') << "] ";
            }
            cout << "\n";
        }
    }

    void displayAvailable() const {
        cout << "\nAvailable seats (row-seat):\n";
        bool any = false;
        for (int row = 0; row < ROWS; row++) {
            for (Node* p = head[row]; p != nullptr; p = p->next) {
                if (!p->booked) {
                    cout << row + 1 << "-" << p->seat << "  ";
                    any = true;
                }
            }
            cout << "\n";
        }
        if (!any) cout << "No seats available.\n";
    }

    void bookSeat() {
        int row, seat;
        string id;
        cout << "Enter row (1-10): ";
        cin >> row;
        cout << "Enter seat (1-7): ";
        cin >> seat;
        Node* node = getSeat(row, seat);
        if (node == nullptr) {
            cout << "Invalid row or seat number.\n";
            return;
        }
        if (node->booked) {
            cout << "Seat is already booked.\n";
            return;
        }
        cout << "Enter customer ID: ";
        cin >> id;
        node->booked = true;
        node->customerId = id;
        cout << "Seat " << row << "-" << seat << " booked successfully.\n";
    }

    void cancelSeat() {
        int row, seat;
        string id;
        cout << "Enter row (1-10): ";
        cin >> row;
        cout << "Enter seat (1-7): ";
        cin >> seat;
        Node* node = getSeat(row, seat);
        if (node == nullptr) {
            cout << "Invalid row or seat number.\n";
            return;
        }
        if (!node->booked) {
            cout << "Seat is not booked.\n";
            return;
        }
        cout << "Enter customer ID used for booking: ";
        cin >> id;
        if (node->customerId != id) {
            cout << "Customer ID does not match. Cancellation denied.\n";
            return;
        }
        node->booked = false;
        node->customerId.clear();
        cout << "Booking cancelled successfully.\n";
    }
};

int main() {
    CinemaMax cinema;
    int choice;
    do {
        cout << "\n--- CINEMAX THEATRE ---\n"
             << "1. Display current seat status\n"
             << "2. Book a seat\n"
             << "3. Display available seats\n"
             << "4. Cancel a booking\n"
             << "0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cinema.displayStatus(); break;
            case 2: cinema.bookSeat(); break;
            case 3: cinema.displayAvailable(); break;
            case 4: cinema.cancelSeat(); break;
            case 0: cout << "Thank you.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
