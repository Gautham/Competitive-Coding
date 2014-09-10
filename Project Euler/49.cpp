#include <bits/stdc++.h>
#define PRLIMIT 10000
#include "Primes.h"
using namespace std;

int main() {
	InitializePrimes(PRLIMIT);

	int i = 20;
	int A[4];
	while (Primes[++i] < 1000);
	int X = Primes[i], Y = 0, Z = 0, count = 1;
	while (!Z) {
		A[0] = X / 1000;
		A[1] = X / 100 % 10;
		A[2] = X / 10 % 10;
		A[3] = X % 10;
		do {
			int N = A[0] * 1000 + A[1] * 100 + A[2] * 10 + A[3];
			if (N == X || N == Y || N == Z) continue;
			if (isPrime(N)) {				
				if (Y) Z = N;
				else Y = N;
			}
		} while (next_permutation(A, A + 4));
		if (Y && Z && (2 * Y == X + Z)) cout<<X<<Y<<Z;
		else Y = Z = 0;
		X = Primes[++i];
	}
	return 0;
}
