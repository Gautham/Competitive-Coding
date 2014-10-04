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
		int n, m, t, p = 1;
		cin>>n>>m;
		FORi(i, 0, m) {
			cin>>t;
			p = p * t / gcd(p, t);
		}
		cout<<n / p<<endl;
	}
	return 0;
}