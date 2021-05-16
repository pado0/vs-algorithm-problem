// 배열 안만들어도 됨
// 비교시 min, max 함수 사용

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


int dy[1001]; // dy[i] : i시간에 푼 최대 점수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// M시간 안에 N개의 문제 중 최대점수를 얻을 수 있도록.
	int N, M, ts, tt;

	cin >> N >> M;

	// 풀었을 때의 점수와, 걸리는 시간이 차례대로 주어짐
	// 뒤에부터 비교해야하는 이유? > 앞에서 부터 하면 중복됨.
	// !! 같은문제를 여러번 풀면 안돼서 중복 불가!!!
	// 아, 그래서 뒤에부터 채우면 되는구나.. 앞에 저장됐던 값이 없응께!

	for (int i = 1; i <= N; i++) {
		cin >> ts >> tt;

		for (int j = M; j >= tt; j--) {
			dy[j] = max(dy[j], dy[j - tt] + ts);

		}
	}

	cout << dy[M];

}