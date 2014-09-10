#include <bits/stdc++.h>
#define PRLIMIT 100
#include "Primes.h"
using namespace std;

int SumOfProperDivisors(int n) {
	int S = 1, bak = n;
	for (int i = 0; i < PrimeCount && Primes[i] <= n; ++i) {
		int z = 0, t = 1;
		while (n % Primes[i] == 0) {
			t += pow(Primes[i], ++z);
			n /= Primes[i];
		}
		S *= t;
	}
	if (n > 1) S *= (1 + n);
	S -= bak;
	return S;
}

int main() {
	InitializePrimes(PRLIMIT);

	int A[10000] = {0};
	long long S = 0;
	FORi(i, 3, 10000) {
		A[i] = SumOfProperDivisors(i);
		if (A[i] < i && A[A[i]] == i) {
			S += i + A[i];
		}
	}
	cout<<S;
}