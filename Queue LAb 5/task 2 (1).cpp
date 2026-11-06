#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (top == 99) {
            cout << "Stack is Full!" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return arr[top];
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
    }
};

class Queue {
private:
    Stack s1, s2;

public:
    void enqueue(int value) {
        s1.push(value);
        cout << "Element Inserted!" << endl;
    }

    void transfer() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
    }

    void dequeue() {
        transfer();

        if (s2.isEmpty()) {
            cout << "Queue is Empty!" << endl;
        }
        else {
            cout << "Deleted: " << s2.pop() << endl;
        }
    }

    void front() {
        transfer();

        if (s2.isEmpty()) {
            cout << "Queue is Empty!" << endl;
        }
        else {
            cout << "Front: " << s2.peek() << endl;
        }
    }

    void display() {
        if (s1.isEmpty() && s2.isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue: ";
        s2.display();

        Stack temp;

        while (!s1.isEmpty()) {
            temp.push(s1.pop());
        }

        temp.display();

        while (!temp.isEmpty()) {
            s1.push(temp.pop());
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Front";
        cout << "\n4. Display";
        cout << "\n5. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Value: ";
            cin >> value;
            q.enqueue(value);
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