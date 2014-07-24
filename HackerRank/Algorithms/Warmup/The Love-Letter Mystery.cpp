#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;


int main() {
	int T, count, len, end;
	char A[10001];
	cin>>T;
	while (T--) {
		count = 0;
		cin>>A;
		len = strlen(A);
		end = len / 2;
		for (int i = 0; i < end; ++i) {
			count += abs(A[i] - A[len - i - 1]);
		}
		cout<<count<<endl;
	}

	return 0;
}
