#include <iostream>

using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    myStack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    ~myStack() {
        delete[] arr;
    }

    void push(T value) override {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << "\n";
            return;
        }
        arr[++topIndex] = value;
        cout << "Pushed " << value << " onto the stack.\n";
    }

    T pop() override {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return T();
        }
        return arr[topIndex--];
    }

    T top() const override {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return T();
        }
        return arr[topIndex];
    }

    bool isEmpty() const override {
        return topIndex == -1;
    }

    bool isFull() const override {
        return topIndex == capacity - 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements (Top to Bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int capacity;
    cout << "Enter maximum capacity for the stack: ";
    cin >> capacity;

    while (capacity <= 0) {
        cout << "Please enter a positive integer for capacity: ";
        cin >> capacity;
    }

    myStack<int> stack(capacity);

    int choice;
    do {
        cout << "\n--- STACK OPERATIONS MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek Top\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display Stack\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (stack.isFull()) {
                cout << "Stack Overflow! Stack is full.\n";
            }
            else {
                int val;
                cout << "Enter value to push: ";
                cin >> val;
                stack.push(val);
            }
            break;
        }
        case 2: {
            if (stack.isEmpty()) {
                cout << "Stack Underflow! Stack is empty.\n";
            }
            else {
                int poppedVal = stack.pop();
                cout << "Popped value: " << poppedVal << "\n";
            }
            break;
        }
        case 3: {
            if (stack.isEmpty()) {
                cout << "Stack is empty.\n";
            }
            else {
                cout << "Top element: " << stack.top() << "\n";
            }
            break;
        }
        case 4:
            if (stack.isEmpty()) {
                cout << "Stack is EMPTY.\n";
            }
            else {
                cout << "Stack is NOT empty.\n";
            }
            break;
        case 5:
            if (stack.isFull()) {
                cout << "Stack is FULL.\n";
            }
            else {
                cout << "Stack is NOT full.\n";
            }
            break;
        case 6:
            stack.display();
            break;
        case 7:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}