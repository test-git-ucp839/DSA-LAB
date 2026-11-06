//#include<iostream>
//using namespace std;
//
//class employee {
//public:
//    virtual void calculatesalary() = 0;
//};
//
//class fulltimeemployee : public employee {
//    int fixedsalary;
//
//public:
//    fulltimeemployee(int fs) {
//        fixedsalary = fs;
//    }
//
//    void calculatesalary() {
//        cout << "salary:" << fixedsalary << endl;
//    }
//
//    void display() {
//        cout << "Fixed Salary" << fixedsalary << endl;
//    }
//};
//
//class parttimesalary : public employee {
//    int hour;
//    int hourrate;
//    int totalsalary;
//
//public:
//
//    parttimesalary(int h, int hr) {
//        hour = h;
//        hourrate = hr;
//        totalsalary = 0;
//    }
//
//    void calculatesalary() {
//        totalsalary = hour * hourrate;
//    }
//
//    void displayparttime () {
//        cout << "Hours:" << hour << endl;
//        cout << "Hour Rate:" << hourrate << endl;
//        cout << "Total Salary:" << totalsalary << endl;
//    }
//};
//
//int main() {
//
//    fulltimeemployee f1(1432);
//
//    f1.calculatesalary();
//    f1.display();
//
//    parttimesalary p1(12, 700);
//    p1.calculatesalary();
//    p1.displayparttime();
//    return 0;
//}