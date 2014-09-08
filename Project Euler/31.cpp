#include <iostream>
using namespace std;

int main() {
	int Coins[] = { 1, 2, 5, 10, 20, 50, 100, 200 }, Sum = 0, Ways[201] = {0}, n = 200;
	Ways[0] = 1;
	for (int i = 0; i < 8; ++i) {
		for (int j = Coins[i]; j <= n; ++j) {
			Ways[j] += Ways[j - Coins[i]];
		}
	}
	cout<<Ways[200];
	return 0;
}