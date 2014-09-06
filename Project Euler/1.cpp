#include <iostream>
using namespace std;

int main() {
	int n = 999 / 5;
	int sum = 5 * n * (n + 1) / 2;
	n = 999 / 3;
	sum += n * (3 + 999) / 2;
	n = 999 / 15;
	sum -= n * (15 + 990) / 2;
	cout<<sum;
	return 0;
}