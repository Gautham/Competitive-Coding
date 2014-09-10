#include <bits/stdc++.h>
#define PRLIMIT 2000000LL
#include "Primes.h"
using namespace std;

int main() {
	InitializePrimes(PRLIMIT);
	_ll S = 0;
	FORi(i, 0, PrimeCount) S += Primes[i];
	cout<<S;
	return 0;
}