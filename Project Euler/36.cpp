#include <iostream>
#include <math.h>
using namespace std;

int Reverse(int n, int b) {
	int temp = 0;
	while (n > 0) {
		temp = temp * b + (n % b);
		n /= b;
	}
	return temp;
}

int main() {
	long long S = 0;
	for (int i = 1; i < 1000; ++i) {
		int N, T;
		if (i < 10) {
			T = i;
			if (Reverse(T, 2) == T) S += T;
			T = i * 11;
			if (Reverse(T, 2) == T) S += T;
			for (int j = 0; j < 10; ++j) {
				T = i * 100 + j * 10 + i;
				if (Reverse(T, 2) == T) S += T;
			}
		} else if (i < 99) {
			T = i * 100 + Reverse(i, 10);
			if (Reverse(T, 2) == T) S += T;
			for (int j = 0; j < 10; ++j) {
				T = i * 1000 + j * 100 + Reverse(i, 10);
				if (Reverse(T, 2) == T) S += T;
			}
		} else {
			T = i * 1000 + Reverse(i, 10);
			if (Reverse(T, 2) == T) S += T;
		}
	}
	cout<<S;
}
