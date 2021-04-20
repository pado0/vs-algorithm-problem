#include <iostream>
#include <queue>

using namespace std;
int box[1002][1002];
int flag[1002][1002];

struct xy {
	int x;
	int y;

	xy(int xin, int yin) {
		x = xin;
		y = yin;
	}

};

queue<xy> q;

int main() {
	int M, N, x, y;
	cin >> M >> N;

	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
				box[i][j] = -1;
			}
			else { cin >> box[i][j]; }
		}
	}

	// 시작노드값 넣어주기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {

			if (box[i][j] == 1) {
				q.push(xy(i, j));
				flag[i][j] = 1; // 시작토마토 발견
				//cout <<flag[i][j]<< endl;
			}

		}
	}

	// 하루하루 지나며 시들어가는 토마토

	while (!q.empty()) {
		xy tmp = q.front();
		x = tmp.x;
		y = tmp.y;
		//cout << x <<" " << y << endl ;
		q.pop();

		if (box[x + 1][y] == 0 && flag[x + 1][y] == 0) {
			box[x + 1][y] = 1;
			flag[x + 1][y] = flag[x][y] + 1;
			q.push(xy(x + 1, y));
		}
		if (box[x - 1][y] == 0 && flag[x - 1][y] == 0) {
			box[x - 1][y] = 1;
			flag[x - 1][y] = flag[x][y] + 1;
			q.push(xy(x - 1, y));
		}
		if (box[x][y + 1] == 0 && flag[x][y + 1] == 0) {
			box[x][y + 1] = 1;
			flag[x][y + 1] = flag[x][y] + 1;
			q.push(xy(x, y + 1));
		}
		if (box[x][y - 1] == 0 && flag[x][y - 1] == 0) {
			box[x][y - 1] = 1;
			flag[x][y - 1] = flag[x][y] + 1;
			q.push(xy(x, y - 1));
		}

	}

	int max = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {

			if (flag[i][j] > max) {
				max = flag[i][j];
			}

			if (box[i][j] == 0) {
				cout << "-1";
				return 0;
			}

		}
	}

	cout << max - 1;
}