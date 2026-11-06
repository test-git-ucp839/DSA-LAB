#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int size;
    int f, r, count;

public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        f = 0;
        r = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }

    void enqueue(int ticket_id) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }

        if (ticket_id < 1000 || ticket_id > 9999) {
            cout << "Ticket ID must be 4 digits!" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            if (arr[(f + i) % size] == ticket_id) {
                cout << "Ticket ID already exists!" << endl;
                return;
            }
        }

        r = (r + 1) % size;
        arr[r] = ticket_id;
        count++;

        cout << "Ticket Added Successfully!" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No Pending Tickets!" << endl;
            return;
        }

        cout << "Resolved Ticket: " << arr[f] << endl;
        f = (f + 1) % size;
        count--;
    }

    void front() {
        if (isEmpty()) {
            cout << "No Pending Tickets!" << endl;
            return;
        }

        cout << "Next Ticket: " << arr[f] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "No Pending Tickets!" << endl;
            return;
        }

        cout << "Pending Tickets: ";

        for (int i = 0; i < count; i++) {
            cout << arr[(f + i) % size] << " ";
        }

        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int size, choice, ticket_id;

    cout << "Enter Maximum Tickets: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid Size!" << endl;
        return 0;
    }

    Queue q(size);

    do {
        cout << "\n1. Add Ticket";
        cout << "\n2. Resolve Ticket";
        cout << "\n3. Next Ticket";
        cout << "\n4. Display Pending Tickets";
        cout << "\n5. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> ticket_id;
            q.enqueue(ticket_id);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.front();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Program Ended!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}