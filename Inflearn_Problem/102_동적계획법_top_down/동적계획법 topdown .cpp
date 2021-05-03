/*
top dwn은 재귀로 해결한다
dfs(7): 7m를 1, 2m로 자르는 방법의 수를 리턴한다
- 마지막 자르는 것을 1m or 2m로 분리처리
- 1m > dfs(6), 2m > dfs(5)
- 즉 dfs(7) = dfs(6) + dfs(5)


#include <iostream>
using namespace std;
int memo[200];

int dfs1(int n) {

	//이 아래 코드 로직 줄일 수 있으나, 속도엔 큰 영향x
	if (n == 1) {  return 1; }
	else if (n == 2) { return 2; }

	else {
		// 리턴값 코드 줄일 수 있음  
		int a, b;
		if (memo[n - 1] == 0) {
			a = dfs1(n - 1);
			memo[n - 1] = a;

		}
		else {
			a = memo[n - 1];
		}
		if (memo[n - 2] == 0) {
			b = dfs1(n - 2);
			memo[n - 2] = b;
		}
		else {
			b = memo[n - 2];
		}
		return a+b;
	}

	// return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	cout << dfs1(N);
}

*/