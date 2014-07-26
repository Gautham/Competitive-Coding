#include <iostream>
using namespace std;

void RadixSort(int A[], int N, int k) {
	int t = 1;
	for (int i = 0; i < k; ++i) {
		for (int i = 1; i < N; ++i) {
			int key = A[i];
			int x = (int)(key / t) % 10;
			int j = i - 1;
			for (; j >= 0 && ((int)(A[j] / t) % 10) < x; --j) {
				A[j + 1] = A[j];
			}
			A[j + 1] = key;
		}
		t *= 10;
	}
}

int main() {
	int A[100], N;
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>A[i];
	RadixSort(A, N, 3);
	for (int i = 0; i < N; ++i) cout<<A[i]<<'\t';
}