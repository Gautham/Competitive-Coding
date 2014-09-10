#include <bits/stdc++.h>
#define PRLIMIT 65536
#include "Primes.h"
using namespace std;


int main() {
	InitializePrimes(PRLIMIT);

	int n = 28, d = 8;
	while (1) {
		int bak = n;
		vector<int> PF;
		FORi(i, 0, PrimeCount) {
			int z = 0;
			while (n % Primes[i] == 0) {
				++z;
				n /= Primes[i];
			}
			if (z > 0) PF.push_back(z + 1);
			z = 0;
		}
		n = bak;
		if (!PF.empty()) {
			int t = PF.size(), f = 1;
			FORi(i, 0, t) {
				f *= PF[i];				
			}
			if (f > 500) {
				cout<<n;
				break;
			}
		}
		n += d++;
	}
	return 0;
}