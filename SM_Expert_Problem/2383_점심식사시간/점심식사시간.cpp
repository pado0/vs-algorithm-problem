/*
목표: 빨리 내려가기



이동완료시간: 모든사람들이 계단을 내려가 아래층으로 이동한 시간
1. 이동시간: 계단 입구까지의 거리
2. 계단 내려가는 시간:
   - 대기시간 1분
   - 동시 3명까지만 계단에 올라가기 가능, 아니라면 완전히
     내려갈 때까지 대기해야함
- 계단 내려가는 시간 = 계단길이 K (칸마다 다름)

? 입구도착 기준 ? >계단 써있는 칸으로 올라가기
입구도착인원의 제한은 없음
계단 입구는 2개

이동완료 최소시간 출력.

>풀이
: 사람끼리 겹쳐도 되는게 킹받네 음 어떻게 이동시키지?
!!! 제일 가까운 계단에 가는게 능사가 아닐 수 도 있음

1)계단 선택: 각 사람이 계단1 / 계단 2 선택하는 모든 경우 방문 (dfs)
2) 계단까지의 이동
   p를 struct로 만들어 현재위치, 계단까지 걸린시간 기록 ex.queue.push(p(x,y, n+1))
   각 p에 id 부여 필요(index로 하기)
    >> bfs 할 필요 없이 그냥 거리 계산해주기
3) 계단에 도착한 p 시간 순서대로 계단 내려가게 처리해주기
   - 제일늦은 계단 도착시간 + 계단 내려가는 시간
   ? 계단 도착
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int N;
int map[12][12];
int cnt = 0; // 사람 수 count

struct person {
	int x, y, time, stair;
	person() {

	 }
	person(int xi, int yi, int timei, int stairi) {
		x = xi; y = yi; time = timei; stair = stairi;
	}

	bool operator < (const person &d) const {
		return time < d.time;
	}
};

struct person p[10];
vector<pair<int, int>> stair;
priority_queue<int> pq;
vector < pair<int, int >> vv;

void dfs(int n, int s) {

	if (s == 0) {
		p[n].stair = 0;
	}
	else {
		p[n].stair = 1;
	}

	int sx, sy;
	if (n == cnt - 1) {
		//뭐가 몇번계단인지를 리턴해야함
		cout << "어떤 노드가 몇번 개단인지" << endl;
		for (int i = 0; i < cnt; i++) {

			//어느 노드가 몇 번 째 ㄱ 계단을 쓰는지 p[i]에 들어있음
			int x = p[i].x;
			int y = p[i].y;
			sx = stair[p[i].stair].first;
			sy = stair[p[i].stair].second;


			// 계단까지 얼마나 걸리는지 시간이 들어있음
			p[i].time = abs(x - sx) + abs(y - sy);
			cout << p[i].x << " " << p[i].y << " " << p[i].stair << " " << p[i].time << endl;

			pq.push(-p[i].time);
		}

		int count = -pq.top() +1;
		vv.push_back(make_pair(-pq.top(), count));
		pq.pop();
		
		// 계단 도착시간까지 알아냈는데, 큐에 넣고 3개씩 묶어서 n초간 내려가는건
		// 어떻게 처리해야하지? 모르겠다.
		// 내일까지 고민해보고 답 확인하기
		//count+1 값을 넣는다
		/*while (!pq.empty()) {
			

		}*/
	}


	else {
		dfs(n + 1, 0);
		dfs(n + 1, 1);
	}

}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) { 
				p[cnt].x = i;
				p[cnt].y = j;
				p[cnt].time = 0;
				cnt++;
			}
			else if (map[i][j] != 0) {
				stair.push_back(make_pair(i, j));
			}
		}
	}

	//첫번째 노드 기준으로 dfs 진행하기
	//dfs 1번계단
	dfs(0, 0); //0번노드 1번계단
	//dfs 2번계단
	dfs(0, 1);

}