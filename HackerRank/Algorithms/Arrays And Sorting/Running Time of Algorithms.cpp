#include <iostream>
using namespace std;

int InsertionSort(int A[], int N) {
	int shifts = 0;
	for (int i = 1; i < N; ++i) {
		int key = A[i];
		int j = i - 1;
		for (; j >= 0 && A[j] > key; --j) {
			A[j + 1] = A[j];
			++shifts;
		}
		A[j + 1] = key;
	}
	return shifts;
}

int main() {
	int A[1001], N;
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>A[i];
	cout<<InsertionSort(A, N);
}