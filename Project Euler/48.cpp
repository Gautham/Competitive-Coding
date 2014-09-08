#include <iostream>
#include <limits>
using namespace std;

long long MulMod(long long a, long long b, long long m) {
	long long res = 0;
	while (a != 0) {
		if (a & 1) res = (res + b) % m;
		a >>= 1;
		b = (b << 1) % m;
	}
	return res;
}


long long powMod(long long T, long long N, long long M) {
	long long Z = 1;
	while (N > 1) {
		long long P = T % M, a = 1, t = 0;
		while (a < N) {
			a <<= 1;
			++t;
		}
		if (a > N) {
			a >>= 1;
			--t;
		}
		N -= a;
		while (t--) {
			P = MulMod(P, P, M);
		}
		Z = MulMod(Z, P, M);
	}
	if (N == 1) Z = MulMod(Z, T, M);
	return Z;
}


int main() {
	long long S = 0;
	for (int i = 1; i <= 1000; ++i) {
		long long t = powMod(i, i, 10000000000LL);
		S += powMod(i, i, 10000000000LL);
		S %= 10000000000LL;
	}
	cout<<(long long)S % 10000000000LL;
	return 0;
}