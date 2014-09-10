#include <bits/stdc++.h>
#define PRLIMIT 200000
#include "Primes.h"
using namespace std;

int main() {
	InitializePrimes(PRLIMIT);

	cout<<Primes[10000];
	return 0;
}