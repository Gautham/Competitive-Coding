#include <iostream>
using namespace std;

int main() {
	int T, N;
	cin>>T;
	while (T--) {
		cin>>N;
		bool flag = false;
		char A[N + 1];
		for (int i = N; i >= 0; --i) {
			if ((i % 3 == 0) && ((N - i) % 5 == 0)) {
				int p = 0;
				for (; p < i; ++p) A[p] = '5';
				for (; p < N; ++p) A[p] = '3';
				A[p] = '\0';
				flag = true;
				cout<<A<<endl;
				break;
			}
		}
		if (!flag) cout<<-1<<endl;
	}
}