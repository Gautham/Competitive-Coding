#include <bits/stdc++.h>
#define PRLIMIT 100000
#include "Primes.h"
using namespace std;

int main() {
	InitializePrimes(PRLIMIT);
	int K[] = { 9, 8, 7, 6, 5, 4, 3, 2 , 1};
	int *N = K + 2;
	int P, z = 7;
	bool flag = true;
	while (1) {
		do {
			P = 0;
			FORi(i, 0, z) P = P * 10 + N[i];
			if (isPrime(P)) break;
		} while (prev_permutation(N, N + z));
		if (isPrime(P)) break;
		N = N + 1;
		--z;
	}
	cout<<P;
	return 0;
}