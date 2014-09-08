#include <iostream>
#include <tr1/unordered_set>
using namespace std;

int main() {
	tr1::unordered_set<int> Tr;
	for (int i = 1; i < 50; ++i) Tr.insert(i * (i + 1) / 2);
	string A;
	int count = 0;
	while (getline(cin, A)) {
		if (A == "") continue;
		int z = 0;
		for (int i = 1; A[i] != '\"'; ++i) z += A[i] - 'A' + 1;
		if (Tr.count(z)) ++count;
	}
	cout<<count;
	return 0;
}
