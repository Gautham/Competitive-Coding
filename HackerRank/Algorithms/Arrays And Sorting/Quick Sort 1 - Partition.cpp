#include <iostream>
using namespace std;

void Partition(int A[], int N, int key) {
	int B[1000], C[1000];
	int i = 0, k = 0, count = 0;
	for (int j = 0; j < N; ++j) {
		if (A[j] < key) B[i++] = A[j]; 
		else if (A[j] > key) C[k++] = A[j];
		else ++count;
	}
	int t = 0;
	for (int p = 0; p < i; ++p) A[t++] = B[p];
	while (count--) A[t++] = key;
	for (int p = 0; p < k; ++p) A[t++] = C[p];
}

int main() {
	int A[1000], N;
	cin>>N;
	for (int i = 0; i < N; ++i) cin>>A[i];
	Partition(A, N, A[0]);
	for (int i = 0; i < N; ++i) cout<<A[i]<<'\t';
}