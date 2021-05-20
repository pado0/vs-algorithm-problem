/*
M 구간 별 공부의 효율성

가장 높은 효율성은?

시간복잡도가 낮으면 공간복잡도가 높아짐
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
	

	// 끝나는 시간이 빠른 것 기준으로 정렬
	//dy[i]: i시간까지 공부했을 때의 효율성?



}