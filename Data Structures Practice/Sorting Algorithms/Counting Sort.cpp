#include <iostream>
using namespace std;

void CountingSort(int A[], int B[], int N, int k = -1) {
	int C[100] = {};
	if (k == -1) k = A[0];
	for (int i = 0; i < N; ++i) {
		C[A[i]] += 1;
		if (A[i] > k) k = A[i];
	}
	for (int i = k - 1; i >= 0; --i) C[i] += C[i + 1];
	for (int i = N - 1; i >= 0; --i) {
		B[C[A[i]] - 1] = A[i];
		C[A[i]] -= 1;
	}
}

int main() {
	int A[100], B[100], N;
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>A[i];
	CountingSort(A, B, N, 10);
	for (int i = 0; i < N; ++i) cout<<B[i]<<'\t';
}