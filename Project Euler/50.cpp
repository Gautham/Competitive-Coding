#include <bits/stdc++.h>
#include "Primes.h"
using namespace std;

vector<_ll> PrimeSum;

int main() {
	InitializePrimes(PRLIMIT);
	
	PrimeSum.push_back(0);
	FORi(i, 0, PrimeCount) PrimeSum.push_back(PrimeSum[i] + Primes[i]);
	int maxL = 0, T;
	for (int i = 1; i <= PrimeCount; ++i) {
		for (int j = i - 1; j >= 0 && (PrimeSum[i] - PrimeSum[j] < PRLIMIT); --j) {
			if (isPrime(PrimeSum[i] - PrimeSum[j])) {
				if (i - j > maxL) {
					maxL = i - j;
					T = PrimeSum[i] - PrimeSum[j];
				}
			}
		}
	}
	cout<<T;
	return 0;
}
