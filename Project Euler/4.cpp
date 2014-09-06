#include <iostream>
using namespace std;

bool isPalindrome(int a) {	
	int t = 0, p = a;
	while (a > 0) {
		t = t * 10 + (a % 10);
		a /= 10;
	}
	return (t == p);
}

int main() {
	int a = 1000, b, d, L = 0;
	while (--a) {
		if (a % 11) {
			b = 990;
			d = 11;
		} else {
			b = 999;
			d = 1;
		}
		while (b >= a) {
			if ((a * b > L) && isPalindrome(a * b)) {
				L = a * b;
				break;
			}
			b -= d;
		}
	}
	cout<<L;
}