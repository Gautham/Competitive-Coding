#include <iostream>
#include <bitset>
using namespace std;

int main() {
	long Max = 0, i , j;
	int A[20][20];
	for (i = 0; i < 20; ++i) {
		for (j = 0; j < 20; ++j) cin>>A[i][j];
	}
	for (i = 0; i < 20; ++i) {
		for (j = 0; j < 20; ++j) {
			int P;
			if (j < 17) {
				P = A[i][j] * A[i][j + 1] * A[i][j + 2] * A[i][j + 3];
				if (P > Max) Max = P;
			}
			if (i < 17) {
				P = A[i][j] * A[i + 1][j] * A[i + 2][j] * A[i + 3][j];
				if (P > Max) Max = P;				
			}
			if (i < 17 && j < 17) {
				P = A[i][j] * A[i + 1][j + 1] * A[i + 2][j + 2] * A[i + 3][j + 3];
				if (P > Max) Max = P;
			}
			if (i < 17 && j > 2) {
				P = A[i][j] * A[i + 1][j - 1] * A[i + 2][j - 2] * A[i + 3][j - 3];
				if (P > Max) Max = P;				
			}
		}
	}
	cout<<Max;
	return 0;
}