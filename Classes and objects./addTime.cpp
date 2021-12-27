#include<iostream>
using namespace std;

class tim {
public:
	int min, hr;
	void get() {
		cout << "Enter the Hours and minutes : ";
		cin >> hr >> min;
	}
	void display() {
		cout << "Time is " << hr << ":" << min;
	}
	void addTime(tim t1, tim t2 ) {
		min = t1.min + t2.min;
		hr = min / 60;
		min = min % 60;
		hr += t1.hr + t2.hr;
		display();
	}
};

int main() {
	tim t1, t2, t3;
	t1.get();
	t2.get();
	t3.addTime(t1, t2);

}