#include <bits/stdc++.h>
#include "Overflow.h"
using namespace std;

int main() {
	_ll S = 0;
	FORie(i, 1, 1000) S = (S + ExpMod(i, i, 10000000000)) % 10000000000;
	cout<<S;
	return 0;
}