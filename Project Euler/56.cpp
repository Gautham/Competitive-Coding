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


int DigitSum(char A[], int n) {
	int S = 0;
	FORi(i, 0, n) S += A[i];
	return S;
}

int Calculate(int a, int b) {
	char A[210] = {0};
	int t = a, i = 0, n, carry = 0;
	while (t) {
		A[i++] = t % 10;
		t /= 10;
	}
	n = i;
	while (--b) {
		FOR(i, 0, n) {
			t = A[i] * a + carry;
			carry = t / 10;
			A[i] = t % 10;			
		}
		while (carry) {
			A[i++] = carry % 10;
			carry /= 10;
		}
		n = i;
	}
	return DigitSum(A, n);
}

int main() {
	FastIO
	int Max =  0, p = 99, q = 99, Z;
	while (p > 80) {
		while (q > 80) {
			if ((Z = Calculate(p, q)) > Max) Max = Z;
			--q;
		}
		--p;
	}
	cout<<Max;
	return 0;
}