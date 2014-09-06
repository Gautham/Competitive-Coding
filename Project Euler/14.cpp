#include <iostream>
using namespace std;

int main() {
	long long A[1000000] = {0}, p = 1, q = 1, max = 1, maxVal = 1;
	while (p < 1000000) {
		A[p] = q++;
		p = p << 1;
	}
	p = 2;
	while (++p < 1000000) {
		long long t = p;
		q = 1;
		while ((t & (t - 1)) || t >= 1000000) {
			t = (t % 2) ? (3 * t + 1) : (t / 2);
			if (t < p) {
				q += A[t];
				t = 0;
				break;
			} else ++q;
		}
		q += A[t];
		A[p] = q;
		if (q > max) {
			max = q;
			maxVal = p;
		}
	}
	cout<<maxVal;
	return 0;
}