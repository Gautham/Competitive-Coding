#include <iostream>
using namespace std;

int main() {
	int T;
	long long N;
	long long P;
	cin>>T;
	while (T--) {
		cin>>N;
		P = N;
		int count = 0;
		while (P > 0) {
			int x = P % 10;
			if (x && N % x == 0) ++count;
			P /= 10;
		}
		cout<<count<<endl;
	}
}