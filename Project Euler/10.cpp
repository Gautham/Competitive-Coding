#include <iostream>
#include <bitset>
using namespace std;

bitset<2000000> Primes;

int main() {
	long long S = 2;
	Primes.flip();
	Primes[0] = Primes[1] = Primes[4] = false;
	for (int i = 3; i < 2000000; i += 2) {
		if (Primes[i]) {
			S += i;
			for (int j = i; j < 2000000; j += 2 * i) {
				Primes[j] = false;
			}
		}
	}
	cout<<S;
	return 0;
}