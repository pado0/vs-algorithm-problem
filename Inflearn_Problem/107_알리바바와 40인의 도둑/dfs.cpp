
/*
나의 다이나믹 프로그래밍 문제점
- 아직 top dowm과 bottom up 해법의 차이점이 와닿지 않는다.
- 문제를 쪼개는걸 잘 못하겠다.
- 알리바바같은 문제도 작은문제가 반복되는 규칙을 찾아야하는데,
  브루트포스처럼 다 확인해주는 코드만 짜진다....
  dfs로 하고 메모이제이션만 하는건 dp가 아니잖아..
*/

/*
#include <iostream>
#include <queue>

using namespace std;
int N;
int map[22][22];
queue<pair<int, int>> q;
int min_e = 2147000000;

void dfs(int x, int y, int h) {

	if (h > min_e)return;
	if (x > N || y > N) return;
	if (x == N && y == N) {
		if (h < min_e) min_e = h;
	}
	else {

		dfs(x + 1, y, h + map[x+1][y]);
		dfs(x, y + 1, h + map[x][y+1]);
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 높이가 다른 돌다리 N x N
	// 최단거리 이동
	// 최소 에너지(높이)

	// 오른쪽, 아래로만 가면 무조건 최소.
	// 오른쪽, 아래 중 작은 칸으로 이동
	// 다 가보는 수 밖에 없지 않나?

	cin >> N;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(1, 1, map[1][1]);
	cout << min_e;
}

*/