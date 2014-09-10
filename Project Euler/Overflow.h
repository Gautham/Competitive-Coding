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

_ll MulMod(_ll a, _ll b, _ll MOD) {
	_ll res = 0;
	a %= MOD;
	b %= MOD;
	while (b) {
		if (b & 1) res = (res + a) % MOD; 
		a = (a << 1) % MOD;
		b >>= 1;
	}
	return res;
}

_ll ExpMod(_ll a, _ll b, _ll MOD) {
	_ll res = 1;
	a %= MOD;
	b %= MOD;
	while (b) {
		if (b & 1) res = MulMod(res, a, MOD);
		a = MulMod(a, a, MOD);
		b >>= 1;
	}
	return res;
}
