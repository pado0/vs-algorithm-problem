/*
- 모든 정점에서 모든 정점으로 가는 최소비용을 구하는데 사용하는 알고리즘
- 다이나믹 프로그래밍으로 푼다
- i->j로 가는 최소비용을 i->k->j를 거쳐 가는 최소비용과 비교한다.
- 모든 정점을 거쳐가는 경우를 다 세기 위해 3중 for문이 필요하다
- k=1, 1을 거쳐갈때, k=2,2를 거쳐갈때를 단계별 갱신하다보면 5->4갈때도 5->2,1거침 ->4로 가는게 자연스럽게 갱신됨
- 어렵지 않다!

*/

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

long long dis[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, x, y, w;
	cin >> N >> M;

	// 초기화 Max, 0
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = 2147000000;
		}
	}

	// 입력받기
	for (int i = 1; i <= M; i++) {
		cin >> x >> y >> w;
		dis[x][y] = w;
	}


	// 알고리즘
	for (int k = 1; k <= N; k++) { // 거쳐가는 노드
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	// 출력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(dis[i][j]==2147000000) cout << "M ";
			else cout << dis[i][j] << " ";
		}
		cout << "\n";
	}
}