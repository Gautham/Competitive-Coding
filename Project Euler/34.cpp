#include <iostream>
using namespace std;

int main() {
	int Factorials[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
	long long S = 0, n = Factorials[9] * 8;
	for (int i = 10; i < n; ++i) {
		int T = i, P = 0;
		while (T > 0) {
			P += Factorials[T % 10];
			T /= 10;
		}
		if (P == i) S += i;
	}
	cout<<S;
}
