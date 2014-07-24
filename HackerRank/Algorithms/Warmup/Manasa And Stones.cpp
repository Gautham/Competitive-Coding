#include <iostream>
using namespace std;

int main() {
	int T, n, a, b;
	cin>>T;
	while (T--) {
		cin>>n>>a>>b;
		if (a == b) cout<<(n - 1) * a<<endl;
		else {
			if (a < b) {
				a += b;
				b = a - b;
				a = a - b;
			}
			for (int i = 0; i < n; ++i) cout<<(i * a) + (n - 1 - i) * b<<' ';
			cout<<endl;
		}
	}
}