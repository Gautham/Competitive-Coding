#include <iostream>
using namespace std;

int main() {
	long long T, N;
	cin>>T;
	while (T--) {
		cin>>N;
		long long p = N / 2;
		cout<<p * (N - p)<<endl;
	}
	return 0;
}