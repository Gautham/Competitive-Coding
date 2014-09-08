#include <iostream>
#include <math.h>
#include <bitset>
#include <tr1/unordered_set>
using namespace std;

int main() {
	long long Sum = 0;
	tr1::unordered_set<int> P;
	for (int i = 2; i <= 9999; ++i) {
		int p = ceil(log10(i));
		for (int j = i + 1; j <= 9999; ++j) {
			bitset<10> T;
			T.flip();
			T[0] = false;
			int N = i * j;
			int q = p + ceil(log10(j)) + ceil(log10(N));
			if (q > 9) break;
			else if (q < 9) continue;

			int x = i, y = j, z = N;
			while (x > 0) {
				T[x % 10] = false;
				x /= 10;
			}
			while (y > 0) {
				T[y % 10] = false;
				y /= 10;
			}
			while (z > 0) {
				T[z % 10] = false;
				z /= 10;
			}
			if (!T.any()) {
				if (P.count(N) == 0) Sum += N;				
				P.insert(N);
			}
		}
	}
	cout<<Sum;
	return 0;
}