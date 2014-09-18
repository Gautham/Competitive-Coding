#include <bits/stdc++.h>
#define _ll long long
#define Max(a, b) (a > b) ? a : b
#define Min(a, b) (a < b) ? a : b
#define gcd __gcd
#define FOR(i, a, n) for (i = a; i < n; ++i)
#define FORe(i, a, n) for (i = a; i <= n; ++i)
#define FORi(i, a, n) for (int i = a; i < n; ++i)
#define FORie(i, a, n) for (int i = a; i <= n; ++i)		
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
using namespace std;

inline _ll Reverse(_ll n) {
	_ll t = 0;
	while (n) {
		t = t * 10 + (n % 10);
		n /= 10;
	}
	return t;
}

int main() {
	FastIO
	int Count = 0, SIZE = 10000;
	FORi(D, 100, SIZE) {
		_ll Number = D, t;
		char A[1000] = {0};
		int i = 0;
		while (Number) {
			A[i++] = Number % 10;
			Number /= 10;			
		}
		Number = D;
		int n = i;
		t = 0;
		bool flag = true;
		while (t < 50 && flag) {
			int f = (n + 1) / 2;
			FOR(i, 0, f) A[i] = A[n - i - 1] = A[i] + A[n - i - 1];
			i = 0;
			int carry = 0;
			while (i < n) {
				A[i] += carry;
				carry = A[i] / 10;
				A[i++] %= 10;
			}
			if (carry) A[n++] = carry;
			flag = false;
			FORi(j, 0, n) {
				if (A[j] != A[n - j - 1]) flag = true;
			}
			++t;
		}
		if (flag) ++Count;
	}
	cout<<Count;
	return 0;
}