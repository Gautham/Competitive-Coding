#include <iostream>
using namespace std;

#define left(i) (2*i + 1)
#define right(i) (2*i + 2)

void Heapify(int A[], int N, int i) {
	int l, r, min, small = i;
	do {
		l = left(i);
		r = right(i);
		i = small;
		min = A[i];
		if (l < N && A[l] < min) {
			min = A[l];
			small = l;
		}
		if (r < N && A[r] < min) {
			min = A[r];
			small = r;
		}
		if (small != i) {
			A[small] = A[i];
			A[i] = min;
		}
	} while (small != i);
}

void BuildMinHeap(int A[], int N) {
	for (int i = (N - 1)/ 2; i >= 0; --i) {
		Heapify(A, N, i);
	}
}

void HeapSort(int A[], int N) {
	BuildMinHeap(A, N);
	int HeapSize = N;
	for (int i = N - 1; i >= 1; --i) {
		A[0] += A[i];
		A[i] = A[0] - A[i];
		A[0] -= A[i];
		Heapify(A, --HeapSize, 0);
	}
}

int main() {
	int A[100], N;
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>A[i];
	HeapSort(A, N);
	for (int i = 0; i < N; ++i) cout<<A[i]<<'\t';
}