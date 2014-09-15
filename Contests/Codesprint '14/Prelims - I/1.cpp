#include <bits/stdc++.h>
#include <cmath>
#define _ll long long
#define Max(a, b) (a > b) ? a : b
#define Min(a, b) (a < b) ? a : b
#define gcd __gcd
#define FOR(i, a, n) for (i = a; i < n; ++i)
#define FORe(i, a, n) for (i = a; i <= n; ++i)
#define FORi(i, a, n) for (int i = a; i < n; ++i)
#define FORie(i, a, n) for (int i = a; i <= n; ++i)		
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

int main() {
	int T;
	cin>>T;
	while (T--) {
		int x, y, x1, y1, x2, y2;
		cin>>x>>y>>x1>>y1>>x2>>y2;
		cout<<min(min(x- x1, x2 - x), min(y - y1, y2 - y))<<'\n';		
	}
	return 0;
}