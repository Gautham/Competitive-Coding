#include <iostream>
using namespace std;

int main() {
	for (int i = 5; i < 500; ++i) {
		for (int j = i + 1; j < 500; ++j) {
			int t = 1000 - (i + j);
			if (i * i + j * j == (t * t)) {
				cout<<i*j*t;
				break;
			}
		}
	}
}