#include <bits/stdc++.h>
#include <tr1/unordered_set>
#include "Primes.h"
using namespace std;

int main() {
	InitializePrimes(PRLIMIT);

	long long Sum = 0;
	tr1::unordered_set<int> P;
	for (int i = 4; i < PrimeCount; ++i) {
		bool flag = true;
		int t =  Primes[i] / 10, u = 1;
		while (t > 0) {
			if (!PrimeBits[t]) {
				flag = false;
				break;
			}
			u *= 10;
			t /= 10;
		}
		if (!flag) continue;	
		t = Primes[i] % u;
		u /= 10;
		while (t > 0) {
			if (!PrimeBits[t]) {
				flag = false;
				break;
			}			
			t %= u;
			u /= 10;
		}
		if (!flag) continue;
		if (P.count(Primes[i]) == 0) {
			Sum += Primes[i];
			P.insert(Primes[i]);
		}
	}
	cout<<Sum;
	return 0;
}
