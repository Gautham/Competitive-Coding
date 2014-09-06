#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int A[15][15];
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j <= i; ++j) cin>>A[i][j];
	}
	for (int i = 13; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			A[i][j] += max(A[i + 1][j], A[i + 1][j + 1]);
		}
	}
	cout<<A[0][0];
}