
#include <iostream>
using namespace std;

template <class Type>
class List {
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
    List(int size = 10, int current = 0) {
        maxSize = size;
        currentSize = current;
        arr = new Type[maxSize];
    }

    List(const List<Type>& obj) {
        maxSize = obj.maxSize;
        currentSize = obj.currentSize;

        arr = new Type[maxSize];

        for (int i = 0; i < currentSize; i++) {
            arr[i] = obj.arr[i];
        }
    }

    virtual void addElementAtFirstIndex(Type) = 0;
    virtual void addElementAtLastIndex(Type) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    virtual ~List() {
        delete[] arr;
    }

    void display() {
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

template <class Type>
class ArrayList : public List<Type> {
public:
    ArrayList(int size = 10, int current = 0)
        : List<Type>(size, current) {}

    void addElementAtFirstIndex(Type value) override {
        if (this->currentSize == this->maxSize)
            return;

        for (int i = this->currentSize; i > 0; i--) {
            this->arr[i] = this->arr[i - 1];
        }

        this->arr[0] = value;
        this->currentSize++;
    }

    void addElementAtLastIndex(Type value) override {
        if (this->currentSize == this->maxSize)
            return;

        this->arr[this->currentSize] = value;
        this->currentSize++;
    }

    Type removeElementFromEnd() override {
        if (this->currentSize == 0)
            return Type();

        Type value = this->arr[this->currentSize - 1];
        this->currentSize--;
        return value;
    }

    void removeElementFromStart() override {
        if (this->currentSize == 0)
            return;

        for (int i = 0; i < this->currentSize - 1; i++) {
            this->arr[i] = this->arr[i + 1];
        }

        this->currentSize--;
    }
};

int main() {
    ArrayList<int> list1;

    list1.addElementAtLastIndex(10);
    list1.addElementAtLastIndex(20);
    list1.addElementAtLastIndex(30);

    cout << "Original List: ";
    list1.display();

    list1.addElementAtFirstIndex(5);

    cout << "After Adding at First: ";
    list1.display();

    ArrayList<int> list2(list1);

    cout << "Copied List: ";
    list2.display();

    cout << "Removed from End: "
        << list1.removeElementFromEnd() << endl;

    list1.removeElementFromStart();

    cout << "After Removing from Start: ";
    list1.display();

    return 0;
}
