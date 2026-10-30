#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    string* arr;
    int size;
    int f, r, count;

public:
    Queue(int s) {
        size = s;
        arr = new string[size];
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

    void enqueue(string document_name) {
        if (isFull()) {
            cout << "Print Queue is Full!" << endl;
            return;
        }

        r = (r + 1) % size;
        arr[r] = document_name;
        count++;

        cout << "Document Added Successfully!" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No Documents to Print!" << endl;
            return;
        }

        cout << "Printing Document: " << arr[f] << endl;

        f = (f + 1) % size;
        count--;
    }

    void front() {
        if (isEmpty()) {
            cout << "Print Queue is Empty!" << endl;
            return;
        }

        cout << "Next Document: " << arr[f] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "No Pending Documents!" << endl;
            return;
        }

        cout << "Pending Documents:" << endl;

        for (int i = 0; i < count; i++) {
            cout << arr[(f + i) % size] << endl;
        }
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    int size, choice;
    string document_name;

    cout << "Enter Maximum Print Jobs: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid Size!" << endl;
        return 0;
    }

    Queue q(size);

    do {
        cout << "\n1. Add Document";
        cout << "\n2. Print Document";
        cout << "\n3. Check Front Document";
        cout << "\n4. Display Pending Documents";
        cout << "\n5. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Document Name: ";
            cin >> ws;
            getline(cin, document_name);
            q.enqueue(document_name);
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