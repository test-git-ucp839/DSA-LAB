//#include <iostream>
//#include <string>
//using namespace std;
//
//class LibraryItem {
//public:
//    virtual void display() = 0;
//};
//class Book : public LibraryItem {
//public:
//    string title, author;
//    int pages;
//    Book() {
//        title = "";
//        author = "";
//        pages = 0;
//    }
//    Book(string t, string a, int p) {
//        title = t;
//        author = a;
//        pages = p;
//    }
//    void display() {
//        cout << "Title: " << title << endl;
//        cout << "Author: " << author << endl;
//        cout << "Pages: " << pages << endl;
//    }
//};
//class Newspaper : public LibraryItem {
//public:
//    string name, date, edition;
//    Newspaper() {
//        name = "";
//        date = "";
//        edition = "";
//    }
//    Newspaper(string n, string d, string e) {
//        name = n;
//        date = d;
//        edition = e;
//    }
//    void display() {
//        cout << "Name: " << name << endl;
//        cout << "Date: " << date << endl;
//        cout << "Edition: " << edition << endl;
//    }
//};
//template <class T>
//T* linearSearch(T arr[], int n, string key) {
//    for (int i = 0; i < n; i++) {
//        if (arr[i].name == key)
//            return &arr[i];
//    }
//    return NULL;
//}
//template <class T>
//T* binarySearch(T arr[], int n, string key) {
//    int left = 0, right = n - 1;
//    while (left <= right) {
//        int mid = (left + right) / 2;
//        if (arr[mid].title == key) {
//            return &arr[mid];
//        }
//        if (arr[mid].title < key) {
//            left = mid + 1;
//        }
//        else
//            right = mid - 1;
//    }
//
//    return NULL;
//}
//class Library {
//public:
//    Book books[10];
//    Newspaper papers[10];
//    int b = 0, n = 0;
//
//    void addBook(Book x) {
//        if (b < 10)
//            books[b++] = x;
//    }
//    void addNewspaper(Newspaper x) {
//        if (n < 10)
//            papers[n++] = x;
//    }
//    void displayCollection() {
//        for (int i = 0; i < b; i++)
//            books[i].display();
//
//        for (int i = 0; i < n; i++)
//            papers[i].display();
//    }
//    void sortBooksByPages() {
//        for (int i = 0; i < b - 1; i++) {
//            for (int j = 0; j < b - i - 1; j++) {
//                if (books[j].pages > books[j + 1].pages) {
//                    Book temp = books[j];
//                    books[j] = books[j + 1];
//                    books[j + 1] = temp;
//                }
//            }
//        }
//    }
//    void sortNewspapersByEdition() {
//        for (int i = 0; i < n - 1; i++) {
//            for (int j = 0; j < n - i - 1; j++) {
//                if (papers[j].edition > papers[j + 1].edition) {
//                    Newspaper temp = papers[j];
//                    papers[j] = papers[j + 1];
//                    papers[j + 1] = temp;
//                }
//            }
//        }
//    }
//    Book* searchBookByTitle(string title) {
//        for (int i = 0; i < b - 1; i++) {
//            for (int j = 0; j < b - i - 1; j++) {
//                if (books[j].title > books[j + 1].title) {
//                    Book temp = books[j];
//                    books[j] = books[j + 1];
//                    books[j + 1] = temp;
//                }
//            }
//        }
//        return binarySearch(books, b, title);
//    }
//    Newspaper* searchNewspaperByName(string name) {
//        return linearSearch(papers, n, name);
//    }
//};
//int main() {
//    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
//    Book book2("To Kill a Mockingbird", "Harper Lee", 324);
//
//    Newspaper paper1("Washington Post", "2024-10-13",
//        "Morning Edition");
//    Newspaper paper2("The Times", "2024-10-12",
//        "Weekend Edition");
//
//    Library library;
//    library.addBook(book1);
//    library.addBook(book2);
//    library.addNewspaper(paper1);
//    library.addNewspaper(paper2);
//
//    cout << "Before Sorting:\n";
//    library.displayCollection();
//
//    library.sortBooksByPages();
//    library.sortNewspapersByEdition();
//
//    cout << "\nAfter Sorting:\n";
//    library.displayCollection();
//
//    Book* foundBook =
//        library.searchBookByTitle("The Catcher in the Rye");
//
//    if (foundBook != NULL) {
//        cout << "\nFound Book:\n";
//        foundBook->display();
//    }
//    else {
//        cout << "Book not found\n";
//    }
//    Newspaper* foundPaper =
//        library.searchNewspaperByName("The Times");
//    if (foundPaper != NULL) {
//        cout << "\nFound Newspaper:\n";
//        foundPaper->display();
//    }
//    else {
//        cout << "Newspaper not found\n";
//    }
//
//    return 0;
//}