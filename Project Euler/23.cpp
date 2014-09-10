#include <bits/stdc++.h>
#define PRLIMIT 170
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
	InitializePrimes(170);

	vector<int> AbundantNumbers;
	bitset<28124> Num;
	long long S = 0;
	int N = 0;
	for (int i = 12; i < 28124; ++i) {		
		int t = SumOfProperDivisors(i);
		if (t > i) {
			AbundantNumbers.push_back(i);
			++N;			
			for (int j = 0; j < N; ++j) {
				if (AbundantNumbers[j] + i < 28124) Num[AbundantNumbers[j] + i] = true;
			}
		}
	}
	AbundantNumbers.clear();
	for (int i = 1; i < 28124; ++i) {
		if (!Num[i]) {
			S += i;
		}
	}
	cout<<S;
	return 0;
}