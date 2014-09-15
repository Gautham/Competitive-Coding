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
#include <cmath>
using namespace std;


int main() {
	int T;
	cin>>T;
	while (T--) {
		int n, t; cin>>n;
		vector<int> M, H;
		FORi(i, 0, n) {
			cin>>t;
			M.push_back(t);
		}
		FORi(i, 0, n) {
			cin>>t;
			H.push_back(t);
		}
		sort(M.begin(), M.end());
		sort(H.begin(), H.end());
		int max = abs(M[0] - H[0]);
		FORi(i, 0, n) {
			if (abs(M[i] - H[i]) > max) max = abs(M[i] - H[i]);
		}
		cout<<max<<endl;
	}
	return 0;
}