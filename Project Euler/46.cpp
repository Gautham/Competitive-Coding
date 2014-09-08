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

	tr1::unordered_set<int> SquaresTimesTwo;
	for (int i = 1; i < 50; ++i) {
		SquaresTimesTwo.insert(i * i << 1);
	}
	for (int i = 35; i < 1000001; i += 2) {
		bool flag = false;
		if (PrimeBits[i]) continue;
		for (int j = i - 2; j > 2; j -= 2) {
			if (PrimeBits[j]) {
				if (SquaresTimesTwo.count(i - j)) {
					flag = true;
					break;
				}
			}
		}
		if (!flag) {
			cout<<i;
			break;
		}
	}
	return 0;
}