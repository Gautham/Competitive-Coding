#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long E = 600851475143L; 
	int n = sqrt(E) + 1;
	int f = -1;
	int i = 3;
	while (i < n) {
		while (i < n && E % i) i += 2;
		if (i < n) {
			E /= i;
			f = i;
		}
	}
	cout<<f;
	return 0;
}