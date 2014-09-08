#include <iostream>
#include <math.h>
#include <bitset>
#include <vector>
#include <tr1/unordered_set>
using namespace std;

bitset<1000000> PrimeBits;
vector<int> Primes;
int PrimeCount;

bool isPrime(long long p) {
	if (p <= 1) return false;
	if (p <= Primes[PrimeCount - 1]) return PrimeBits[p];
	long long n = sqrt(p) + 1, i;
	for (i = 0; i < PrimeCount && Primes[i] < n && p % Primes[i]; ++i);
	if (i == PrimeCount || Primes[i] >= n) return true;
}

int NoOfFactors(int n) {
	tr1::unordered_set<int> A;
	for (int j = 0; j < PrimeCount && Primes[j] <= n; ++j) {
		while (n % Primes[j] == 0) {
			A.insert(Primes[j]);
			n /= Primes[j];
		}
	}	
	return A.size();
}

bool hasFourFactors(int n) {
	return (NoOfFactors(n) == 4);
}

int main() {
	Primes.push_back(2);
	PrimeCount = 1;
	PrimeBits.flip();
	PrimeBits[0] = PrimeBits[1] = PrimeBits[4] = false;
	for (int i = 4; i < 1000001; i += 2) PrimeBits[i] = false;
	for (int i = 3; i < 1000001; i += 2) {
		if (PrimeBits[i]) {
			Primes.push_back(i);
			++PrimeCount;
			for (int j =  3 * i; j < 1000001; j += 2 * i) {
				PrimeBits[j] = false;
			}
		}
	}

	for (int T = 211; T < 1000000; ++T) {
		int count = 0, Z = T;
		bool flag = true;
		while (flag) {
			if (NoOfFactors(T) == 4) {
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