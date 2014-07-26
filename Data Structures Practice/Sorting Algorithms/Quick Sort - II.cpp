#include <iostream>
using namespace std;

struct Pair {
	int x, y;
};

Pair LomutoPartition(int A[], int p, int r) {
	Pair P;
	int pivot = A[r], x = p - 1, y = p - 1;
	for (int i = p; i < r; ++i) {
		if (A[i] == pivot) {
			int t = A[++y];
			A[y] = A[i];
			A[i] = t;
		} else if (A[i] > pivot) {
			int t = A[++x];
			A[x] = A[i];
			A[i] = t;
			if ((i == y + 1) || (x == y + 1)) ++y;
			else {
				t = A[++y];
				A[y] = A[i];
				A[i] = t;
			}
		}
	}
	A[r] = A[++y];
	A[y] = pivot;
	P.x = x + 1;
	P.y = y;
	return P;
}

void QuickSort(int A[], int N) {
	int p = 0, r = N - 1;
	while (p < r) {
		Pair P = LomutoPartition(A, p, r);
		QuickSort(A + p, P.x - p);
		p = P.y + 1;
	}
}

int main() {
	int A[100], N;
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>A[i];
	QuickSort(A, N);
	for (int i = 0; i < N; ++i) cout<<A[i]<<'\t';
}