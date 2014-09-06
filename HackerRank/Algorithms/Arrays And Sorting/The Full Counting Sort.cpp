#include <iostream>
#include <string.h>
using namespace std;

char Z[1000000][11];
char T[1000000][11];
void CountingSort(int A[], char T[][11], int N, int k = -1) {
	int C[100] = {};
	if (k == -1) k = A[0];
	for (int i = 0; i < N; ++i) {
		C[A[i]] += 1;
		if (A[i] > k) k = A[i];
	}
	for (int i = k - 1; i >= 0; --i) C[i] += C[i + 1];
	for (int i = 0; i < N; ++i) {
		if (i < N/ 2) strcpy(Z[C[A[i]] - 1], "-");
		else strcpy(Z[C[A[i]] - 1], T[i]);
		
		C[A[i]] -= 1;
	}
}

int main() {
	int A[1000000], N;
	int x = 0;
	cin>>N;
	for (int i = 0; i < N; ++i) {
		cin>>A[i]>>T[i];
	}
	CountingSort(A, T, N, 99);
	for (int i = N - 1; i >= 0; --i) cout<<Z[i]<<' ';
}