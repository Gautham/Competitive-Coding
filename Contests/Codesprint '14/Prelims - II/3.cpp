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

int main() {
	FastIO
	int T;
	cin>>T;
	while (T--) {
		_ll n, t = 1;
		cin>>n;
		n = 2 * n + 2;
		while (t * (t + 1) < n) ++t;
		cout<<--t<<endl;
	}
	return 0;
}