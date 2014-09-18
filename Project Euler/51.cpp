#include <bits/stdc++.h>
#include <stdio.h>
#define _ll long long
#define Max(a, b) (a > b) ? a : b
#define Min(a, b) (a < b) ? a : b
#define gcd __gcd
#define FOR(i, a, n) for (i = a; i < n; ++i)
#define FORe(i, a, n) for (i = a; i <= n; ++i)
#define FORi(i, a, n) for (int i = a; i < n; ++i)
#define FORie(i, a, n) for (int i = a; i <= n; ++i)
#include "Primes.h"
using namespace std;

int main() {
	InitializePrimes(PRLIMIT);

	int i = lower_bound(Primes.begin(), Primes.end(), 100000) - Primes.begin();
	while (1) {
		int X = -1, N = Primes[i], A[10] = {0};
		char B[7];
		sprintf(B, "%d", N);
		FORi(j, 0, 6) A[B[j] -= '0'] += 1;
		FORi(j, 0, 3) {
			if (A[j] == 3) {
				X = j;
				break;
			}
		}

		if (B[5] != X) {
			int I = 0, t = 10, count = 1;
			for (int j = 4; j >= 0; --j) {
				if (B[j] == X) I += t;
				t *= 10;
			}
			FORi(j, X + 1, 10) {
				N += I;
				if (isPrime(N)) ++count;
			}
			if (count == 8) break;
		}
		++i;
	}
	cout<<Primes[i];
	return 0;
}