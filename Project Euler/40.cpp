#include <iostream>
using namespace std;

int getDigit(int n) {
	if (n < 10) {
		return n;
	}
	if (n < 190) {
		int t = (n - 8) / 2;
		t += 9;
		if (n % 2 == 0) {
			return (t % 10);
		} else {
			return (t / 10);
		}
	}
	if (n < 2890) {
		int t = (n - 187) / 3;
		t += 99;
		switch (n % 3) {
			case 0:
				return (t % 10);
			case 1:
				return (t / 100);
			case 2:
				return (t / 10 % 10);
		}
	}
	if (n < 9000 * 4 + 2890) {
		int t = (n - 2890 + 4) / 4;
		t += 999;
		switch (n % 4) {
			case 0:
				return (t / 10 % 10);
			case 1:
				return (t % 10);
			case 2:
				return (t / 1000);
			case 3:
				return (t / 100 % 10);
		}
	}
	if (n < 90000 * 5 + 9000 * 4 + 2890) {
		int t = (n - (9000 * 4 + 2890) + 5) / 5;
		t += 9999;
		switch (n % 5) {
			case 0:
				return (t / 10000);
			case 1:
				return (t / 1000 % 10);
			case 2:
				return (t / 100 % 10);
			case 3:
				return (t / 10 % 10);
			case 4:
				return (t % 10);
		}
	}
	int t = (n - (90000 * 5 + 9000 * 4 + 2890) + 6) / 6;
	t += 99999;
	switch (n % 6) {
		case 0:
			return (t / 1000 % 10);
		case 1:
			return (t / 100 % 10);
		case 2:
			return (t / 10 % 10);
		case 3:
			return (t % 10);
		case 4:
			return (t / 100000);
		case 5:
			return (t / 10000 % 10);
	}	
}

int main() {
	int t = 1;
	for (int i = 1; i <= 1000000; i *= 10) t *= getDigit(i);
	cout<<t;
	return 0;
}