#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

void insertionSort(int * A, int N) {
	int key = A[N - 1];
	int j = N - 2;
	for (; j >= 0 && A[j] > key; --j) {
		A[j + 1] = A[j];
		for (int k = 0; k < N; ++k) cout<<A[k]<<' ';
		cout<<endl;
	}
	A[j + 1] = key;
	for (int k = 0; k < N; ++k) cout<<A[k]<<' ';
	cout<<endl;
}
int main(void) {
   
	int _ar_size;
	cin >> _ar_size;
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
		cin>>_ar[_ar_i];
	}

   insertionSort(_ar, _ar_size);
   
   return 0;
}