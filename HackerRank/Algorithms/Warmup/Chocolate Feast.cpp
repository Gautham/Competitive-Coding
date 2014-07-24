#include <iostream>
using namespace std;

int main() {
	int T, N, C, M, total, t;
	cin>>T;
	while (T--) {
		cin>>N>>C>>M;
		total = t = N / C;
		while (t >= M) {
			total += t / M;
			t = (t / M) + (t % M);
		}
		cout<<total<<endl;
	}
}