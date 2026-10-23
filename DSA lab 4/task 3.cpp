#include <iostream>
#include <string>

using namespace std;

class myCarStack {
private:
    string* arr;
    int capacity;
    int topIndex;

public:
    myCarStack(int size = 8) {
        capacity = size;
        arr = new string[capacity];
        topIndex = -1;
    }

    ~myCarStack() {
        delete[] arr;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }

    void push(string carNum) {
        if (isFull()) {
            cout << "Parking lot is full (Limit: 8 cars)! Cannot park " << carNum << "[cite: 3].\n";
            return;
        }
        arr[++topIndex] = carNum;
        cout << "Car " << carNum << " parked successfully[cite: 3].\n";
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }
        return arr[topIndex--];
    }

    string top() const {
        if (isEmpty()) {
            return "";
        }
        return arr[topIndex];
    }

    int getCount() const {
        return topIndex + 1;
    }

    bool search(string carNum) const {
        for (int i = 0; i <= topIndex; i++) {
            if (arr[i] == carNum) {
                return true;
            }
        }
        return false;
    }

    void removeCar(string carNum) {
        if (!search(carNum)) {
            cout << "Car " << carNum << " not found in the parking lot[cite: 3].\n";
            return;
        }

        myCarStack tempStack(capacity);

        while (!isEmpty()) {
            string currentCar = pop();
            if (currentCar == carNum) {
                cout << "Car " << carNum << " removed from the parking lot[cite: 3].\n";
                break;
            }
            else {
                tempStack.push(currentCar);
            }
        }

        while (!tempStack.isEmpty()) {
            push(tempStack.pop());
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "Parking lot is empty[cite: 3].\n";
            return;
        }
        cout << "Cars currently parked (Top to Bottom):\n";
        for (int i = topIndex; i >= 0; i--) {
            cout << "- " << arr[i] << "\n";
        }
    }
};

int main() {
    myCarStack parkingLot(8);
    int choice;

    do {
        cout << "\n--- PARKING LOT MANAGEMENT SYSTEM ---\n";
        cout << "1. Park a new car\n";
        cout << "2. Remove a car by car number\n";
        cout << "3. Show top car\n";
        cout << "4. Check if parking lot is empty\n";
        cout << "5. Check if parking lot is full\n";
        cout << "6. Display cars currently parked\n";
        cout << "7. Show total cars parked\n";
        cout << "8. Search for a car\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string carNum;
            cout << "Enter car number/license plate: ";
            cin >> carNum;
            parkingLot.push(carNum);
            break;
        }
        case 2: {
            string carNum;
            cout << "Enter car number to remove: ";
            cin >> carNum;
            parkingLot.removeCar(carNum);
            break;
        }
        case 3: {
            if (parkingLot.isEmpty()) {
                cout << "Parking lot is empty[cite: 3].\n";
            }
            else {
                cout << "Top car: " << parkingLot.top() << "\n";
            }
            break;
        }
        case 4:
            if (parkingLot.isEmpty()) {
                cout << "Parking lot is EMPTY[cite: 3].\n";
            }
            else {
                cout << "Parking lot is NOT empty[cite: 3].\n";
            }
            break;
        case 5:
            if (parkingLot.isFull()) {
                cout << "Parking lot is FULL (8 cars limit reached)[cite: 3].\n";
            }
            else {
                cout << "Parking lot is NOT full[cite: 3].\n";
            }
            break;
        case 6:
            parkingLot.display();
            break;
        case 7:
            cout << "Total cars parked: " << parkingLot.getCount() << " / 8[cite: 3].\n";
            break;
        case 8: {
            string carNum;
            cout << "Enter car number to search: ";
            cin >> carNum;
            if (parkingLot.search(carNum)) {
                cout << "Car " << carNum << " IS present in the parking lot[cite: 3].\n";
            }
            else {
                cout << "Car " << carNum << " is NOT present in the parking lot[cite: 3].\n";
            }
            break;
        }
        case 9:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}