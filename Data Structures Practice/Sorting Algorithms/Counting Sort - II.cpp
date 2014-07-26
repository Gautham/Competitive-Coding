#include <iostream>
using namespace std;

void CountingSort(int A[], int N, int k = -1) {
	int C[100] = {};
	if (k == -1) k = A[0];
	for (int i = 0; i < N; ++i) {
		C[A[i]] += 1;
		if (A[i] > k) k = A[i];
	}
	for (int i = k, j = 0; i >=0; --i) {
		while (C[i] > 0) {
			A[j++] = i;
			C[i] -= 1;
		}
	}
}

int main() {
	int A[100], N;
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>A[i];
	CountingSort(A, N);
	for (int i = 0; i < N; ++i) cout<<A[i]<<'\t';
}