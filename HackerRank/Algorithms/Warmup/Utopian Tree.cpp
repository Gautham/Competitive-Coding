#include <iostream>
#include <math.h>
using namespace std;


int main() {
	int T, N;
	cin>>T;
	while (T--) {
		cin>>N;
		int x = pow(2, (N + 3) / 2);
		if (N % 2) cout<<x - 2<<endl;
		else cout<<x - 1<<endl;
	}
	return 0;
}
