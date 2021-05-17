/*
다른 모두와 친구이면 1점
다른 모두와 친구 OR 친구의 친구이면 2점
...

*/
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

int mem[51][51]; //mem[i][j] : i와 j가 얼마나 먼 친구사이인지
int score[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // 회원수
	int x= 0, y=0;
	
	cin >> N;
	//초기화
	for (int i = 1; i <= N; i++) { // 
		for (int j = 1; j <= N; j++) {
			mem[i][j] = 100;
		}
	}

	while (true) {
		cin >> x >> y;
		if (x == -1 && y == -1) break;
		mem[x][y] = 1;
		mem[y][x] = 1;
	}

	for (int k = 1; k <= N; k++) { // 거쳐갈 친구 고르기
		for (int i = 1; i <= N; i++) { // 
			for (int j = 1; j <= N; j++) {
				mem[i][j] = min(mem[i][j], mem[i][k] + mem[k][j]);
			}
		}
	}

	// 점수 기록하기, 각 행의 max값이 그 사람의 점수
	int min = 2147000000;
	for (int i = 1; i <= N; i++) { // 
		for (int j = 1; j <= N; j++) {
			if (mem[i][j] > score[i] && mem[i][j]!=100) score[i] = mem[i][j];
		}
		if (score[i] < min) min = score[i];
	}

	// 회장 점수 ,수
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (score[i] == min) cnt++;
//		cout << score[i] << " ";
	}
	cout << min << " " << cnt << "\n";

	for (int i = 1; i <= N; i++) {
		if (score[i] == min) cout << i << " ";
	}


}