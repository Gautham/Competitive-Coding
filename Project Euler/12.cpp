#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<int> Primes;
int PrimeCount;

bool isPrime(int p) {
	int n = sqrt(p) + 1, i;
	for (i = 0; i < PrimeCount && Primes[i] < n && p % Primes[i]; ++i);
	return (p % Primes[i]) ? true : false;

}
int main() {
	Primes.push_back(2);
	Primes.push_back(3);
	Primes.push_back(5);
	Primes.push_back(7);
	PrimeCount = 4;
	for (int i = 11; ; i += 6) {
		int j = i + 2;
		if (isPrime(i)) {
			Primes.push_back(i);
			++PrimeCount;
			if (i >= 65536) break;
		}
		if (isPrime(j)) {
			Primes.push_back(j);
			++PrimeCount;
			if (j >= 65536) break;
		}
	}
	int n = 28, d = 8;
	while (1) {
		int bak = n;
		vector<int> PF;
		for (int i = 0; i < PrimeCount; ++i) {
			int z = 0;
			while (n % Primes[i] == 0) {
				++z;
				n /= Primes[i];
			}
			if (z > 0) PF.push_back(z + 1);
			z = 0;
		}
		n = bak;
		if (!PF.empty()) {
			int t = PF.size(), f = 1;
			for (int i = 0; i < t; ++i) {
				f *= PF[i];
			}
			if (f > 500) {
				cout<<n;
				break;
			}
		}
		n += d++;
	}
	return 0;
}