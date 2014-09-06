#include <iostream>
#include <math.h>
#include <bitset>
#include <vector>
using namespace std;

bitset<14500> PrimeBits;
vector<int> Primes;
int PrimeCount;

int SumOfProperDivisors(int n) {
	int S = 1, bak = n;
	for (int i = 0; i < PrimeCount && Primes[i] <= bak / 2; ++i) {
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
	for (int i = 4; i < 14500; i += 2) PrimeBits[i] = false;
	for (int i = 3; i < 14500; i += 2) {
		if (PrimeBits[i]) {
			Primes.push_back(i);
			++PrimeCount;
			for (int j = 3 * i; j < 14500; j += 2 * i) {
				PrimeBits[j] = false;
			}
		}
	}
	vector<int> AbundantNumbers;
	bitset<28124> Num;
	long long S = 0;
	for (int i = 12; i < 28124; ++i) {		
		int t = SumOfProperDivisors(i);
		if (t > i) {
			AbundantNumbers.push_back(i);
			t = AbundantNumbers.size();
			for (int j = 0; j < t; ++j) {
				if (AbundantNumbers[j] + i < 28124) Num[AbundantNumbers[j] + i] = true;
			}
		}
	}
	AbundantNumbers.clear();
	for (int i = 1; i < 28124; ++i) {
		if (!Num[i]) {
			S += i;
		}
	}
	cout<<S;
	return 0;
}