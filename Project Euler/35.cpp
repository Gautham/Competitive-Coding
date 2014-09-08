#include <iostream>
#include <math.h>
#include <bitset>
#include <vector>
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
			for (int j = 3 * i; j < 1000001; j += 2 * i) {
				PrimeBits[j] = false;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < PrimeCount; ++i) {
		bool flag = false;
		int T = Primes[i], n = ceil(log10(Primes[i]));
		int z = pow(10, n - 1);
		for (int j = 1; j < n; ++j) {
			T = (T % z) * 10 + (T / z);
			if (!isPrime(T)) {
				flag = true;
				break;
			}
		}
		if (!flag) ++count;
	}
	cout<<count;
	return 0;
}
