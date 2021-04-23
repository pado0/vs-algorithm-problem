/*
!!���ѽð� �ʰ�

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

vector<pair<int, int>> stair;
priority_queue<int> pq;
int arr1[300];
int arr2[300];
int answer = 2147000000;
int buffer[300];
int min_time1 = 0;
int min_time2 = 0;
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
		////cout << "� ��尡 ��� ��������" << endl;
		for (int i = 0; i < cnt; i++) {

			//��� ��尡 �� �� ° �� ����� ������ p[i]�� �������
			int x = p[i].x;
			int y = p[i].y;
			sx = stair[p[i].stair].first;
			sy = stair[p[i].stair].second;


			// ��ܱ��� �󸶳� �ɸ����� �ð��� �������
			p[i].time = abs(x - sx) + abs(y - sy);
			////cout << p[i].x << " " << p[i].y << " " << p[i].stair << " " << p[i].time << endl;
			int pt = p[i].time;
			////cout << "pt!!  " <<pt << endl;
			// pushback�� �ƴ϶� time�� �ش��ϴ� index��++�������
			if (p[i].stair == 0) {
				arr1[pt]++;

		
			}
			else if (p[i].stair == 1) {
				arr2[pt]++;
			}

	
		}

		//v0���� ó��
		for (int t = 1; t < 20; t++) {
			while (arr1[t] > 0) {
				arr1[t]--;

				int down_time = map[stair[0].first][stair[0].second];
				
				for (int tt = t; tt < 300; tt++) {
					if (buffer[tt] < 3) {
						buffer[tt]++;
						down_time--;

						if (down_time == 0) {
							if (tt+1 > min_time1) {
								min_time1 = tt +1;
								break;
							}
						}
					}
				}

			}
			
		}
		
		for (int t = 0; t < 300; t++) {
			buffer[t] = 0;
		}

		//v0���� ó��
		for (int t = 1; t < 20; t++) {
			while (arr2[t] > 0) {
				arr2[t]--;

				int down_time = map[stair[1].first][stair[1].second];

				for (int tt = t; tt < 300; tt++) {
					if (buffer[tt] < 3) {
						buffer[tt]++;
						down_time--;

						if (down_time == 0) {
							if (tt + 1 > min_time2) {
								min_time2 = tt + 1;
								break;
							}
						}
					}
				}

			}

		}

		int tmp;
		if (min_time1 > min_time2) {
			tmp = min_time1;
		}
		else {
			tmp = min_time2;
		}

		if (tmp < answer) answer = tmp;

		//�ʱ�ȭ ���ֱ�
		for (int t = 0; t < 300; t++) {
			buffer[t] = 0; arr1[t] = 0; arr2[t] = 0;
		}
		min_time2 = 0; min_time1 = 0;
	}


	else {
		dfs(n + 1, 0);
		dfs(n + 1, 1);
	}

}

int main() {
	int T;
	
	cin >> T;
	for (int iterator = 0; iterator < T; iterator++) {
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
		cout << "#" << iterator+1 << " "<< answer + 1 <<endl;
	
		answer = 2147000000;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j] = 0;
			}
		}
	}
}