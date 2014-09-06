#include <iostream>
using namespace std;


long long Count = 0;

void Merge(int A[],int B[],int C[], int p, int q) {
	int i = 0, j = 0, k = 0;
	int * D;
	if (A == C || B == C) {
		D = new int[100000];
	} else D = C;
	while (i < p && j < q) {
		if (A[i] <= B[j]) D[k++] = A[i++];
		else {
			Count += (p - i);
			D[k++] = B[j++];

		}
	}
	while (i < p) D[k++] = A[i++];
	while (j < q) D[k++] = B[j++];
	if (D != C) {
		while (--k >= 0) C[k] = D[k];
		delete(D);
	}
}

void RecursiveMergeSort(int A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		RecursiveMergeSort(A, p, q);
		RecursiveMergeSort(A, q + 1, r);
		Merge(A + p, A + q + 1, A + p, q - p + 1, r - q);
	}
}

void MergeSort(int A[], int N) {
	RecursiveMergeSort(A, 0, N - 1);
}

int main() {
	int A[100000], T, N;
	cin>>T;
	while (T--) {
		Count = 0;
		cin>>N;
		for (int i = 0; i < N; ++i) cin>>A[i];
		MergeSort(A, N);
		cout<<Count<<endl;
	}
}