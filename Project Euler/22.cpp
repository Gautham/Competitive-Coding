#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string A[6000];
	int n = 0;
	long long S = 0, T = 0;
	while (getline(cin, A[n++]));
	sort(A, A + n);
	for (int i = 1; i < n; ++i) {
		T = 0;
		for (int j = A[i].size() - 2; j > 0; --j) T += A[i][j] - 'A' + 1;
		S += T * (i);
	}
	cout<<S;
}