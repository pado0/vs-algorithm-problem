/*
top dwn�� ��ͷ� �ذ��Ѵ�
dfs(7): 7m�� 1, 2m�� �ڸ��� ����� ���� �����Ѵ�
- ������ �ڸ��� ���� 1m or 2m�� �и�ó��
- 1m > dfs(6), 2m > dfs(5)
- �� dfs(7) = dfs(6) + dfs(5)


#include <iostream>
using namespace std;
int memo[200];

int dfs1(int n) {

	//�� �Ʒ� �ڵ� ���� ���� �� ������, �ӵ��� ū ����x
	if (n == 1) {  return 1; }
	else if (n == 2) { return 2; }

	else {
		// ���ϰ� �ڵ� ���� �� ����  
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