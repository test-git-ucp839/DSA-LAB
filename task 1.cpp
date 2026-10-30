//#include <iostream>
//using namespace std;
//
//template <typename T>
//class AbstractQueue {
//public:
//    virtual void enQueue(T value) = 0;
//    virtual T deQueue() = 0;
//    virtual T front() const = 0;
//    virtual bool isEmpty() const = 0;
//    virtual bool isFull() const = 0;
//    virtual ~AbstractQueue() {}
//};
//
//template <typename T>
//class myQueue : public AbstractQueue<T> {
//private:
//    T* arr;
//    int size;
//    int count;
//    int frontIndex;
//    int rearIndex;
//
//public:
//    myQueue(int s) {
//        size = s;
//        arr = new T[size];
//        count = 0;
//        frontIndex = 0;
//        rearIndex = -1;
//    }
//
//    bool isEmpty() const {
//        return count == 0;
//    }
//
//    bool isFull() const {
//        return count == size;
//    }
//
//    void enQueue(T value) {
//        if (isFull()) {
//            cout << "Queue is Full!" << endl;
//            return;
//        }
//
//        rearIndex = (rearIndex + 1) % size;
//        arr[rearIndex] = value;
//        count++;
//
//        cout << "Element inserted successfully!" << endl;
//    }
//
//    T deQueue() {
//        if (isEmpty()) {
//            cout << "Queue is Empty!" << endl;
//            return T();
//        }
//
//        T value = arr[frontIndex];
//        frontIndex = (frontIndex + 1) % size;
//        count--;
//
//        return value;
//    }
//
//    T front() const {
//        if (isEmpty()) {
//            cout << "Queue is Empty!" << endl;
//            return T();
//        }
//
//        return arr[frontIndex];
//    }
//
//    void display() const {
//        if (isEmpty()) {
//            cout << "Queue is Empty!" << endl;
//            return;
//        }
//
//        cout << "Queue Elements: ";
//
//        for (int i = 0; i < count; i++) {
//            cout << arr[(frontIndex + i) % size] << " ";
//        }
//
//        cout << endl;
//    }
//
//    ~myQueue() {
//        delete[] arr;
//    }
//};
//
//int main() {
//    int size, choice, value;
//
//    cout << "Enter Queue Size: ";
//    cin >> size;
//
//    if (size <= 0) {
//        cout << "Invalid Queue Size!" << endl;
//        return 0;
//    }
//
//    myQueue<int> q(size);
//
//    do {
//        cout << "\n1. EnQueue" << endl;
//        cout << "2. DeQueue" << endl;
//        cout << "3. Front" << endl;
//        cout << "4. IsEmpty" << endl;
//        cout << "5. IsFull" << endl;
//        cout << "6. Display" << endl;
//        cout << "7. Exit" << endl;
//
//        cout << "Enter Choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter Value: ";
//            cin >> value;
//            q.enQueue(value);
//            break;
//
//        case 2:
//            if (!q.isEmpty()) {
//                cout << "Deleted Element: " << q.deQueue() << endl;
//            }
//            else {
//                cout << "Queue is Empty!" << endl;
//            }
//            break;
//
//        case 3:
//            if (!q.isEmpty()) {
//                cout << "Front Element: " << q.front() << endl;
//            }
//            else {
//                cout << "Queue is Empty!" << endl;
//            }
//            break;
//
//        case 4:
//            if (q.isEmpty()) {
//                cout << "Queue is Empty!" << endl;
//            }
//            else {
//                cout << "Queue is Not Empty!" << endl;
//            }
//            break;
//
//        case 5:
//            if (q.isFull()) {
//                cout << "Queue is Full!" << endl;
//            }
//            else {
//                cout << "Queue is Not Full!" << endl;
//            }
//            break;
//
//        case 6:
//            q.display();
//            break;
//
//        case 7:
//            cout << "Exiting Program!" << endl;
//            break;
//
//        default:
//            cout << "Invalid Choice!" << endl;
//        }
//
//    } while (choice != 7);
//
//    return 0;
//}