/*
>> 문제풀이
1. 입력받기
2. 심바 위치 찾으면 심바 위치 0으로 바꿔주기
3. 심바의 현재 위치 기준으로 bfs를 통해 가장 가까운 토끼 찾기
4. 가장 가까운 토끼 찾았으면 잡아먹고, 사이즈 조정하고 모든걸 0으로 세팅하기
   - 잡아먹은 자리에서 다시 시작해야하니까
*/


#include <iostream>
#include <queue>
using namespace std;
int map[27][27];
int flag[27][27];
int dx[4] = { 1, 0 , -1 , 0 };
int dy[4] = { 0, 1 , 0 , -1 };
int N, M = 0; // N: 정글 크기, M: 토끼 마리 수


struct simba {
	int x, y, size, ate, dist;
	simba() {

	}

	simba(int x1, int y1, int size1, int ate1, int dist1) {
		x = x1; y = y1; size = size1; ate = ate1; dist = dist1;
	}

	bool operator < (const simba &d) const {
		if (dist == d.dist) { // 거리가 같을때
			if (x == d.x) return y > d.y;  // 오름차순 (왼쪽 먼저)
			else return x > d.x;// 오름차순 (위쪽 먼저)
		}
		else {
			return dist > d.dist; // 오름차순 (가까운거 먼저)
		}
	}

};

simba s;

int find_rabbit() {
	int min = 214700000, sum = 0;
	priority_queue<simba> q;
	int x, y, dist, ate = 0, size;
	int tmp = 0;
	q.push(s); // 초기 심바 push

	while (!q.empty()) {
		//더이상 먹을 수 있는 토끼가 없을 때? > 사이즈떄메 못먹는경우는? > dist max는 토끼 먹엇을떄 갱신하면 됨
		//if (ate + tmp == M) break;

		//현재위치
		x = q.top().x;
		y = q.top().y;
		dist = q.top().dist;
		ate = q.top().ate;
		size = q.top().size;

		q.pop();
		//cout << "이동경로" << " x: " << x << "  y " << y << endl;

		// flag는 토끼 한마리 잡아먹고나면 초기화해줘야함
		if (x == 0 || y == 0 || x == N + 1 || y == N + 1 || map[x][y] > size || flag[x][y] == 1)continue;
		if (map[x][y] <= size && flag[x][y] == 0) { // 사이즈가 같거나 지나갈 수 있음, 같으면 안먹어야됨
			flag[x][y] = 1; // 토끼 한마리 잡는 과정에서는 1로 해줘도 됨. 그래야 최소.
			//dist++;

			// 사이즈가 작으면 잡아먹기, 토끼가 있는위치여야해서0빼줌
			if (map[x][y] < size && map[x][y] != 0) {
				ate++; map[x][y] = 0;
				if (ate == size) {
					size++; ate = 0;
					tmp = tmp + ate;
				}
				sum = dist + sum;
				//cout << "잡아먹은 x,y x: " << x << " y: " << y << " dist: " << dist << endl;
				//cout << "sum: " << sum << endl;
				// 잡아먹었으니 flag 초기화? q도 초기화, 여기서 다시시작?
				for (int k = 1; k <= N; k++) {
					for (int l = 1; l <= N; l++) {
						flag[k][l] = 0;

					}
				}
				while (!q.empty()) {
					q.pop();
				}
				min = 214700000;
				dist = 0;

			}
		}

		for (int i = 0; i < 4; i++) {

			int tx = x + dx[i];
			int ty = y + dy[i];


			//사이즈가 다르면 안잡아먹고 그냥 다음 위치로 이동
			//cout << "푸시목록 " << "tx: " << tx << " ty: " << ty << " dist: " << dist << endl;
			q.push(simba(tx, ty, size, ate, dist + 1));
		}
		// 토끼와의 최소거리가 제대로 구해진거 맞나?
		// 토끼 각 위치를 기준점 삼고 거리 계산해야하는거 아닌가?
		// flag 초기화 어디에서 해주지?

	}

	return sum;
}


int main() {

	// 최소거리 & 먹을 수 있는 토끼 찾기
	// 위쪽, 왼쪽 먼저 먹기
	// 크기만큼 마리수 먹기

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				// 심바 초기 위치, 초기크기, 먹은 수 초기화
				s.x = i; s.y = j; s.size = 2; s.ate = 0, s.dist = 0;
				map[i][j] = 0;
			}
			else if (map[i][j] != 0) M++;

		}
	}

	// 먹을 수 있는 토끼 찾기 1)크기 2)최소거리 토끼 찾기 
	// 우선순위 큐로 왼쪽 위에있는 것 먼저 pop하기
	cout << find_rabbit();

}