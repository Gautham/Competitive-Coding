#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	long long magic = 1000000007L, pdt = 1;
	long long N, M, t;
	cin>>N>>M;
	vector<long long> A(N + 1), B(M + 1), C(M + 1), D(N + 1, 1);
	for (int i = 1; i <= N; ++i) {
		cin>>t;
		A[i] = t;
	}
	for (int i = 1; i <= M; ++i) {
		cin>>t;
		B[i] = t;
	}
	for (int i = 1; i <= M; ++i) {
		cin>>t;
		C[i] = t;
		D[B[i]] *= t;
		D[B[i]] %= magic;
	}
	for (int i = 1; i <= N; ++i) {
		if (D[i] > 1) {
			for (int j = i; j <= N; j += i) {
				A[j] *= D[i];
				A[j] %= magic;
			}
		}
	}
	for (int i = 1; i <= N; ++i) cout<<A[i]<<' ';

}