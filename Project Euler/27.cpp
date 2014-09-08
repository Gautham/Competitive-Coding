#include <iostream>
#include <math.h>
#include <bitset>
#include <vector>
using namespace std;

bitset<100000> PrimeBits;
vector<int> Primes;
int PrimeCount;

bool isPrime(long long p) {
	if (p <= 1) return false;
	if (p <= Primes[PrimeCount - 1]) return PrimeBits[p];
	long long n = sqrt(p) + 1, i;
	for (i = 0; i < PrimeCount && Primes[i] < n && p % Primes[i]; ++i);
	return (p % Primes[i]) ? true : false;

}

int main() {
	Primes.push_back(2);
	PrimeCount = 1;
	PrimeBits.flip();
	PrimeBits[0] = PrimeBits[1] = PrimeBits[4] = false;
	for (int i = 4; i < 100000; i += 2) PrimeBits[i] = false;
	for (int i = 3; i < 100000; i += 2) {
		if (PrimeBits[i]) {
			Primes.push_back(i);
			++PrimeCount;
			for (int j = 3 * i; j < 100000; j += 2 * i) {
				PrimeBits[j] = false;
			}
		}
	}
	long long max = 0, maxVal;
	for (int a = -999; a < 1000; ++a) {
		for (int f = 0; Primes[f] < 1000; ++f) {
			long long b = Primes[f], z;
			for (z = 1; isPrime(z * z + a * z + b); ++z);
			if (z > max) {
				max = z;
				maxVal = a * b;
			}
			b *= -1;
			for (z = 1; isPrime(z * z + a * z - b); ++z);
			if (z > max) {
				max = z;
				maxVal = a * b;
			}
		}
	}
	cout<<maxVal;
}