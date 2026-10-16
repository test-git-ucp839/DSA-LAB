#include <iostream>
using namespace std;

template <class T>
class MyList {
private:
    T* arr;
    int capacity;
    int currentSize;

public:
    MyList(int cap = 10, int size = 0) {
        capacity = cap;
        currentSize = size;
        arr = new T[capacity];
    }

    MyList(const MyList<T>& other) {
        capacity = other.capacity;
        currentSize = other.currentSize;
        arr = new T[capacity];

        for (int i = 0; i < currentSize; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~MyList() {
        delete[] arr;
    }

    bool empty() {
        return currentSize == 0;
    }

    bool full() {
        return currentSize == capacity;
    }

    int size() {
        return currentSize;
    }

    bool insertAt(int index, T value) {
        if (index < 0 || index > currentSize || full()) {
            return false;
        }

        for (int i = currentSize; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = value;
        currentSize++;
        return true;
    }

    T last() {
        if (empty()) {
            cout << "List is empty!" << endl;
            return T();
        }

        return arr[currentSize - 1];
    }

    bool search(T value) {
        for (int i = 0; i < currentSize; i++) {
            if (arr[i] == value) {
                return true;
            }
        }

        return false;
    }

    void display() {
        if (empty()) {
            cout << "List is empty!" << endl;
            return;
        }

        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter list capacity: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Invalid capacity!" << endl;
        return 0;
    }

    MyList<int> list(capacity);
    int choice, index, value;

    do {
        cout << "\n----- MyList Menu -----" << endl;
        cout << "1. Check Empty" << endl;
        cout << "2. Check Full" << endl;
        cout << "3. Get Size" << endl;
        cout << "4. Insert At Index" << endl;
        cout << "5. Get Last Element" << endl;
        cout << "6. Search Value" << endl;
        cout << "7. Display List" << endl;
        cout << "8. Copy List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (list.empty())
                cout << "List is empty." << endl;
            else
                cout << "List is not empty." << endl;
            break;

        case 2:
            if (list.full())
                cout << "List is full." << endl;
            else
                cout << "List is not full." << endl;
            break;

        case 3:
            cout << "Current size: " << list.size() << endl;
            break;

        case 4:
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;

            if (list.insertAt(index, value))
                cout << "Value inserted successfully." << endl;
            else
                cout << "Insertion failed." << endl;
            break;

        case 5:
            if (!list.empty())
                cout << "Last element: " << list.last() << endl;
            else
                cout << "List is empty." << endl;
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> value;

            if (list.search(value))
                cout << "Value found." << endl;
            else
                cout << "Value not found." << endl;
            break;

        case 7:
            list.display();
            break;

        case 8: {
            MyList<int> copiedList(list);
            cout << "Copied list: ";
            copiedList.display();
            break;
        }

        case 0:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}