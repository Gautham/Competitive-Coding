#include <iostream>
using namespace std;

int LomutoPartition(int A[], int p, int r) {
	int x = A[r], i = p - 1;
	for (int j = p; j < r; ++j) {
		if (A[j] >= x) {
			int t = A[++i];
			A[i] = A[j];
			A[j] = t;
		}
	}
	A[r] = A[++i];
	A[i] = x;
	for (int i = p; i <= r; ++i) cout<<A[i]<<'\t';
		cout<<endl;
	return i;
}

int HoarePartition(int A[], int p, int r) {
	int x = A[r], i = p - 1, j = r;
	while (true) {
		while (A[++i] > x);
		while (--j >= p && A[j] <= x);
		if (i < j) {
			int t = A[i];
			A[i] = A[j];
			A[j] = t;
		} else {
			A[r] = A[++j];
			A[j] = x; 
			return j;	
		}
	}
}

void QuickSort(int A[], int N) {
	int p = 0, r = N - 1;
	while (p < r) {
		int q = LomutoPartition(A, p, r);
		if (q - p < r - q) {
			QuickSort(A + p, q - p);
			p = q + 1;
		} else {
			QuickSort(A + q + 1, r - q);
			r = q - 1;
		}
	}
}

int main() {
	int A[100], N;
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>A[i];
	QuickSort(A, N);
	for (int i = 0; i < N; ++i) cout<<A[i]<<'\t';
}