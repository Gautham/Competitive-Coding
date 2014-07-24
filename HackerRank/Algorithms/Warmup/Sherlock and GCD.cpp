#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (a < b) {
		a += b;
		b = a - b;
		a = a -b;
	}
	int t;
	while (b != 0) {
		t = a;
		a = b;
		b = t % b;
	}
	return a;
}

int main() {
	int T, N;
	cin>>T;
	for (int i = 0; i < T; ++i) {
		cin>>N;
		int gc = 0;
		for (int j = 0; j < N; ++j) {
			int p;
			cin>>p;
			gc = gcd(p, gc);
		}
		if (gc == 1) cout<<"YES";
		else cout<<"NO";
		if (i < T - 1) cout<<endl;
	}
	return 0;
}