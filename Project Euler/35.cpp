#include <bits/stdc++.h>
#include "Primes.h"
using namespace std;

int main() {
	InitializePrimes(PRLIMIT);

	int count = 0;
	FORi(i, 0, PrimeCount) {
		bool flag = false;
		int T = Primes[i], n = ceil(log10(Primes[i]));
		int z = pow(10, n - 1);
		FORi(j, 1, n) {
			T = (T % z) * 10 + (T / z);
			if (!isPrime(T)) {
				flag = true;
				break;
			}
		}
		if (!flag) ++count;
	}
	cout<<count;
	return 0;
}
