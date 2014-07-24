#include <iostream>
#include <vector>
using namespace std;


int main() {
	int N, T, w, i, j;
	vector<int> W;
	cin>>N>>T;
	for (int p = 0; p < N; ++p) {
		cin>>w;
		W.push_back(w);
	}
	while (T--) {
		cin>>i>>j;
		int min = W[i];
		if (min == 1) {
			cout<<1<<endl;
			continue;
		}
		for (w = i + 1; w <= j; ++w) {
			if (W[w] < min) {
				min = W[w];
				if (min == 1) break;
			}
		}
		cout<<min<<endl;
	}
	return 0;
}
