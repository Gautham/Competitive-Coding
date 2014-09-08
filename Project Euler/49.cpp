#include <iostream>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <vector>
using namespace std;

bitset<10001> PrimeBits;
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
	for (int i = 4; i < 10000; i += 2) PrimeBits[i] = false;
	for (int i = 3; i < 10000; i += 2) {
		if (PrimeBits[i]) {
			Primes.push_back(i);
			++PrimeCount;
			for (int j =  3 * i; j < 10000; j += 2 * i) {
				PrimeBits[j] = false;
			}
		}
	}
	int i = 20;
	int A[4];
	while (Primes[++i] < 1000);
	int X = Primes[i], Y = 0, Z = 0, count = 1;
	while (!Z) {
		A[0] = X / 1000;
		A[1] = X / 100 % 10;
		A[2] = X / 10 % 10;
		A[3] = X % 10;
		do {
			int N = A[0] * 1000 + A[1] * 100 + A[2] * 10 + A[3];
			if (N == X || N == Y || N == Z) continue;
			if (PrimeBits[N]) {				
				if (Y) Z = N;
				else Y = N;
			}
		} while (next_permutation(A, A + 4));
		if (Y && Z && (2 * Y == X + Z)) cout<<X<<Y<<Z;
		else Y = Z = 0;
		X = Primes[++i];
	}
	return 0;
}
