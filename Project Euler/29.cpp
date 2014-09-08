#include <iostream>
#include <math.h>
#include <tr1/unordered_set>
using namespace std;
using namespace tr1;

int main() {
	unordered_set<double> T;
	for (int a = 2; a <= 100; ++a) {
		for (int b = 2; b <= 100; ++b) {
			double d = pow(a, b);
			T.insert(d);
		}
	}
	cout<<T.size();
	return 0;
}