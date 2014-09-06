#include <iostream>
using namespace std;

int main() {
	int V, N, A[1000], i;
	cin>>V>>N;
	for (int i = 0; i < N; ++i) {
		cin>>A[i];
	}
	for (i = 0; i < N && A[i] != V; ++i);
	cout<<i;
    return 0;
}