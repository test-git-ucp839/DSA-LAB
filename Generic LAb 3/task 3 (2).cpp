#include <iostream>
using namespace std;

class CustomList {
    int* arr;
    int size;

public:
    CustomList(int s = 5, int a[] = nullptr) {
        size = s;
        arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = (a != nullptr) ? a[i] : 0;
        }
    }

    CustomList(const CustomList& obj) {
        size = obj.size;
        arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = obj.arr[i];
        }
    }

    ~CustomList() {
        delete[] arr;
    }

    void input() {
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << "List: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool isPrime(int n) {
        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int sum_ofPrime() {
        int sum = 0;

        for (int i = 0; i < size; i++) {
            if (isPrime(arr[i])) {
                sum += arr[i];
            }
        }

        return sum;
    }

    int secondMaxEven() {
        int max1 = 0, max2 = 0;
        bool found1 = false, found2 = false;

        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 == 0) {
                if (!found1 || arr[i] > max1) {
                    if (found1) {
                        max2 = max1;
                        found2 = true;
                    }
                    max1 = arr[i];
                    found1 = true;
                }
                else if (arr[i] < max1 &&
                    (!found2 || arr[i] > max2)) {
                    max2 = arr[i];
                    found2 = true;
                }
            }
        }

        if (found2)
            return max2;

        cout << "Second maximum even number does not exist.\n";
        return -1;
    }

    int secondMinOdd() {
        int min1 = 0, min2 = 0;
        bool found1 = false, found2 = false;

        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 != 0) {
                if (!found1 || arr[i] < min1) {
                    if (found1) {
                        min2 = min1;
                        found2 = true;
                    }
                    min1 = arr[i];
                    found1 = true;
                }
                else if (arr[i] > min1 &&
                    (!found2 || arr[i] < min2)) {
                    min2 = arr[i];
                    found2 = true;
                }
            }
        }

        if (found2)
            return min2;

        cout << "Second minimum odd number does not exist.\n";
        return -1;
    }

    void printDuplicates() {
        bool duplicateFound = false;

        cout << "Duplicate numbers: ";

        for (int i = 0; i < size; i++) {
            bool alreadyChecked = false;

            for (int k = 0; k < i; k++) {
                if (arr[k] == arr[i]) {
                    alreadyChecked = true;
                    break;
                }
            }

            if (alreadyChecked)
                continue;

            int count = 0;

            for (int j = 0; j < size; j++) {
                if (arr[i] == arr[j])
                    count++;
            }

            if (count > 1) {
                cout << arr[i] << " ";
                duplicateFound = true;
            }
        }

        if (!duplicateFound)
            cout << "None";

        cout << endl;
    }

    void rotateClockwaise(int r) {
        if (size <= 1)
            return;

        int mid = size / 2;
        r = r < 0 ? 0 : r;

        if (mid > 0) {
            int k = r % mid;

            while (k--) {
                int last = arr[mid - 1];

                for (int i = mid - 1; i > 0; i--)
                    arr[i] = arr[i - 1];

                arr[0] = last;
            }
        }

        int secondSize = size - mid;

        if (secondSize > 0) {
            int k = r % secondSize;

            while (k--) {
                int last = arr[size - 1];

                for (int i = size - 1; i > mid; i--)
                    arr[i] = arr[i - 1];

                arr[mid] = last;
            }
        }
    }

    void rotateanitclockwaise(int rt) {
        if (size <= 1)
            return;

        int mid = size / 2;
        rt = rt < 0 ? 0 : rt;

        if (mid > 0) {
            int k = rt % mid;

            while (k--) {
                int first = arr[0];

                for (int i = 0; i < mid - 1; i++)
                    arr[i] = arr[i + 1];

                arr[mid - 1] = first;
            }
        }

        int secondSize = size - mid;

        if (secondSize > 0) {
            int k = rt % secondSize;

            while (k--) {
                int first = arr[mid];

                for (int i = mid; i < size - 1; i++)
                    arr[i] = arr[i + 1];

                arr[size - 1] = first;
            }
        }
    }
};

int main() {
    int n, choice, r;

    cout << "Enter the size of the list: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid list size.\n";
        return 0;
    }

    CustomList list(n);
    list.input();

    do {
        cout << "\n===== CUSTOM LIST MENU =====\n";
        cout << "1. Display List\n";
        cout << "2. Sum of Prime Numbers\n";
        cout << "3. Second Maximum Even Number\n";
        cout << "4. Second Minimum Odd Number\n";
        cout << "5. Print Duplicates\n";
        cout << "6. Rotate Clockwise\n";
        cout << "7. Rotate Anticlockwise\n";
        cout << "8. Copy Constructor Demonstration\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            list.display();
            break;

        case 2:
            cout << "Sum of prime numbers: "
                << list.sum_ofPrime() << endl;
            break;

        case 3:
        {
            int result = list.secondMaxEven();
            if (result != -1)
                cout << "Second maximum even number: "
                << result << endl;
        }
        break;

        case 4:
        {
            int result = list.secondMinOdd();
            if (result != -1)
                cout << "Second minimum odd number: "
                << result << endl;
        }
        break;

        case 5:
            list.printDuplicates();
            break;

        case 6:
            cout << "Enter number of rotations: ";
            cin >> r;
            list.rotateClockwaise(r);
            list.display();
            break;

        case 7:
            cout << "Enter number of rotations: ";
            cin >> r;
            list.rotateanitclockwaise(r);
            list.display();
            break;

        case 8:
        {
            CustomList copy(list);
            cout << "Copied list:\n";
            copy.display();
        }
        break;

        case 0:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}