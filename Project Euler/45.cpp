#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int i = 286, j = 166, k = 144;
	long long P = i * (i + 1) / 2, Q = j * (3 * j - 1) / 2, R = k * (2 * k - 1);
	while (P != Q || Q != R) {
		if (P < Q) {
			P += ++i;
		} else if (P > Q) {
			Q += 3 * j++ + 1;
		}
		if (Q < R) {
			Q += 3 * j++ + 1;	
		} else if (Q > R) {
			R += 4 * k++ + 1;
		}
	}
	cout<<P;
}
