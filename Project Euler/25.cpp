#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double logPhi = log(1 + sqrt(5)) - log(2), logRoot5 = log(5) / 2;	
	cout<<ceil((999 * log(10) + logRoot5) / logPhi);
}