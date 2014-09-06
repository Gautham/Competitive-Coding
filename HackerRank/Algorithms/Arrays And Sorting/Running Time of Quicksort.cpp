#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int QuickSortSwaps, InsertionSortSwaps;

int LomutoPartition(int A[], int p, int r) {
	int x = A[r], i = p - 1;
	for (int j = p; j < r; ++j) {
		if (A[j] < x) {
			int t = A[++i];
			A[i] = A[j];
			A[j] = t;
			++QuickSortSwaps;
		}
	}
	A[r] = A[++i];
	A[i] = x;
	++QuickSortSwaps;
	return i;
}

void QuickSort(int A[], int N) {
	int p = 0, r = N - 1;
	while (p < r) {
		int q = LomutoPartition(A, p, r);
		QuickSort(A + p, q - p);
		p = q + 1;
	}
}

void InsertionSort(int A[], int N) {
	for (int i = 1; i < N; ++i) {
		int key = A[i];
		int j = i - 1;
		for (; j >= 0 && A[j] > key; --j) {
			++InsertionSortSwaps;
			A[j + 1] = A[j];
		}
		A[j + 1] = key;
	}
}


int main() 
{
	int N, t;
	int A[1000], B[1000];
	cin>>N;
	for (int i = 0; i < N; ++i) {
		cin>>t;
		A[i] = B[i] = t;
	}
	QuickSort(A, N);
	InsertionSort(B, N);
	cout<<InsertionSortSwaps - QuickSortSwaps;
}
