/*
top dwn�� ��ͷ� �ذ��Ѵ�
dfs(7): 7m�� 1, 2m�� �ڸ��� ����� ���� �����Ѵ�
- ������ �ڸ��� ���� 1m or 2m�� �и�ó��
- 1m > dfs(6), 2m > dfs(5)
- �� dfs(7) = dfs(6) + dfs(5)

*/

#include <iostream>
using namespace std;
int memo[200];

int dfs1(int n) {
	
	//�� �ڵ尡 ����ġ�� �ڵ�.
	// �̹� �ִ� ���� �н��ϰ� �Ѿ �� ����
	if (memo[n] > 0) return memo[n];

	// n�� ������ �� �־��ֱ�
	if (n == 1 || n ==2 ) { return n; }
	else {
		// �޸������̼� ����
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