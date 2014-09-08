#include <iostream>
using namespace std;

int GCD(int a, int b) {
	if (a < b) {
		a += b;
		b = a - b;
		a = a - b;
	}
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main() {
	int Num[4], Den[4], count = 0, num = 11;
	while (count < 4) {
		for (int den = num + 1; den <= 99; ++den) {
			if (num % 10 || den % 10) {
				int X = GCD(num, den), Y, p = num / 10, q = num % 10, r = den / 10, s = den % 10;
				if (p == r) {
					Y = GCD(q, s);
					if (num / X == q / Y && den / X == s / Y) {
						Num[count] = num / X;
						Den[count++] = den / X;
					}
				} else if (p == s) {
					Y = GCD(q, r);
					if (num / X == q / Y && den / X == r / Y) {
						Num[count] = num / X;
						Den[count++] = den / X;
					}
				} else if (q == r) {
					Y = GCD(p, s);
					if (num / X == p / Y && den / X == s / Y) {
						Num[count] = num / X;
						Den[count++] = den / X;
					}
				} else if (q == s) {
					Y = GCD(p, r);
					if (num / X == p / Y && den / X == r / Y) {
						Num[count] = num / X;
						Den[count++] = den / X;
					}
				}
			}
		}
		++num;
	}	
	int P = Num[0] * Num[1] * Num[2] * Num[3], Q = Den[0] * Den[1] * Den[2] * Den[3];
	cout<<Q / GCD(Q, P);
}