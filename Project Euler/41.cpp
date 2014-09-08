#include <iostream>
#include <math.h>
#include <bitset>
#include <algorithm>
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
			for (int j =  3 * i; j < 1000001; j += 2 * i) {
				PrimeBits[j] = false;
			}
		}
	}

	int K[] = { 9, 8, 7, 6, 5, 4, 3, 2 , 1};
	int *N = K + 2;
	int P, z = 7;
	bool flag = true;
	while (1) {
		do {
			P = 0;
			for (int i = 0; i < z; ++i) P = P * 10 + N[i];
			if (isPrime(P)) break;
		} while (prev_permutation(N, N + z));
		if (isPrime(P)) break;
		N = N + 1;
		--z;
	}
	cout<<P;
	return 0;
}