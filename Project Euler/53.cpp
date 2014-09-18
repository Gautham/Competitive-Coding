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

int getNumbers(int N, int R) {
	int res = (N / 2 - R + 1) * 2;
	return (N & 1) ? res : res - 1;
}

int main() {
	int Count = 0, N = 23, R = 10;
	while (N <= 100) {
		while (1) {
			int S = N, i;
			FORe(i, 2, R) {
				S = S * (N - i + 1) / i;
				if (S > 1000000) break; 
			}
			if (S > 1000000) {
				Count += getNumbers(N, i);
				R = i;
				break;
			} else --R;
		}
		++N;
	}
	cout<<Count;
	return 0;
}