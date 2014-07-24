#include <iostream>
#include <bitset>
using namespace std;

int main() {
	char A[100001];
	int i;
	cin>>A;
	bitset<26> flag;
	for (i = 0; A[i] != '\0'; ++i) flag[A[i] - 'a'] = !flag[A[i] - 'a'];
	if (flag.count() > (i % 2)) cout<<"NO";
	else cout<<"YES";
	return 0;
}