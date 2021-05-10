/*
노드-노드 사이의 최단거리를 구하는 알고리즘

방법]
간선 1개썼을때 > 2개 .. > 노드개수-1 개 썼을때. N개까지 쓰면 사이클이 생기는것이므로 그 전까지만.
음의 사이클이 존재하지 않는 다는 것을 전제로 한다.

1. DIST 배열을 만들어 정점사이의 거리를 무한대로 초기화해준다.
2. 특정 노드에서 간선을 한 번만 써서 갈 수 있는 모든 노드까지의 비용을 확인하고 DIST를 갱신한다
3. 특정 노드에서 간선을 두 번만 써서 갈 수 있는 모든 노드까지의 비용을 확인하고 DIST를 갱신한다.

*/


#include <iostream>
#include <queue>
using namespace std;

int map[201][201];
int dist[100];

struct Edge {

};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int tx, ty, w;

	// 맵구성
	for (int i = 1; i <= m; i++) {
		cin >> tx >> ty >> w;
		map[tx][ty] = w;
	}

	//초기화
	for (int i = 1; i <= n; i++) {
		dist[i] = 2147000000;
	}

	// 출발, 도착지 정보
	int sc, dc;
	cin >> sc >> dc;

	dist[sc] = 0;

	return 0;
}