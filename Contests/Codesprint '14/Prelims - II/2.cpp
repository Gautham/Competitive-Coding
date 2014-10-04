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
		string P, MaxString;
		cin>>P;
		int t = P.length();
		char Max = P[0];
		FORi(i, 1, t) Max = max(P[i], Max);
		MaxString = P;
		FORi(i, 0, t) {
			if (P[i] != Max) continue;
			string z = P.substr(i);
			z += P.substr(0, i);
			if (z > MaxString) MaxString = z;
		}
		cout<<MaxString<<endl;
	}
	return 0;
}