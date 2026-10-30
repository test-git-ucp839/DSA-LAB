#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int f, r, count;

public:
    Queue() {
        f = 0;
        r = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(int value) {
        if (count == 100) {
            cout << "Queue is Full!" << endl;
            return;
        }

        r = (r + 1) % 100;
        arr[r] = value;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        int value = arr[f];
        f = (f + 1) % 100;
        count--;
        return value;
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }
        return arr[f];
    }

    int getSize() {
        return count;
    }

    void display() {
        for (int i = 0; i < count; i++) {
            cout << arr[(f + i) % 100] << " ";
        }
        cout << endl;
    }
};

class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top < 99) {
            arr[++top] = value;
        }
    }

    int pop() {
        if (top == -1) {
            return -1;
        }
        return arr[top--];
    }
};

void reverseK(Queue& q, int k) {
    int n = q.getSize();

    if (k <= 1 || k > n) {
        return;
    }

    Stack s;

    for (int i = 0; i < k; i++) {
        s.push(q.dequeue());
    }

    for (int i = 0; i < k; i++) {
        q.enqueue(s.pop());
    }

    for (int i = 0; i < n - k; i++) {
        q.enqueue(q.dequeue());
    }
}

int main() {
    Queue q;
    int n, value, k;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 0 || n > 100) {
        cout << "Invalid Size!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter element: ";
        cin >> value;
        q.enqueue(value);
    }

    cout << "Original Queue: ";
    q.display();

    cout << "Enter K: ";
    cin >> k;

    reverseK(q, k);

    cout << "Queue after reversing: ";
    q.display();

    return 0;
}