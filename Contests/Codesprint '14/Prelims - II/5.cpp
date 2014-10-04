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

_ll MOD = 1000000007;

int main() {
	FastIO
	int T;
	cin>>T;
	while (T--) {
		_ll N, t, C = 1, Value = 0;
		cin>>N;
		FORi(i, 0, N) {
			cin>>t;
			t %= MOD;
			_ll z = pow(-1, i) * C * t;
			z %= MOD; 
			if (z < 0) z += MOD;
			Value += z;
			Value %= MOD;
			C = (N == (i + 1)) ? 1 : (C * (N - i - 1)) / (i + 1);
			C %= MOD;
		}
		if (Value < 0) Value += MOD;
		cout<<Value<<endl;
	}
	return 0;
}