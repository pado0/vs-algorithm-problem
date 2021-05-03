/*
top dwn은 재귀로 해결한다
dfs(7): 7m를 1, 2m로 자르는 방법의 수를 리턴한다
- 마지막 자르는 것을 1m or 2m로 분리처리
- 1m > dfs(6), 2m > dfs(5)
- 즉 dfs(7) = dfs(6) + dfs(5)

*/

#include <iostream>
using namespace std;
int memo[200];

int dfs1(int n) {
	
	//이 코드가 가지치기 코드.
	// 이미 있는 값은 패스하고 넘어갈 수 있음
	if (memo[n] > 0) return memo[n];

	// n이 작을때 값 넣어주기
	if (n == 1 || n ==2 ) { return n; }
	else {
		// 메모이제이션 구현
		return memo[n] = dfs1(n - 1) + dfs1(n - 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	cout << dfs1(N);
}