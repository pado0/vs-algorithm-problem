#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int flag[100];
int map[100][100];

struct Edge {
	int v;
	int w;

	Edge(int v1, int wi) {
		v = v1; w = wi;
	}
	bool operator < (const Edge &d) const {
		return w > d.w;

	}
};

// 이건 가중치 우선순위 뺄때 빼주기
priority_queue<Edge> pq;


int main() {
	int x, y, w;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	// prim 알고리즘이란? 방문한 노드와 연결된 모든 엣지 중 가장 가중치가 적은것을 선택한다.
	// 이미 선택한 노드는 pass한다.

	// 우선순위 큐를 쓰겠다.
	// 1. 출발 정점을 우선순위 큐에다 넣는다. (정점번호, 간선가중치를 쌍으로 넣는다)
	// 2. 방문한 정점은 flag처리, 정점 번호에서 갈 수 있는 노드, 가중치를 모두 큐에 넣는다.
	// 3. POP 한 edge와 연결된 노드를 선택한다.
	
	// 의문? 우선순위 큐는 가중치 작은게 먼저뽑히는데.. 연결한 노드가 또 연결되지 않음?
	// - 이렇게 되었을때, 이미 선택된 노드는 간선 선택을 하면 안된다. 그냥 pop시키면 됨.
	// - 누적하지 않고 pop해서 지나가버림
	

	/*
	필요한건?
	- map을 구성할 배열 형태 > 어떤 노드가 누구랑 가중치 몇으로 
	
	연결되어있는지 확인하기 위한 map
	*/


	int v, e;

	cin >> v >> e;
	// 맵구성
	for (int i = 1; i <= e; i++) {
		cin >> x >> y >> w;
		map[x][y] = w;
		map[y][x] = w;
	}
	
	pq.push(Edge(1, 0));

	int sum = 0;

	while (!pq.empty()) {
		int vin = pq.top().v;
		int w = pq.top().w;
		// cout << "v: " << vin <<" w: " << w << "\n";
		pq.pop();
		// 안갔던 노드이면 가고, 갔던 노드이면 스킵
		
		if (flag[vin] == 0) {

			flag[vin] = 1;
			sum = sum + w;


			for (int i = 1; i <= v; i++) {
				if (map[vin][i] != 0 && flag[i] == 0){ // 이미 방문한 노드는 빼줌
					// cout << "chk";
					pq.push(Edge(i, map[vin][i])); // 연결된 노드와 가중치를 push
				}
			}
		}

	}

	cout << sum;


}