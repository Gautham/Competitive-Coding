#include <iostream>
#include <math.h>
using namespace std;

int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	int count = 0, year = 1901, day = 1 + (365 % 7), month = 0;
	while (year < 2001) {
		if (!day) ++count;
		day += Months[month];
		if (month++ == 1 && year % 4 == 0) ++day;
		day %= 7;
		if (month == 12) {
			++year;
			month = 0;
		}
	}
	cout<<count;
}