#include <iostream>
using namespace std;

int main() {
	long long N, A[1000000], t, PMEAN = 0, maxPMEAN, Sum = 0;
	cin>>N;
	for (int i = 0; i < N; ++i) {
		cin>>t;
		PMEAN += (i + 1) * t;
		Sum += t;
		A[i] = t;
	}
	maxPMEAN = PMEAN;
	for (int i = 0; i < N - 1; ++i) {
		PMEAN += N * A[i] - Sum;
		if (PMEAN > maxPMEAN) maxPMEAN = PMEAN;
	}
	cout<<maxPMEAN;
	return 0;
}