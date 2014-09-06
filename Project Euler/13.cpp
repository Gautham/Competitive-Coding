#include <iostream>
using namespace std;

int main() {
	char Sum[52] = {0}, A[51];
	for (int i = 0; i < 100; ++i) {
		cin>>A;
		int carry = 0, j = 0;
		for (; j < 50; ++j) {
			Sum[j] += A[49 - j] + carry - '0';
			carry = Sum[j] / 10;
			Sum[j] %= 10;
		}
		while (carry) {
			Sum[j] += carry;
			carry = Sum[j] / 10;
			Sum[j++] %= 10;
		} 
	}
	int z = 0, i = 52;
	while (!Sum[--i]);
	while (z < 10) {
		cout<<(int)Sum[i];
		--i; ++z;
	}
	return 0;
}