/*
��������
- ���� �켱������ ���ϴ� �˰���
1. ���� ������ ���� ��� ��� �����ؼ� ť�� ����
2. �ƹ��ų� ���ϰ�, ���� ����� ������ ����
3. �ٽ� ���� ������ ���� ��� ť�� ����
*/

// �ڵ� ����ȭ�� ����
//�߰��۾� degree[]�迭�� ����, �� ��忡 ���� ���� ���� ������ ����Ͽ�
// degree[i] = 0�ΰ� ��ó ť�� ó��. 1�� ť�� �ְ� ���ߴٸ� 1�� ����� ��� ���������� ������
// 1->4 ���ַ��� degree[4]-1 ���ֱ�. �ش� ���� 0�� �Ǹ� �ٽ� push ���ֱ�

#include <iostream>
#include <queue>

using namespace std;
int map[100][100];
int chk[100];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, x, y;

	cin >> N >> M;

	//�Է�, �� ����
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		map[x][y] = 1;
	}
	

	// input���³��? ���� ��� 0�� ��
	for (int t = 1; t <= N; t++) {
		for (int i = 1; i <= N; i++) { // ������
			int flag = 0;
			for (int j = 1; j <= N; j++) {
			
				// ����Ȱ� �ƹ��͵� ���� ������� Ȯ��
				if (map[j][i] != 0) flag = 1;
			}

			// �ƹ��͵� ������ push
			if (flag == 0 && chk[i] == 0) {
				q.push(i);
				chk[i] = 1;
			}
		}

		// �������� out
		int start = q.front();
		cout << start << " ";

		// pop��Ű�� ���� �����ֱ�
		q.pop();
		for (int i = 1; i <= N; i++) map[start][i] = 0;

	}

}