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
	int T;
	cin>>T;
	while (T--) {
		bitset<26> Broken;
		string S;
		char z;
		cin>>S;
		int t = S.length();
		FORi(i, 0, t) Broken[S[i] - 'a'] = true;
		cin>>S;
		bitset<26> ToFix;
		t = S.length();
		FORi(i, 0, t) if (Broken[S[i] - 'a']) ToFix[S[i] - 'a'] = true;
		cout<<ToFix.count()<<'\n';
	}
	return 0;
}