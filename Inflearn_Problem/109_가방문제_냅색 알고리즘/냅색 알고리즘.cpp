#include <iostream>

using namespace std;

struct jew {
	int weight, value;
};

struct jew jew[30] ;
int dy[31];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L; // N: 보석 종류개수, L: 가방 한계 무게
	cin >> N >> L;

	// L kg를 넘지 않으면서 최대가치가 되어야한다.
	// 제일 가치가 큰것 중 제일 가벼운것 먼저 넣는다. > 아니다.
	// 각 kg를 담았을 때 가치를 저장한다.
	// 각 1개씩 담았을 때 가치
	// 그다음 2개 담았을 때 가치
	// > 이 문제의 문제점은 현재의 최선이 최선이 아닐 수 있다는 것

	int tw, tv;
	for (int i = 0; i < N; i++) {
		cin >> tw >> tv;
		jew[i].value = tw;
		jew[i].value = tv;
	}

	return 0;
}