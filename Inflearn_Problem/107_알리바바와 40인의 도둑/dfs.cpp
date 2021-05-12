
/*
���� ���̳��� ���α׷��� ������
- ���� top dowm�� bottom up �ع��� �������� �ʹ��� �ʴ´�.
- ������ �ɰ��°� �� ���ϰڴ�.
- �˸��ٹٰ��� ������ ���������� �ݺ��Ǵ� ��Ģ�� ã�ƾ��ϴµ�,
  ���Ʈ����ó�� �� Ȯ�����ִ� �ڵ常 ¥����....
  dfs�� �ϰ� �޸������̼Ǹ� �ϴ°� dp�� �ƴ��ݾ�..
*/

/*
#include <iostream>
#include <queue>

using namespace std;
int N;
int map[22][22];
queue<pair<int, int>> q;
int min_e = 2147000000;

void dfs(int x, int y, int h) {

	if (h > min_e)return;
	if (x > N || y > N) return;
	if (x == N && y == N) {
		if (h < min_e) min_e = h;
	}
	else {

		dfs(x + 1, y, h + map[x+1][y]);
		dfs(x, y + 1, h + map[x][y+1]);
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ���̰� �ٸ� ���ٸ� N x N
	// �ִܰŸ� �̵�
	// �ּ� ������(����)

	// ������, �Ʒ��θ� ���� ������ �ּ�.
	// ������, �Ʒ� �� ���� ĭ���� �̵�
	// �� ������ �� �ۿ� ���� �ʳ�?

	cin >> N;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(1, 1, map[1][1]);
	cout << min_e;
}

*/