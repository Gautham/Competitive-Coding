#include <iostream>
using namespace std;

void CountingSort(int A[], int B[], int N) {
	for (int i = 0; i < N; ++i) {
		B[A[i]] += 1;
	}
}

int main() {
	int A[1000000], B[100], N;
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>A[i];
	CountingSort(A, B, N);
	for (int i = 0; i < 100; ++i) cout<<B[i]<<'\t';
}