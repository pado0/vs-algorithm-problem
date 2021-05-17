/*
위상정렬
- 일의 우선순위를 정하는 알고리즘
1. 진입 간선이 없는 노드 모두 선택해서 큐에 넣음
2. 아무거나 팝하고, 팝한 노드의 간선을 제거
3. 다시 진입 간선이 없는 노드 큐에 넣음
*/

// 코드 간소화를 위한
//추가작업 degree[]배열을 통해, 각 노드에 대한 진입 엣지 개수를 기록하여
// degree[i] = 0인것 먼처 큐에 처리. 1을 큐에 넣고 팝했다면 1과 연결된 모든 진입차수를 없애줌
// 1->4 없애려면 degree[4]-1 해주기. 해당 값이 0이 되면 다시 push 해주기

#include <iostream>
#include <queue>

using namespace std;
int map[100][100];
int chk[100];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, x, y;

	cin >> N >> M;

	//입력, 맵 구성
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		map[x][y] = 1;
	}
	

	// input없는노드? 열이 모두 0인 점
	for (int t = 1; t <= N; t++) {
		for (int i = 1; i <= N; i++) { // 열선택
			int flag = 0;
			for (int j = 1; j <= N; j++) {
			
				// 연결된게 아무것도 없는 노드인지 확인
				if (map[j][i] != 0) flag = 1;
			}

			// 아무것도 없으면 push
			if (flag == 0 && chk[i] == 0) {
				q.push(i);
				chk[i] = 1;
			}
		}

		// 위상정렬 out
		int start = q.front();
		cout << start << " ";

		// pop시키고 엣지 끊어주기
		q.pop();
		for (int i = 1; i <= N; i++) map[start][i] = 0;

	}

}