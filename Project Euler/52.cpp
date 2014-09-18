#include <bits/stdc++.h>
#define _ll long long
#define Max(a, b) (a > b) ? a : b
#define Min(a, b) (a < b) ? a : b
#define gcd __gcd
#define FOR(i, a, n) for (i = a; i < n; ++i)
#define FORe(i, a, n) for (i = a; i <= n; ++i)
#define FORi(i, a, n) for (int i = a; i < n; ++i)
#define FORie(i, a, n) for (int i = a; i <= n; ++i)		
using namespace std;

bool checkDigits(_ll i, _ll j) {
	int A[10] = {0};
	while (i) {
		++A[i % 10];
		i /= 10;
	}
	while (j) {
		--A[j % 10];
		j /= 10;
	}
	FORi(t, 0, 10) if (A[t]) return false;
	return true;
}

int main() {
	_ll i = 108, T = 1000;
	while (1) {
		int Z = T / 6;
		while (i <= Z) {
			if (checkDigits(i, 2 * i) && checkDigits(i, 3 * i) && checkDigits(i, 4 * i) && checkDigits(i, 5 * i) && checkDigits(i, 6 * i)) break;
			i += 9;
		}
		if (i <= Z) break;
		i = T + 8;
		T *= 10;
	}
	cout<<i;
	return 0;
}