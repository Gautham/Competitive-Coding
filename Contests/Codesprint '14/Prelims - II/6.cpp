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
		int M, N, F = 0;
		cin>>M>>N;
		while (M > 0 && N > 0) {
			int P = Min(M, N), Q = Max(M, N);
			F += Q / P;
			M = P;
			N = Q % P;
		}
		cout<<F<<endl;
	}
	return 0;
}