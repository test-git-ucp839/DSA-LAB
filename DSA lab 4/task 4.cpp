#include <iostream>
#include <string>

using namespace std;

struct Action {
    char type; 
    char ch;   
};

class TextStack {
private:
    Action* arr;
    int capacity;
    int topIndex;

public:
    TextStack(int size = 100) {
        capacity = size;
        arr = new Action[capacity];
        topIndex = -1;
    }

    ~TextStack() {
        delete[] arr;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    void push(Action act) {
        if (topIndex == capacity - 1) {
            int newCapacity = capacity * 2;
            Action* newArr = new Action[newCapacity];
            for (int i = 0; i <= topIndex; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }
        arr[++topIndex] = act;
    }

    Action pop() {
        if (isEmpty()) {
            return Action{ '\0', '\0' };
        }
        return arr[topIndex--];
    }

    void clear() {
        topIndex = -1;
    }
};

class TextEditor {
private:
    string text;
    TextStack undoStack;
    TextStack redoStack;

public:
    void type(char c) {
        text += c;
        undoStack.push({ 'T', c });
        redoStack.clear();
        cout << "Typed '" << c << "'. Current text: \"" << text << "\"\n";
    }

    void remove() {
        if (text.empty()) {
            cout << "Text is empty. Nothing to delete.\n";
            return;
        }
        char c = text.back();
        text.pop_back();
        undoStack.push({ 'D', c });
        redoStack.clear();
        cout << "Deleted character '" << c << "'. Current text: \"" << text << "\"\n";
    }

    void undo() {
        if (undoStack.isEmpty()) {
            cout << "Nothing to undo[cite: 4].\n";
            return;
        }
        Action act = undoStack.pop();
        if (act.type == 'T') {
            text.pop_back();
        }
        else if (act.type == 'D') {
            text += act.ch;
        }
        redoStack.push(act);
        cout << "Undo performed. Current text: \"" << text << "\"\n";
    }

    void redo() {
        if (redoStack.isEmpty()) {
            cout << "Nothing to redo[cite: 4].\n";
            return;
        }
        Action act = redoStack.pop();
        if (act.type == 'T') {
            text += act.ch;
        }
        else if (act.type == 'D') {
            text.pop_back();
        }
        undoStack.push(act);
        cout << "Redo performed. Current text: \"" << text << "\"\n";
    }

    void display() const {
        cout << "Current Text: \"" << text << "\"\n";
    }
};

int main() {
    TextEditor editor;
    int choice;

    do {
        cout << "\n--- TEXT EDITOR MENU ---\n";
        cout << "1. Type a character\n";
        cout << "2. Delete a character\n";
        cout << "3. Undo[cite: 4]\n";
        cout << "4. Redo[cite: 4]\n";
        cout << "5. Display current text\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            char c;
            cout << "Enter character to type: ";
            cin >> c;
            editor.type(c);
            break;
        }
        case 2:
            editor.remove();
            break;
        case 3:
            editor.undo();
            break;
        case 4:
            editor.redo();
            break;
        case 5:
            editor.display();
            break;
        case 6:
            cout << "Exiting text editor...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}