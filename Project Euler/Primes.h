#include <bits/stdc++.h>
#define _ll long long
#define Max(a, b) (a > b) ? a : b
#define Min(a, b) (a < b) ? a : b
#define gcd __gcd
#define FOR(i, a, n) for (i = a; i < n; ++i)
#define FORe(i, a, n) for (i = a; i <= n; ++i)
#define FORi(i, a, n) for (int i = a; i < n; ++i)
#define FORie(i, a, n) for (int i = a; i <= n; ++i)		
using namespace std;

#ifndef PRLIMIT
	#define PRLIMIT 1000000
#endif

bitset<PRLIMIT + 1> PrimeBits;
vector<int> Primes;
int PrimeCount;

bool isPrime(_ll p) {
	if (p <= 1) return false;
	if (p <= Primes[PrimeCount - 1]) return PrimeBits[p];
	_ll n = sqrt(p) + 1, i;
	for (i = 0; i < PrimeCount && Primes[i] < n && p % Primes[i]; ++i);
	return (p % Primes[i]) ? true : false;
}

void InitializePrimes(int PRIME_LIMIT) {
	Primes.push_back(2);
	PrimeCount = 1;
	PrimeBits.flip();
	PrimeBits[0] = PrimeBits[1] = PrimeBits[4] = false;
	for (int i = 4; i < PRIME_LIMIT; i += 2) PrimeBits[i] = false;
	for (int i = 3; i < PRIME_LIMIT; i += 2) {
		if (PrimeBits[i]) {
			Primes.push_back(i);
			++PrimeCount;
			for (int j = 3 * i; j < PRIME_LIMIT; j += 2 * i) {
				PrimeBits[j] = false;
			}
		}
	}
}
