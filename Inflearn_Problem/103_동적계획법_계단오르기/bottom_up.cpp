//��� �� �Ȱ��� ������..!

#include <iostream>

using namespace std;
int memo[200];
int main() {

	// 1���: 1
	// 2���: 1+1, 2
	// 3���: 2���+1, 1���+2
	// f(n) = f(n-1)+ f(n-2)

	int n;
	cin >> n;

	memo[1] = 1;
	memo[2] = 2;

	for (int i = 3; i <= n; i++) {
		memo[i] = memo[i - 1] + memo[i - 2];
	}

	cout << memo[n];
}