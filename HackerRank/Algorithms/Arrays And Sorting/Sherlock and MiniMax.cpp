#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	int N, A[100], i;
	long long P, Q, t, Min = 0, p, M;
	cin>>N;
	for (i = 0; i < N; ++i) {
		cin>>A[i];
	}
	cin>>P>>Q;
	sort(A, A + N);
	M = P;
	t = A[0];
	for (i = 0; i < N && A[i] < P; ++i) {
		t = P - A[i];
	}
	Min = (A[i] - P < t) ? A[i] - P : t;
	t = A[N - 1];
	for (i = N - 1; i >=0 && A[i] > Q; --i) {
		t = A[i] - Q;
	}
	t = (Q - A[i] < t) ? Q - A[i] : t;
	if (t > Min) {
		Min = t;
		M = Q;
	}
	for (i = 0; i < N - 1; ++i) {
		long long Mid = (A[i] + A[i + 1]) / 2;
		if (Mid < P) Mid = P;
		else if (Mid > Q) Mid = Q;
		t = min(Mid - A[i], A[i + 1] - Mid);
		if (t > Min) {
			Min = t;
			M = Mid;
		}
	}
	cout<<M;
	return 0;
}