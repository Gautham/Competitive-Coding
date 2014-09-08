#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int P[1001] = {0};
	for (int i = 2; i < 500; ++i) {
		for (int j = i + 1; i + j < 500; ++j) {
			long double t = sqrt(i * i + j * j);
			if (t + i + j > 1000) break;
			int u = t;
			if (t - (long double)u <= 0.00000001) P[u + i + j] += 1;	
		}
	}
	int max = 2;
	for (int i = 3; i < 1001; ++i) {
		if (P[max] < P[i]) max = i;
	}
	cout<<max;
	return 0;
}