#include <iostream>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <vector>
using namespace std;

bitset<1000001> PrimeBits;
vector<int> Primes;
vector<long long> PrimeSum;
int PrimeCount;

bool isPrime(long long p) {
	if (p <= 1) return false;
	if (p <= Primes[PrimeCount - 1]) return PrimeBits[p];
	long long n = sqrt(p) + 1, i;
	for (i = 0; i < PrimeCount && Primes[i] < n && p % Primes[i]; ++i);
	if (i == PrimeCount || Primes[i] >= n) return true;
}

int main() {
	Primes.push_back(2);
	PrimeCount = 1;
	PrimeSum.push_back(0);
	PrimeSum.push_back(2);
	PrimeBits.flip();
	PrimeBits[0] = PrimeBits[1] = PrimeBits[4] = false;
	for (int i = 4; i < 1000000; i += 2) PrimeBits[i] = false;
	for (int i = 3; i < 1000000; i += 2) {
		if (PrimeBits[i]) {
			Primes.push_back(i);
			PrimeSum.push_back(PrimeSum[PrimeCount] + (long long)i);
			++PrimeCount;
			for (int j =  3 * i; j < 1000000; j += 2 * i) {
				PrimeBits[j] = false;
			}
		}
	}
	int maxL = 0, T;
	for (int i = 1; i <= PrimeCount && Primes[i] < 1000000; ++i) {
		for (int j = i - 1; j >= 0 && (PrimeSum[i] - PrimeSum[j] < 1000000); --j) {
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
