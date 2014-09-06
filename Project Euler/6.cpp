#include <iostream>
using namespace std;

int main() {
	int n = 100;
	long P = n * (n + 1) * (2 * n + 1) / 6;
	long Q = n * (n + 1) / 2;
	cout<<Q * Q - P;
	return 0;
}