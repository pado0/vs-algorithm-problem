/*
��ǥ: ���� ��������



�̵��Ϸ�ð�: ��������� ����� ������ �Ʒ������� �̵��� �ð�
1. �̵��ð�: ��� �Ա������� �Ÿ�
2. ��� �������� �ð�:
   - ���ð� 1��
   - ���� 3������� ��ܿ� �ö󰡱� ����, �ƴ϶�� ������
     ������ ������ ����ؾ���
- ��� �������� �ð� = ��ܱ��� K (ĭ���� �ٸ�)

? �Ա����� ���� ? >��� ���ִ� ĭ���� �ö󰡱�
�Ա������ο��� ������ ����
��� �Ա��� 2��

�̵��Ϸ� �ּҽð� ���.

>Ǯ��
: ������� ���ĵ� �Ǵ°� ŷ�޳� �� ��� �̵���Ű��?
!!! ���� ����� ��ܿ� ���°� �ɻ簡 �ƴ� �� �� ����

1)��� ����: �� ����� ���1 / ��� 2 �����ϴ� ��� ��� �湮 (dfs)
2) ��ܱ����� �̵�
   p�� struct�� ����� ������ġ, ��ܱ��� �ɸ��ð� ��� ex.queue.push(p(x,y, n+1))
   �� p�� id �ο� �ʿ�(index�� �ϱ�)
    >> bfs �� �ʿ� ���� �׳� �Ÿ� ������ֱ�
3) ��ܿ� ������ p �ð� ������� ��� �������� ó�����ֱ�
   - ���ϴ��� ��� �����ð� + ��� �������� �ð�
   ? ��� ����
*/
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int N;
int map[12][12];
int cnt = 0; // ��� �� count

struct person {
	int x, y, time, stair;
	person() {

	 }
	person(int xi, int yi, int timei, int stairi) {
		x = xi; y = yi; time = timei; stair = stairi;
	}

	bool operator < (const person &d) const {
		return time < d.time;
	}
};

struct person p[10];
vector<pair<int, int>> stair;
priority_queue<int> pq;
vector < pair<int, int >> vv;

void dfs(int n, int s) {

	if (s == 0) {
		p[n].stair = 0;
	}
	else {
		p[n].stair = 1;
	}

	int sx, sy;
	if (n == cnt - 1) {
		//���� ������������ �����ؾ���
		cout << "� ��尡 ��� ��������" << endl;
		for (int i = 0; i < cnt; i++) {

			//��� ��尡 �� �� ° �� ����� ������ p[i]�� �������
			int x = p[i].x;
			int y = p[i].y;
			sx = stair[p[i].stair].first;
			sy = stair[p[i].stair].second;


			// ��ܱ��� �󸶳� �ɸ����� �ð��� �������
			p[i].time = abs(x - sx) + abs(y - sy);
			cout << p[i].x << " " << p[i].y << " " << p[i].stair << " " << p[i].time << endl;

			pq.push(-p[i].time);
		}

		int count = -pq.top() +1;
		vv.push_back(make_pair(-pq.top(), count));
		pq.pop();
		
		// ��� �����ð����� �˾Ƴ´µ�, ť�� �ְ� 3���� ��� n�ʰ� �������°�
		// ��� ó���ؾ�����? �𸣰ڴ�.
		// ���ϱ��� ����غ��� �� Ȯ���ϱ�
		//count+1 ���� �ִ´�
		/*while (!pq.empty()) {
			

		}*/
	}


	else {
		dfs(n + 1, 0);
		dfs(n + 1, 1);
	}

}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) { 
				p[cnt].x = i;
				p[cnt].y = j;
				p[cnt].time = 0;
				cnt++;
			}
			else if (map[i][j] != 0) {
				stair.push_back(make_pair(i, j));
			}
		}
	}

	//ù��° ��� �������� dfs �����ϱ�
	//dfs 1�����
	dfs(0, 0); //0����� 1�����
	//dfs 2�����
	dfs(0, 1);

}