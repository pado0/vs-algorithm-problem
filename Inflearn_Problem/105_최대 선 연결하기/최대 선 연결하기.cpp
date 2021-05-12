#include <iostream>
using namespace std;

int rightArr[101];
int dy[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 선이 겹치지 않고 자기 선을 찾아가기. 최대값음?
	// 와, 최대 부분 증가수열을 그냥 쓰면 되네...
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> rightArr[i];
	}

	// rightArr[i]가 마지막 부분최대증가수열일때
	// 원소개수 세어주기

	dy[1] = 1;

	// i = 기준 값
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (rightArr[i]>rightArr[j]) {

				if(dy[j]+1 > dy[i])
				dy[i] = dy[j] + 1;
			}
		}

		if (dy[i] == 0) dy[i] = 1;
		
	}

	int max = 0;

	for (int i = 1; i <= N; i++) {
		if (dy[i] > max) max = dy[i];
	}
	cout << max;
}