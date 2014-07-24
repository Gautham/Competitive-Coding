#include <iostream>
#include <bitset>
using namespace std;


int main() {
	int N, count = 0;
	char A[101];
	bitset<26> gems, el;
	cin>>N>>A;
	for (int i = 0; A[i] != '\0'; gems[A[i++] - 'a'] = true);
	while (--N) {
		cin>>A;
		for (int i = 0; A[i] != '\0'; el[A[i++] - 'a'] = true);
		gems &= el;
		el.reset();
	}
	for (int i = 0; i < 26; count += gems[i++]);
	cout<<count;
	return 0;
}
