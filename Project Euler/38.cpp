#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;

bool isPandigital(int N) {
	int p = ceil(log10(N));
	bitset<10> P;
	P.flip();
	P[0] = false;
	for (int i = p + 1; i < 10; ++i) P[i] = false;
	while (N > 0) {
		int t = N % 10;
		if (t > p) return false;
		P[t] = false;
		N /= 10;
	}
	return !P.any();
}

int main() {
	for (int i = 9999; i >= 9000; --i) {
		int N = i * 2;
		N += i * pow(10, ceil(log10(N)));
		if (isPandigital(N)) {
			cout<<N;
			break;
		}
	}
	return 0;
}