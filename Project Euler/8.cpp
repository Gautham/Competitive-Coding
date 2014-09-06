#include <iostream>
#include <vector>
using namespace std;

int main() {
	char N[1000];
	cin>>N;
	vector<long long> Q;
	long long P = 1, MaxP = 1;
	for (int i = 0; i < 13; ++i) {
		N[i] -= '0';
		P *= N[i];
		Q.push_back(N[i]);
	}
	MaxP = P;
	for (int i = 13; i < 1000; ++i) {
		if (Q[0] == 0) {
			P = 1;
			for (int j = 1; j < 13; ++j) P *= Q[j];
		} else P /= Q[0];
		N[i] -= '0';
		Q.push_back(N[i]);
		Q.erase(Q.begin());
		P *= Q[12];
		if (P > MaxP) MaxP = P; 
	}
	cout<<MaxP;
	return 0;
}