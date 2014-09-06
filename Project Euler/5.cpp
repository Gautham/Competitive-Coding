#include <iostream>
#include <math.h>
using namespace std;

int isPrime(int p) {
	int n = sqrt(p) + 1;
	for (int i = 2; i < n; ++i) {
		if (!(p % i)) return false;
	}
	return true;
}

int main() {
	int N = 16;
	for (int i = 3; i < 20; i += 2) {
		if (isPrime(i)) {
			int t = log(20) / log(i);
			N *= pow(i, t);
		}
	}
	cout<<N;
}