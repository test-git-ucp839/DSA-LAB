//#include<iostream>
//using namespace std;
//
//class course {
//public:
//    virtual void duration();
//};
//
//void course::duration() {
//    cout << "Course duration" << endl;
//}
//
//class onlinecourse : public course {
//    int week;
//    int hoursperweek;
//    int totalstudenthour;
//
//public:
//
//    onlinecourse(int w, int h) {
//        week = w;
//        hoursperweek = h;
//        totalstudenthour = 0;
//    }
//
//    void duration() override {
//        cout << "duration " << week << endl;
//    }
//
//    void area() {
//        totalstudenthour = week * hoursperweek;
//    }
//
//    void displayonline() {
//        cout << "WEEK:" << week << endl;
//        cout << "Hours Per Week:" << hoursperweek << endl;
//        cout << "Total Student hours:" << totalstudenthour << endl;
//    }
//};
//
//class offlinecourse : public course {
//    int month;
//    int hourperday;
//    int total;
//
//public:
//
//    offlinecourse(int m, int hday) {
//        month = m;
//        hourperday = hday;
//        total = 0;
//    }
//
//    void duration() override {
//        cout << "duration " << month << " months" << endl;
//    }
//
//    void area() {
//        total = month * hourperday;
//    }
//
//    void displayoffline() {
//        cout << "Month:" << month << endl;
//        cout << "Hours Per Day:" << hourperday << endl;
//        cout << "Total :" << total << endl;
//    }
//};
//
//int main() {
//
//    onlinecourse c1(4, 5);
//    c1.duration();
//    c1.area();
//    c1.displayonline();
//
//    return 0;
//}