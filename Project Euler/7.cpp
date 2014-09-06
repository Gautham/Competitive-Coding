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
			if (PrimeCount == 10001) break;
		}
		if (isPrime(j)) {
			Primes.push_back(j);
			++PrimeCount;
			if (PrimeCount == 10001) break;			
		}
	}
	cout<<Primes[10000];
	return 0;
}