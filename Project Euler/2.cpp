#include <iostream>
using namespace std;

int main() {
	long int sum = 0;
	int a = 1, b = 2, t;
	while (a <= 4000000) {
		if (a % 2 == 0) sum += a;
		t = a + b;
		a = b;
		b = t;
	}
	cout<<sum;
	return 0;
}