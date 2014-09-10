#include <bits/stdc++.h>
#define PRLIMIT 1000
#include "Primes.h"
#include <tr1/unordered_set>
using namespace std;

int NoOfFactors(int n) {
	tr1::unordered_set<int> A;
	for (int j = 0; j < PrimeCount && Primes[j] <= n; ++j) {
		while (n % Primes[j] == 0) {
			A.insert(Primes[j]);
			n /= Primes[j];
		}
	}
	if (n > 1) A.insert(n);
	return A.size();
}

bool hasFourFactors(int n) {
	return (NoOfFactors(n) == 4);
}

int main() {
	InitializePrimes(PRLIMIT);

	for (int T = 211; T < 1000000; ++T) {
		int count = 0, Z = T;
		bool flag = true;
		while (flag) {
			if (hasFourFactors(T)) {
				++T;
				++count;
				if (count == 4) flag = false;
			} else {
				count = 0;
				flag = false;
			}
		}
		if (count == 4) {
			cout<<Z;
			break;
		}
	}
}