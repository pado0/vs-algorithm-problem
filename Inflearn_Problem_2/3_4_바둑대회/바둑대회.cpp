// 12:36~ 1:03

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
int N;
int score;
int min_score = 2147000000;

void dfs(int num, int wn, int bn, int black, int white) {
	if (wn > N / 2 || bn > N/2) return;
	if (num == N-1) {
		score = abs(black - white);
		// cout << "score: " <<score << endl;
		if (score < min_score) min_score = score;
	}
	else {

		num ++;
		// cout << "num: " << num << " first: " << v[num].first << endl;
		dfs(num, wn, bn+1, black + v[num].first, white);
		dfs(num, wn+1, bn,  black, white + v[num].second);

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 흰돌 N/2 검은돌 N/2
	//흰돌과 검은돌 능력차가 최소
	
	int x, y;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	// dfs 선수가 검은돌선택 0 or 흰돌선택 1
	dfs(0, 0, 1, v[0].first, 0);
	dfs(0, 1, 0, 0,  v[0].second);
	
	cout << min_score;
}