#include<iostream>
using namespace std;

class temperatureLoc {
	int tempDegree;

public:

	temperatureLoc() {
		cout << "Enter a positive integer: ";
		cin >> tempDegree;
	}
	void operator -() {
		tempDegree = -tempDegree;
	}

	void display() {
		cout << "The Negative integer is  " << tempDegree << endl;
		return;
	}

};

int main() {
	temperatureLoc loc;
	-loc;
	loc.display();
	return 0;
}