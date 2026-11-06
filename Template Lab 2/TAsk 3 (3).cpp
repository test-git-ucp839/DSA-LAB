cpp
```

#include <iostream>
#include <string>
using namespace std;

class Publication {
public:
    virtual void display() = 0;
    virtual ~Publication() {}
};

class Book : public Publication {
    string title;
    string author;
    int pages;

public:
    Book() {
        title = "";
        author = "";
        pages = 0;
    }

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getPages() const {
        return pages;
    }

    void display() override {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

class Newspaper : public Publication {
    string name;
    string date;
    string edition;

public:
    Newspaper() {
        name = "";
        date = "";
        edition = "";
    }

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getName() const {
        return name;
    }

    string getDate() const {
        return date;
    }

    string getEdition() const {
        return edition;
    }

    void display() override {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};

template <class T, class Key>
int linearSearch(T arr[], int size, Key key,
    bool (*match)(const T&, const Key&)) {
    for (int i = 0; i < size; i++) {
        if (match(arr[i], key)) {
            return i;
        }
    }
    return -1;
}

template <class T, class Key>
int binarySearch(T arr[], int size, Key key,
    int (*compare)(const T&, const Key&)) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int result = compare(arr[mid], key);

        if (result == 0) {
            return mid;
        }
        else if (result < 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

template <class T>
void bubbleSort(T arr[], int size,
    bool (*greater)(const T&, const T&)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (greater(arr[j], arr[j + 1])) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool bookPagesGreater(const Book& a, const Book& b) {
    return a.getPages() > b.getPages();
}

bool newspaperEditionGreater(const Newspaper& a,
    const Newspaper& b) {
    return a.getEdition() > b.getEdition();
}

bool matchBookTitle(const Book& b, const string& title) {
    return b.getTitle() == title;
}

bool matchNewspaperName(const Newspaper& n, const string& name) {
    return n.getName() == name;
}

int compareBookTitle(const Book& b, const string& title) {
    if (b.getTitle() < title) return -1;
    if (b.getTitle() > title) return 1;
    return 0;
}

int compareNewspaperName(const Newspaper& n, const string& name) {
    if (n.getName() < name) return -1;
    if (n.getName() > name) return 1;
    return 0;
}

class Library {
    Book books[100];
    Newspaper newspapers[100];
    int bookCount;
    int newspaperCount;

public:
    Library() {
        bookCount = 0;
        newspaperCount = 0;
    }

    void addBook(Book b) {
        if (bookCount < 100) {
            books[bookCount++] = b;
        }
    }

    void addNewspaper(Newspaper n) {
        if (newspaperCount < 100) {
            newspapers[newspaperCount++] = n;
        }
    }

    void sortBooksByPages() {
        bubbleSort(books, bookCount, bookPagesGreater);
    }

    void sortNewspapersByEdition() {
        bubbleSort(newspapers, newspaperCount,
            newspaperEditionGreater);
    }

    void displayCollection() {
        cout << "\n--- Books ---\n";
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
            cout << endl;
        }

        cout << "--- Newspapers ---\n";
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
            cout << endl;
        }
    }

    Book* searchBookByTitle(string title) {
        int index = linearSearch(
            books, bookCount, title, matchBookTitle
        );

        if (index != -1) {
            return &books[index];
        }
        return nullptr;
    }

    Newspaper* searchNewspaperByName(string name) {
        int index = linearSearch(
            newspapers, newspaperCount, name,
            matchNewspaperName
        );

        if (index != -1) {
            return &newspapers[index];
        }
        return nullptr;
    }

    Book* binarySearchBookByTitle(string title) {
        bubbleSort(books, bookCount,
            [](const Book& a, const Book& b) {
                return a.getTitle() > b.getTitle();
            });

        int index = binarySearch(
            books, bookCount, title, compareBookTitle
        );

        if (index != -1) {
            return &books[index];
        }
        return nullptr;
    }

    Newspaper* binarySearchNewspaperByName(string name) {
        bubbleSort(newspapers, newspaperCount,
            [](const Newspaper& a, const Newspaper& b) {
                return a.getName() > b.getName();
            });

        int index = binarySearch(
            newspapers, newspaperCount, name,
            compareNewspaperName
        );

        if (index != -1) {
            return &newspapers[index];
        }
        return nullptr;
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13",
        "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12",
        "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook =
        library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    Newspaper* foundNewspaper =
        library.searchNewspaperByName("The Times");

    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    Book* binaryBook =
        library.binarySearchBookByTitle("The Catcher in the Rye");

    if (binaryBook) {
        cout << "\nBook found using Binary Search:\n";
        binaryBook->display();
    }
    else {
        cout << "\nBook not found using Binary Search.\n";
    }

    return 0;
}
```