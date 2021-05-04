#include <iostream>
using namespace std;

int memo[21][21];

int dfs(int n, int r) {
	// nCr 을 2차원 배열에 저장하여 이미 있는 값이면 리턴
	if (memo[n][r] > 0) return memo[n][r];
	if (n == r || r == 0 ) return 1;
	else {
		return memo[n][r] = dfs(n - 1, r) + dfs(n - 1, r - 1);
	}
}

int main() {
	// 5개중 3개를 뽑는 경우의수?
	// 이항계수의 성질 5C3 = 4C2+4C3
	// 5개중 3개를 D뽑는 것은 
	// 1)맨 마지막 5번째 껄 뽑고 4개에서 2개뽑는거
	// 2)맨 마지막 5번째 껄 안뽑고 4개에서 3개뽑는거

	//3C2 = 2C1 + 2C2 , 2C1 = 1C1 +1C0

	int n, r;
	cin >> n >> r;

	cout << dfs(n, r);
}