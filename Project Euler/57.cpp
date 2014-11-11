#include <bits/stdc++.h>
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
typedef long long ll;
typedef unsigned long long ull;


int noDigits(long double i) {
	return (int)(1 + log10(i));
}

int main() {
	FastIO
	long double a = 1, b = 1;
	int count = 0;
	FORi(i, 0, 1000) {
		long double p = a;
		a += 2 * b;
		b += p;
		if (noDigits(a) > noDigits(b)) ++count; 
	}
	cout<<count;
	return 0;
}