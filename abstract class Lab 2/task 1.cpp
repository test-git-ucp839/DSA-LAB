//#include<iostream>
//using namespace std;
//
//class course {
//public:
//	virtual void duration() = 0;
//	virtual void area() = 0;
//
//};
//class onlinecourse : public course {
//private:
//	int week;
//	int hoursperweek;
//public:
//	onlinecourse(int w, int h) {
//		week = w;
//		hoursperweek = h;
//	}
//	void duration() {
//		cout << " ONLINE COURSE DURATION: " << week 
//			<< " WEEKS " << endl;
//	}
//	void area() {
//		cout << " ONLINE COURSE TOTAL HOURS: " 
//			<< week * hoursperweek << endl;
//	}
//};
//class offlinecourse {
//private:
//	int month;
//	int hoursperday;
//public:
//	offlinecourse(int m, int h) {
//		month = m;
//		hoursperday = h;
//	}
//	void duration() {
//		cout << " OFFLINE COURSE DURATION: " << month 
//			<< " MONTHS " << endl;
//	}
//	void area() {
//		cout << " OFFLINE COURSE TOTAL HOURS (assuming30 days per month): "
//			<< month * 30 * hoursperday << endl;
//	}
//};
//
//int main() {
//	onlinecourse online(8, 3);
//	offlinecourse offline(2, 4);
//
//	online.duration();
//	online.area();
//
//	offline.duration();
//	offline.area();
//
//	return 0;
//}
