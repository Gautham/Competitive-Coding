#include <iostream>
using namespace std;

void InsertionSort(int A[], int N) {
	for (int i = 1; i < N; ++i) {
		int key = A[i];
		int j = i - 1;
		for (; j >= 0 && A[j] < key; --j) {
			A[j + 1] = A[j];
		}
		A[j + 1] = key;
	}
}

int main() {
	int A[100], N;
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>A[i];
	InsertionSort(A, N);
	for (int i = 0; i < N; ++i) cout<<A[i]<<'\t';
}