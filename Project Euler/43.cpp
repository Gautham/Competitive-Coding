#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A[] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	long long S = 0;
	do {
		if (!A[0]) continue;
		if (A[3] % 2) continue;
		if ((A[2] + A[3] + A[4]) % 3) continue;
		if (A[5] % 5) continue;
		if ((A[4] * 100 + A[5] * 10 + A[6]) % 7) continue;
		if ((A[5] * 100 + A[6] * 10 + A[7]) % 11) continue;
		if ((A[6] * 100 + A[7] * 10 + A[8]) % 13) continue;
		if ((A[7] * 100 + A[8] * 10 + A[9]) % 17) continue;
		long long N = 0;
		for (int i = 0; i < 10; ++i) N = N * 10 + A[i];
		S += N;
	} while (next_permutation(A, A + 10));
	cout<<S;
}
