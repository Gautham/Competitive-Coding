#include <iostream>
using namespace std;

void SelectionSort(int A[], int N) {
	for (int i = 0; i < N - 1; ++i) {
		int max = A[i], pos = i;
		for (int j = i + 1; j < N; ++j) {
			if (A[j] > max) {
				max = A[j];
				pos = j;
			}
		}
		A[pos] = A[i];
		A[i] = max;
	}
}

int main() {
	int A[100], N;
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>A[i];
	SelectionSort(A, N);
	for (int i = 0; i < N; ++i) cout<<A[i]<<'\t';
}