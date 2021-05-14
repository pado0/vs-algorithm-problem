
/*
나의 다이나믹 프로그래밍 문제점
- 아직 top dowm과 bottom up 해법의 차이점이 와닿지 않는다.
- 문제를 쪼개는걸 잘 못하겠다.
- 알리바바같은 문제도 작은문제가 반복되는 규칙을 찾아야하는데,
  브루트포스처럼 다 확인해주는 코드만 짜진다....
  dfs로 하고 메모이제이션 하면 topdown,,?


// 메모이제이션 어디다할까?
// xy위치까지 가는데 걸리는 에너지를 dy에 기록
// - top down > 도착지부터 back해서 재귀의 재귀 리턴값 int를 넘김. 도착지부터 하나 처음부터 하나 다를게무어야
// 아 패러다임자체가 진짜 다르구나. top에서 시작해서 되돌가아며, 초기값을 찍고 하나하나씩 더해짐. 중간중간 이미 계산한 값들을 메모이제이션.
// 그냥 dfs에서도 메모이제이션 해보기. 가능할것가틍데?

*/

#include <iostream>
#include <queue>

using namespace std;

int dy[22][22];
int N;
int map[22][22];
int min_e = 2147000000;
int h = 0;

int dfs(int x, int y) {
	// 그 위치까지 가는 데걸리는 값을 기록!!!!!!!!!!!!!!!!!!!!
	// 처음방문
	if (dy[x][y] != 0) return dy[x][y];
	if (x == 1 && y == 1) return dy[x][y] = map[x][y];
	else {
		
		if (y == 1) return dy[x][y] = dfs(x - 1, y) + map[x][y];
		else if (x == 1) return dy[x][y] = dfs(x, y - 1) + map[x][y];
		else {
			// 현재까지 온 길 중 가장 작은놈을 골라 감
			return dy[x][y] = min(dfs(x - 1, y), dfs(x, y - 1)) + map[x][y];
			//dfs(a) : a까지 가는데 걸리는 값, 둘중에 최소가 최적이라고 할 수 있는 것은
			// X-1,Y와 X, Y-1까지 간 경로의 길이를 뜻하므로, 둘중에 작은값이 무조건 최적이지.

		}

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

	cout << dfs(N, N);
}
