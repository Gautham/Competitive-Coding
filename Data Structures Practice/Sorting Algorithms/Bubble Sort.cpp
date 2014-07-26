#include <iostream>
using namespace std;

void BubbleSort(int A[], int N) {
	for (int i = 0; i < N - 1; ++i) {
		bool flag = false;
		for (int j = 0; j < N - i - 1; ++j) {
			if (A[j] < A[j + 1]) {
				flag = true;
				A[j] += A[j + 1];
				A[j + 1] = A[j] - A[j + 1];
				A[j] -= A[j + 1]; 
			}
		}
		if (!flag) return;
	}
}

int main() {
	int A[100], N;
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>A[i];
	BubbleSort(A, N);
	for (int i = 0; i < N; ++i) cout<<A[i]<<'\t';
}