#include <bits/stdc++.h>
#define PRLIMIT 1000
#include "Primes.h"
using namespace std;

int main() {
	InitializePrimes(1000);
	
	long long max = 0, maxVal;
	FORi(a, -999, 1000) {
		for (int f = 0; Primes[f] < PRLIMIT; ++f) {
			long long b = Primes[f], z;
			for (z = 1; isPrime(z * z + a * z + b); ++z);
			if (z > max) {
				max = z;
				maxVal = a * b;
			}
			b *= -1;
			for (z = 1; isPrime(z * z + a * z - b); ++z);
			if (z > max) {
				max = z;
				maxVal = a * b;
			}
		}
	}
	cout<<maxVal;
}