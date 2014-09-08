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
