#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	long long T, N, end;
	vector<long long > Fibonacci;
	Fibonacci.push_back(0);
	Fibonacci.push_back(1);
	end = 1;
	cin>>T;
	while (T--) {
		cin>>N;
		long long p = Fibonacci[end];
		if (N <= p) {
			if (binary_search(Fibonacci.begin(), Fibonacci.end(), N)) cout<<"IsFibo\n";
			else cout<<"IsNotFibo\n";
		} else {
			long long q = p + Fibonacci[end - 1];
			long long temp;
			while (p < N) {
				temp = p;
				p = q;				
				q += temp;
				Fibonacci.push_back(p);
				++end;			
			}
			if (p == N) cout<<"IsFibo\n";
			else cout<<"IsNotFibo\n";	
		}
	}
}