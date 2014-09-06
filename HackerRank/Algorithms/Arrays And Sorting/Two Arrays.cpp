#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() 
{
	long long T, N, K, t;
	cin>>T;
	while (T--) {
		vector<long long> A, B;
		cin>>N>>K;
		for (int i = 0; i < N; ++i) {
			cin>>t;
			A.push_back(t);
		}
		for (int i = 0; i < N; ++i) {
			cin>>t;
			B.push_back(t);
		}
		sort(A.begin(), A.end());
		sort(B.rbegin(), B.rend());
		bool flag = true;
		for (int i = 0; i < N; ++i) {
			if (A[i] + B[i] < K) {
				cout<<"NO\n";
				flag = false;
				break;
			}
		}
		if (flag) cout<<"YES\n";
	}

}
