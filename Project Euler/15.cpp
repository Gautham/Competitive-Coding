#include <iostream>
using namespace std;


int main() {
	int k = 2, l = 21;
	long long N = 1;
	while (l <= 40 && k <= 20) {
		N *= l++;
		if (N % k == 0) {
			N /= k++;
		}
	}
	while (l <= 40) N *= l++;
	while (k <= 20) N /= k++;
	cout<<N;
}