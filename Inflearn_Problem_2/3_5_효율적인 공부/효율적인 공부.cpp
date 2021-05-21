/*
M 구간 별 공부의 효율성
가장 높은 효율성은?
다이나믹 프로그래밍 > 아, 어렵다. dy[i] 정하기 연습이 필요해보임.

*/

#include <iostream>
#include <algorithm>
using namespace std;

int dy[1000001];
struct study_time {
	int s, e, ef;

	bool operator < (const study_time &d) const {
		return e < d.e;
	}
};

struct study_time study[1001];

int main() {
	int N, M, R;
	int st, et, eff;

	// N 초의 경부시간이 주어졌을 때 5개 구간중 가장 높은 효율성,
	// R만큼의 휴식시간은 필수임
	cin >> N >> M >> R; 

	for (int i = 1; i <= M; i++) {
		cin >> st >> et >> eff;
		study[i].s = st;
		study[i].e = et;
		study[i].ef = eff;
	}

	sort(study + 1, study + M + 1);
	

	//dy[i]: i번째 인덱스에 있는 구간을 스케쥴의 마지막으로 공부했을 때 최대 효율

	for (int i = 1; i <= M; i++) {
		dy[i] = study[i].ef; // i번째가 마지막이니까 그 구간 효율은 무조건 들어감
		for (int j = i - 1; j > 0; j--) {
			// 끝나는시간이 시작시간보다 작고, i까지의 최대효율보다 크면
			if (study[j].e + R <= study[i].s && dy[j] + study[i].ef > dy[i]) {
				dy[i] = dy[j] + study[i].ef;

			}
		}
	
	}

	int max_e = 0;
	for (int i = 1; i <= M; i++) {

		max_e = max(max_e, dy[i]);
	}

	cout << max_e;
}