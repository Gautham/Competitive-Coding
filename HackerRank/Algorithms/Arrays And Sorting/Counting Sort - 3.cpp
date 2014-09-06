#include <iostream>
using namespace std;

void CountingSort(int A[], int N, int k = -1) {
	int C[100] = {};
	if (k == -1) k = A[0];
	for (int i = 0; i < N; ++i) {
		C[A[i]] += 1;
		if (A[i] > k) k = A[i];
	}
	for (int i = 0; i < k; ++i) C[i + 1] += C[i];
	for (int i = 0; i <= k; ++i) {
		cout<<C[i]<<' ';
	}
}

int main() {
	int A[1000001], N;
	char Z[1000];
	cin>>N;
	for (int i = 0; i < N; ++i) {
		cin>>A[i];
		cin>>Z;
	}
	CountingSort(A, N, 99);
}