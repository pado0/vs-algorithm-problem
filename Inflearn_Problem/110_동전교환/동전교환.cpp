// 거스름돈을 가장 적은 액수의 동전으로 교환.

#include <iostream>
#include <algorithm>
using namespace std;

int coin[13];
int dy[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> coin[i];
	cin >> M; // 거스름 돈

	sort(coin, coin + 1 + N);


	// 가장 큰 것 부터 털어주면 되지않냐 > 아님
	/*
	5
	1 8 20 25 50
	129
	79 29 4 3 2 1 0
	답: 5인데 7로 나옴
	*/
	

	int j, tmp;
	for (int i = 1; i <= N; i++) {
		
		// 동전 선택
		j = coin[i];
		tmp = coin[i];

		//dy[i] : i를 거슬러주는데에 필요한 동전의 개수
		while (j<=M) {
			
			// 최초로 동전 거슬러줄 땐 그냥 갱신하고
			if(dy[j] == 0) dy[j] = dy[j - tmp] + 1;

			// 다른 동전 넣어줄 때 부터 동전 최소개수 비교를 위해 기존 거스름돈 개수 계산한것보다 동전 수가 적게 들면 갱신
			else {
				if (dy[j - tmp] + 1 < dy[j]) dy[j] = dy[j - tmp] + 1;
			}

			j++;
		}
	}

	cout << dy[M];
}