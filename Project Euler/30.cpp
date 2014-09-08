#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int A[10] = { 0, 1, 32, 243, pow(4, 5), pow(5, 5), pow(6, 5), pow(7, 5), pow(8, 5), pow(9, 5) }, Sum = 0;
	int n = 5 * A[9];
	for (int i = 33; i <= n; ++i) {
		int t = i, S = 0;
		while (t > 0) {
			S += A[t % 10];
			t /= 10;
		}
		if (S == i) Sum += i;
	}
	cout<<Sum;
	return 0;
}