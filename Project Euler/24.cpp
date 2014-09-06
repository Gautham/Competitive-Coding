#include <iostream>
#include <bitset>
using namespace std;

int main() {
	bitset<10> N;
	N.flip();
	int Factorials[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 }, count = 0, Ans[10], index = 0, n = N.count() - 1;	
	while (count != 999999) {
		for (int i = 0; i < 10; ++i) {
			if (N[i]) {
				if (count + Factorials[n] < 1000000) {
					count += Factorials[n];
				}
				else {
					Ans[index++] = i;
					N[i] = false;
					n -= 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < 10; ++i) cout<<Ans[i];
	return 0;
}