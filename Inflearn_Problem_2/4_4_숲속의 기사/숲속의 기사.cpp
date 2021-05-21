#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[1002][1002];
int flag[1002][1002];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

vector<pair<int, int>> berry;
queue<int> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 산딸기의 위치를 찾고
	// 찾은 위치에서 기사에게 가는 최단경로를 찾는다.
	int sx, sy, nx, ny;
	

	int W, H;
	cin >> W >> H;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) { sx = i; sy = j; map[i][j] = 0; }
			else if (map[i][j] == 3) { nx = i; ny = j; }
			else if (map[i][j] == 4) { berry.push_back(make_pair(i, j)); }
		}
	}


	q.push(sx);
	q.push(sy);
	q.push(0); // dist;

	while (!q.empty()) {
		int tx = q.front(); q.pop();
		int ty = q.front(); q.pop();
		int dist = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {

				int ttx = tx + i;
				int tty = ty + j;

				if (ttx <= 0 || tty <= 0 || ttx > H || tty > W) continue;
				if (map[ttx][tty] == 0 && flag[ttx][tty] ==0) {
					flag[ttx][tty] = 1;
					q.push(ttx);
					q.push(tty);
					q.push(dist + 1);

				}
			}
		}



	}








}