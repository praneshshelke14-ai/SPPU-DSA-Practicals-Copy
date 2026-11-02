// Practical 7: Pizza parlour order processing using a circular queue
#include <iostream>
using namespace std;

const int MAX_ORDERS = 5;

class PizzaParlour {
    int orders[MAX_ORDERS];
    int frontIndex;
    int rearIndex;
    int count;

public:
    PizzaParlour() : frontIndex(0), rearIndex(-1), count(0) {}

    bool addOrder(int orderId) {
        if (count == MAX_ORDERS) {
            cout << "Pizza parlour queue is full. Please wait.\n";
            return false;
        }
        rearIndex = (rearIndex + 1) % MAX_ORDERS;
        orders[rearIndex] = orderId;
        count++;
        cout << "Order accepted. Order ID: " << orderId << "\n";
        return true;
    }

    void serveOrder() {
        if (count == 0) {
            cout << "No orders in the queue.\n";
            return;
        }
        cout << "Order " << orders[frontIndex] << " is being served.\n";
        frontIndex = (frontIndex + 1) % MAX_ORDERS;
        count--;
        if (count == 0) {
            frontIndex = 0;
            rearIndex = -1;
        }
    }

    void display() const {
        if (count == 0) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "Pending order IDs (front to rear): ";
        for (int i = 0; i < count; i++) {
            int index = (frontIndex + i) % MAX_ORDERS;
            cout << orders[index] << " ";
        }
        cout << "\n";
    }
};

int main() {
    PizzaParlour queue;
    int choice;
    int nextOrderId = 1;

    do {
        cout << "\n--- PIZZA PARLOUR ---\n"
             << "1. Accept order\n2. Serve order\n3. Display pending orders\n0. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                if (queue.addOrder(nextOrderId)) nextOrderId++;
                break;
            case 2:
                queue.serveOrder();
                break;
            case 3:
                queue.display();
                break;
            case 0:
                cout << "Thank you.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
