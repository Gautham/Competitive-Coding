#include <iostream>
#include <tr1/unordered_map>
using namespace std;
using namespace tr1;

int main() {
	int num = 1, den = 2, max = 0, maxVal, Val[1000];
	while (den < 1000) {
		num = 1;
		int t = num, p = 0;
		unordered_map<int, int> Map;
		while (1) {
			while (num < den) num *= 10;
			num = num % den;
			if (num == 0) {
				Val[den] = 0;
				break;
			}
			if (Map.count(num) > 0) {
				Val[den] = p - Map[num];
				if (Val[den] > max) {
					max = Val[den];
					maxVal = den;
				}
				break;
			} else {
				Map[num] = p;
			}
			++p;
		}
		++den;
	}
	cout<<maxVal;
	return 0;
}