/*
>> ����Ǯ��
1. �Է¹ޱ�
2. �ɹ� ��ġ ã���� �ɹ� ��ġ 0���� �ٲ��ֱ�
3. �ɹ��� ���� ��ġ �������� bfs�� ���� ���� ����� �䳢 ã��
4. ���� ����� �䳢 ã������ ��Ƹ԰�, ������ �����ϰ� ���� 0���� �����ϱ�
   - ��Ƹ��� �ڸ����� �ٽ� �����ؾ��ϴϱ�
*/


#include <iostream>
#include <queue>
using namespace std;
int map[27][27];
int flag[27][27];
int dx[4] = { 1, 0 , -1 , 0 };
int dy[4] = { 0, 1 , 0 , -1 };
int N, M = 0; // N: ���� ũ��, M: �䳢 ���� ��


struct simba {
	int x, y, size, ate, dist;
	simba() {

	}

	simba(int x1, int y1, int size1, int ate1, int dist1) {
		x = x1; y = y1; size = size1; ate = ate1; dist = dist1;
	}

	bool operator < (const simba &d) const {
		if (dist == d.dist) { // �Ÿ��� ������
			if (x == d.x) return y > d.y;  // �������� (���� ����)
			else return x > d.x;// �������� (���� ����)
		}
		else {
			return dist > d.dist; // �������� (������ ����)
		}
	}

};

simba s;

int find_rabbit() {
	int min = 214700000, sum = 0;
	priority_queue<simba> q;
	int x, y, dist, ate = 0, size;
	int tmp = 0;
	q.push(s); // �ʱ� �ɹ� push

	while (!q.empty()) {
		//���̻� ���� �� �ִ� �䳢�� ���� ��? > ������� ���Դ°���? > dist max�� �䳢 �Ծ����� �����ϸ� ��
		//if (ate + tmp == M) break;

		//������ġ
		x = q.top().x;
		y = q.top().y;
		dist = q.top().dist;
		ate = q.top().ate;
		size = q.top().size;

		q.pop();
		//cout << "�̵����" << " x: " << x << "  y " << y << endl;

		// flag�� �䳢 �Ѹ��� ��Ƹ԰��� �ʱ�ȭ�������
		if (x == 0 || y == 0 || x == N + 1 || y == N + 1 || map[x][y] > size || flag[x][y] == 1)continue;
		if (map[x][y] <= size && flag[x][y] == 0) { // ����� ���ų� ������ �� ����, ������ �ȸԾ�ߵ�
			flag[x][y] = 1; // �䳢 �Ѹ��� ��� ���������� 1�� ���൵ ��. �׷��� �ּ�.
			//dist++;

			// ����� ������ ��ƸԱ�, �䳢�� �ִ���ġ�����ؼ�0����
			if (map[x][y] < size && map[x][y] != 0) {
				ate++; map[x][y] = 0;
				if (ate == size) {
					size++; ate = 0;
					tmp = tmp + ate;
				}
				sum = dist + sum;
				//cout << "��Ƹ��� x,y x: " << x << " y: " << y << " dist: " << dist << endl;
				//cout << "sum: " << sum << endl;
				// ��ƸԾ����� flag �ʱ�ȭ? q�� �ʱ�ȭ, ���⼭ �ٽý���?
				for (int k = 1; k <= N; k++) {
					for (int l = 1; l <= N; l++) {
						flag[k][l] = 0;

					}
				}
				while (!q.empty()) {
					q.pop();
				}
				min = 214700000;
				dist = 0;

			}
		}

		for (int i = 0; i < 4; i++) {

			int tx = x + dx[i];
			int ty = y + dy[i];


			//����� �ٸ��� ����Ƹ԰� �׳� ���� ��ġ�� �̵�
			//cout << "Ǫ�ø�� " << "tx: " << tx << " ty: " << ty << " dist: " << dist << endl;
			q.push(simba(tx, ty, size, ate, dist + 1));
		}
		// �䳢���� �ּҰŸ��� ����� �������� �³�?
		// �䳢 �� ��ġ�� ������ ��� �Ÿ� ����ؾ��ϴ°� �ƴѰ�?
		// flag �ʱ�ȭ ��𿡼� ������?

	}

	return sum;
}


int main() {

	// �ּҰŸ� & ���� �� �ִ� �䳢 ã��
	// ����, ���� ���� �Ա�
	// ũ�⸸ŭ ������ �Ա�

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				// �ɹ� �ʱ� ��ġ, �ʱ�ũ��, ���� �� �ʱ�ȭ
				s.x = i; s.y = j; s.size = 2; s.ate = 0, s.dist = 0;
				map[i][j] = 0;
			}
			else if (map[i][j] != 0) M++;

		}
	}

	// ���� �� �ִ� �䳢 ã�� 1)ũ�� 2)�ּҰŸ� �䳢 ã�� 
	// �켱���� ť�� ���� �����ִ� �� ���� pop�ϱ�
	cout << find_rabbit();

}