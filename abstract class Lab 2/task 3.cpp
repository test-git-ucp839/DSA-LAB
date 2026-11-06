//#include<iostream>
//using namespace std;
//
//class employee {
//public:
//	virtual double calculatesalary() = 0;
//};
//class fulltimeemployee : public employee {
//private:
//	double fixedsalary;
//public:
//	fulltimeemployee(double salary) {
//		fixedsalary = salary;
//	}
//	double calculatesalary() {
//		return fixedsalary;
//	}
//};
//class parttimeemployee : public employee {
//private:
//	int hoursworked;
//	double hourlyrate;
//public:
//	parttimeemployee(int hours, double rate) {
//		hoursworked = hours;
//		hourlyrate = rate;
//	}
//	double calculatesalary() {
//		return hoursworked * hourlyrate;
//	}
//};
//int main()
//{
//	fulltimeemployee fulltime(50000);
//	parttimeemployee parttime(80, 500);
//
//	cout << " FULL-TIME EMPLOYEE SALARY: " 
//		<< fulltime.calculatesalary() << endl;
//
//	cout << " PART-TIME EMPLOYEE SALARY: "
//		<< parttime.calculatesalary() << endl;
//
//	return 0;
//}