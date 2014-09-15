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

const int SIZE = 1 << 16, MASK = (1 << 16) - 1;

int main() {
	FastIO
	unsigned char A[SIZE], T = 0;
	A[0] = 0;
	FORi(i, 1, SIZE) A[i] = A[i >> 1] + (i & 1);
	int N, t;
	cin>>N;
	while (N--) {
		cin>>t;
		T ^= A[t & MASK] + A[(t >> 16) & MASK];
	}
	if (T) cout<<"Shaka :)";
	else cout<<"The other player :(";
	return 0;
}