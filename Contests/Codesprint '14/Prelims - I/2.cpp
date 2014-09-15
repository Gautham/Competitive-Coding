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
using namespace std;



int main() {
	int T;
	cin>>T;
	while (T--) {
		int n, S = 0, t, A[101] = {0}, N = 0;
		cin>>n;
		FORi(i, 0, n) {
			cin>>t;
			++A[t];
			S += t;
		}
		float Z = S / (float)n;
		if (floor(Z) == ceil(Z)) t = Z + 1;
		else t = ceil(Z);
		FORi(i, t, 101) N += A[i];
		cout<<N<<'\n';
	}
	return 0;
}