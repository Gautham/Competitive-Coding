#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() 
{
	long long n, k;
	cin>>n>>k;
	vector<int> prices;
	for(int i = 0; i < n; i++)
	{
		int p;
		cin>>p;
		prices.push_back(p);
	}
	sort(prices.begin(), prices.end());
	
	int cost = 0, i;
	for (i = 0; i < n && (cost + prices[i]) <= k; cost += prices[i++]);
	cout<<i<<endl;
	
	return 0;
}
