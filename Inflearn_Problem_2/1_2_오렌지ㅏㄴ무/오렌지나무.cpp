/*
11:00 ~

*/

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//오랜지나무가 가장 많이 포함되는 지역의 오렌지나무 개수 구하기

	int W, H, T, S;

	
	cin >> W >> H >> T >> S;

	int x, y;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}



}