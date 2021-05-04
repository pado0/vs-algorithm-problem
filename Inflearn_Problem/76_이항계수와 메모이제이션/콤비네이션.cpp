#include <iostream>
using namespace std;

int memo[21][21];

int dfs(int n, int r) {
	// nCr �� 2���� �迭�� �����Ͽ� �̹� �ִ� ���̸� ����
	if (memo[n][r] > 0) return memo[n][r];
	if (n == r || r == 0 ) return 1;
	else {
		return memo[n][r] = dfs(n - 1, r) + dfs(n - 1, r - 1);
	}
}

int main() {
	// 5���� 3���� �̴� ����Ǽ�?
	// ���װ���� ���� 5C3 = 4C2+4C3
	// 5���� 3���� D�̴� ���� 
	// 1)�� ������ 5��° �� �̰� 4������ 2���̴°�
	// 2)�� ������ 5��° �� �Ȼ̰� 4������ 3���̴°�

	//3C2 = 2C1 + 2C2 , 2C1 = 1C1 +1C0

	int n, r;
	cin >> n >> r;

	cout << dfs(n, r);
}