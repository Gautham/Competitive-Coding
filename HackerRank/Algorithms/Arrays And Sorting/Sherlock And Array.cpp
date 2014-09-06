#include <iostream>
#include <vector>
using namespace std;

int main () {
	int T, N, t;
	cin>>T;
	while (T--) {
		vector<int> A;
		cin>>N;
		for (int i = 0; i < N; ++i) {
			cin>>t;
			A.push_back(t);	
		}
		int p = 0, q = N - 1;
		long long sl = 0, sr = 0;
		while (p < q) {
			if (sl < sr) sl += A[p++];
			else sr += A[q--];
		}
		if (sl == sr) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}