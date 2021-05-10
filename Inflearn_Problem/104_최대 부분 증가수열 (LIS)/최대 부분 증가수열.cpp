/*

// 아래 풀이 (재귀)로 푸니 시간이 너무 오래걸린다. . 이렇게 오래걸릴 일?
가지치기 해줄 수는 있는데 dp로도 풀자

#include <iostream>
using namespace std;
int arr[100];
int max = 0;
int n;

// max보다 적게 len수열이 남았을 경우 끊어주기
void dfs(int index, int len) {
	if (index >= n  ) {
		if (len > max) max = len;
		return;
	}

	else {

		if (arr[index] < arr[index + 1]) {

			//작은것 채택
			dfs(index + 1, len + 1);
			
			//작은것 채택 x
			dfs(index + 1, len);
		}
		else {
			// 큰것 채택x
			dfs(index + 1, len);
		}

	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 순서는 그대로 유지한 채 원소들을 골라, 부분 수열의 가장 큰 증가 길이를 출력한다.
	// 재귀로 구현해야할 것 같은데, 해당 원소를 선택할지 말지. 시작 기준점보다 값이 작은애를 선택할지 말지
	// 후에 줄여줄 수 있는 것 가지치기 > 시간이 너무 오래걸림. 못함.


	// dp로 풀어주기: index i를 마지막항으로 하는 증가수열 count 하기


	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	//처음원소 채택, 미채택
	dfs(0, 1);
	dfs(0, 0);

	cout << max;
	
	return 0;
}

*/