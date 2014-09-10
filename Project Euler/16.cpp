#include <iostream>
using namespace std;

int main() {
	char A[350] = {0};
	int n = 1;
	A[0] = 1;
	for (int i = 0; i < 100; ++i) {
		int carry = 0, j = 0;
		for (; j < n; ++j) {
			int t = A[j] * 1024 + carry;
			carry = t / 10;
			A[j] = t % 10;
		}
		while (carry) {
			++n;
			A[j++] = carry % 10;
			carry /= 10;
		}
	}
	int S = 0;
	for (int i = 0; i < n; ++i) {
		S += A[i];
	}
	cout<<S;
}