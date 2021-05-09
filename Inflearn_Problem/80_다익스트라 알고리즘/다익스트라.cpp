/*
다익스트라: 특정한 하나의 노드에서 다른 모든 노드까지의 거리 최소비용 출력, MST와는 다른개념. 
최단거리만 따지기 때문에 루프가 있을수도 있음.
- 다이나믹 프로그래밍이다 : 최단거리는 여러개 최단거리의 합이기 때문. 이전에 구했던 최단거리를 그대로 사용
- 현재까지 알고있는 최단경로를 계속 갱신 > max로 세팅해놓는 방법 말고, 계속 최소만 선택하는 방법으로 구현했는데
- 이거 틀릴것같다. 경로 합이, 바로가는 경로보다 작다는걸 증명해야함. 아래껀 그냥 프림에 dist 추가한게 됨.

- 한번 선택한 값은 다른것에 의해 최소로 갱신될 수 있을까?
- 아니 없다, 현재 상태에서의 최소값이므로.
- 첨언하면, 다시 그 노드로 가려면 다른 노드를 무조건 거쳐야한다는 것인데
- 그 거치는 노드들은 최소값이 아닐것이므로.
*/

#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int map[21][21];
int flag[21];
int dist[21];

struct Edge {
	int v, w;

	Edge(int v1, int w1) {
		v = v1; w = w1;
	}

	bool operator < (const Edge &d) const {
		return w > d.w; // 오름차순 정렬
	}
};

priority_queue<Edge> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int x, y, w;

	cin >> n >> m;


	// 맵 세팅해주기
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		map[x][y] = w;
	}

	for (int i = 2; i <= n; i++)dist[i] = 2147000000;

	pq.push(Edge(1, 0));

	int vt, wt;
	while (!pq.empty()) {
		
		// 가중치가 가장 작은 노드 선택
		vt = pq.top().v;
		wt = pq.top().w;

		//top으로 봐준건 계속 빼줌
		pq.pop();
		
		// 방문하지 않은 노드인 경우 거리갱신, 이미 방문했을 경우엔 pass
		if (flag[vt] == 0) {
			flag[vt] = 1;


			// 방문 가능한 노드를 전부 큐에 넣어놓는다
			// 방금 편입된 노드 vt를 거쳐 나머지 노드로 가는 최단거리를 여기서 갱신해야함.

			for (int i = 1; i <= n; i++) {
				if (map[vt][i] != 0 && flag[i] == 0) {
					// 연결된 노드를 큐에 다넣어준다
					pq.push(Edge(i, map[vt][i]));
					
					// 연결된 노드들 가중치 합 확인했을때 작으면 갱신
					if (dist[vt] + map[vt][i] < dist[i]) {
						dist[i] = dist[vt] + map[vt][i];
						
					}
				}
			}
		}

	}

	for (int i = 2; i <= n; i++) {
		cout << i << " : ";
		if(dist[i]!=2147000000) cout << dist[i] << "\n";
		else cout << "impossible" << "\n";
	}
	return 0;
}