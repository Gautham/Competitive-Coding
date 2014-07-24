#include <iostream>
using namespace std;

int main() {
	int L, R, max = 0;
	cin>>L>>R;
	for (int i = L; i <=R; ++i) {
		for (int j = i; j <= R; ++j) {
			int k = i ^ j;
			if (k > max) max = k;
		}
	}
	cout<<max;
}