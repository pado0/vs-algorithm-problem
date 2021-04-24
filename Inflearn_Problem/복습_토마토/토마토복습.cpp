//�����ڵ�� ���ؼ� �ð��� ������ �پ���.
//!! struct�� int�� ���� �����ϰ� �迭�� ������ �޸� �ʰ��� ����.
// int = 4byte, 1000x1000 x4 = 4MB 
#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
int map[1002][1002];
int flag[1002][1002];
int dx[4] = { 1,0 , -1 ,0 };
int dy[4] = { 0 , 1, 0 ,-1 };
struct t {
	int x, y;
	t(int xi, int yi) {
		x = xi;
		y = yi;
	}
};
queue<t> qt;

int main() {
	ios::sync_with_stdio(false);
	int N, M;
	cin >> M >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j]; // 1: ����, 0:������, -1: �丶�����
			if (map[i][j] == 1) {
				qt.push(t(i, j));
			}
		}
	}

	int x, y, time;

	while (!qt.empty()) {
		x = qt.front().x;
		y = qt.front().y;
		map[x][y] = 1;
		qt.pop();

		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];

			if (tx == 0 || ty == 0 || tx == N + 1 || ty == M + 1)continue;
			if (map[tx][ty] ==0 && flag[tx][ty] == 0) {
				flag[tx][ty] = flag[x][y]+1;
				qt.push(t(tx, ty));	
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0)cnt++;
		}
	}
	if(cnt == 0){
		cout << flag[x][y];
	}
	else {
		cout << "-1";
	}
	
}