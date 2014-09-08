#include <iostream>
#include <math.h>
using namespace std;

bool isPentagonal(int n) {
	long double t = (1 + sqrt(1 + 24 * n)) / 6;
	int u = t;
	return (t - (long double)u < 0.00000001);
}

int main() {
	bool flag = true;
	int i = 2;
	while (flag) {
		int m = i * (3 * i - 1) / 2;
		for (int j = i - 1; j > 0; --j) {
			int n = j * (3 * j - 1) / 2;
			if (isPentagonal(m - n) && isPentagonal(m + n)) {
				flag = false;
				cout<<m - n;
				break;
			}
		}
		++i;
	}
}
