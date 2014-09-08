#include <iostream>
using namespace std;

int main() {
	long long S = 1, startItem = 3, n = 3;
	while (n <= 1001) {
		S += 4 * startItem + 6 * (n - 1);
		startItem = n * n + n + 1;
		n += 2;
	}
	cout<<S;
}