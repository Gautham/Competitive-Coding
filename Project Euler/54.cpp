#include <bits/stdc++.h>
#define _ll long long
#define Max(a, b) (a > b) ? a : b
#define Min(a, b) (a < b) ? a : b
#define gcd __gcd
#define FOR(i, a, n) for (i = a; i < n; ++i)
#define FORe(i, a, n) for (i = a; i <= n; ++i)
#define FORi(i, a, n) for (int i = a; i < n; ++i)
#define FORie(i, a, n) for (int i = a; i <= n; ++i)
#define endl '\n'
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

class Card {
	public:
		int Value;
		char Deck;	
		
		Card() {
			Value = Deck = 0;
		}

		Card(string C) {
			Set(C);
		}

		void Set(string C) {
			Deck = C[1];
			switch (C[0]) {
				case 'T':
					Value = 10;
					break;
				case 'J':
					Value = 11;
					break;
				case 'Q':
					Value = 12;
					break;		
				case 'K':
					Value = 13;
					break;
				case 'A':
					Value = 14;
					break;
				default:
					Value = (int)C[0] - '0';
					break;
			}
			if (Value == 0) cout<<C<<endl;
		}
};

int HandScore(vector<Card> X) {
	//	Straight Flush & Royal Flush
	char Deck = X[0].Deck;
	int Value = X[0].Value;
	bool flag = true;
	FORi(i, 1, 5) if (X[i].Deck != Deck || X[i].Value != (Value + i)) flag = false;
	if (flag) return (Value == 10) ? 1700 : (1600 + X[4].Value);	

	//	Four Of a Kind
	if (((X[0].Value == X[1].Value) && (X[1].Value == X[2].Value) && (X[2].Value == X[3].Value)) || ((X[1].Value == X[2].Value) && (X[2].Value == X[3].Value) && (X[3].Value == X[4].Value)))
		return (1500 + X[2].Value);

	//	Full House
	if (X[0].Value == X[1].Value && ((X[2].Value == X[3].Value) && (X[3].Value == X[4].Value))) return 1200 + X[4].Value * 15 + X[1].Value;
	if (X[3].Value == X[4].Value && ((X[0].Value == X[1].Value) && (X[1].Value == X[2].Value))) return 1200 + X[2].Value * 15 + X[4].Value;

	//	Flush
	if (X[1].Deck == Deck && X[2].Deck == Deck && X[3].Deck == Deck && X[4].Deck == Deck) return 1100 + X[4].Value;

	//	Straight
	flag = true;
	FORi(i, 1, 5) if (X[i].Value != Value + i) flag = false;
	if (flag) return 1000 + X[4].Value;

	flag = false;
	int x = 0, y;
	if (((X[0].Value == X[1].Value) && (X[1].Value == X[2].Value)) ||
		((X[1].Value == X[2].Value) && (X[2].Value == X[3].Value)) ||
		((X[2].Value == X[3].Value) && (X[3].Value == X[4].Value))) return 700 + X[2].Value;

	FORi(i, 1, 5) if (X[i].Value == X[i - 1].Value) {
		++x;
		y = i;
	}
	if (x == 2) return 400 + X[y].Value * 15 + X[4].Value;
	if (x == 1) return 100 + X[y].Value * 15 + X[4].Value;
	return -1;
}

bool CardCompare(const Card &X, const Card &Y) {
	return (X.Value < Y.Value);
}

int main() {
	FastIO
	int Z = 1000, Count = 0;
	string P;
	while (Z--) {
		vector<Card> P1(5), P2(5);
		FORi(i, 0, 5) {
			cin>>P;
			P1[i].Set(P);
		}
		sort(P1.begin(), P1.end(), CardCompare);
		FORi(i, 0, 5) {
			cin>>P;
			P2[i].Set(P);
		}
		sort(P2.begin(), P2.end(), CardCompare);
		int X = HandScore(P1), Y = HandScore(P2);
		if (X > Y) ++Count;
		if (X == Y) {
			int i = 4;
			while (i >= 0 && P1[i].Value == P2[i].Value) --i;
			if (i >= 0 && P1[i].Value > P2[i].Value) ++Count;
		}
	}
	cout<<Count;
	return 0;
}