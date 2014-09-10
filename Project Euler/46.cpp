#include <bits/stdc++.h>
#define PRLIMIT 10000
#include "Primes.h"
#include <tr1/unordered_set>
using namespace std;

int main() {
	InitializePrimes(PRLIMIT);

	tr1::unordered_set<int> SquaresTimesTwo;
	FORi(i, 1, 50) SquaresTimesTwo.insert(i * i << 1);
	for (int i = 35; i < 1000001; i += 2) {
		bool flag = false;
		if (isPrime(i)) continue;
		for (int j = 0; j < PrimeCount && Primes[j] <= i; ++j) {
			if (SquaresTimesTwo.count(i - Primes[j])) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout<<i;
			break;
		}
	}
	return 0;
}