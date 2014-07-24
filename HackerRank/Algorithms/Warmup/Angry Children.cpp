#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	unsigned int N, K, t;
	vector<unsigned int> Packet;
	cin>>N>>K;
	for (int i = 0; i < N; ++i) {
		cin>>t;
		Packet.push_back(t);
	}
	sort(Packet.begin(), Packet.end());
	int min = Packet[K - 1] - Packet[0];
	for (int i = 1; i < N - K + 1; ++i) {
		t = Packet[K + i - 1] - Packet[i];
		if (t < min) min = t;
	}
	cout<<min;
}