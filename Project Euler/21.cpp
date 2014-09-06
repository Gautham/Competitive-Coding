#include <iostream>
#include <math.h>
#include <bitset>
#include <vector>
using namespace std;

bitset<5000> PrimeBits;
vector<int> Primes;
int PrimeCount;

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
	S -= bak;
	return S;
}

int main() {
	Primes.push_back(2);
	PrimeCount = 1;
	PrimeBits.flip();
	PrimeBits[0] = PrimeBits[1] = PrimeBits[4] = false;
	for (int i = 4; i < 5000; i += 2) PrimeBits[i] = false;
	for (int i = 3; i < 5000; i += 2) {
		if (PrimeBits[i]) {
			Primes.push_back(i);
			++PrimeCount;
			for (int j = 3 * i; j < 5000; j += 2 * i) {
				PrimeBits[j] = false;
			}
		}
	}
	int A[10000] = {0};
	long long S = 0;
	for (int i = 3; i < 10000; ++i) {
		A[i] = SumOfProperDivisors(i);
		if (A[i] < i && A[A[i]] == i) {
			S += i + A[i];
		}
	}
	cout<<S;
}