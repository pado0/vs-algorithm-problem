/*
��Ǯ����.
����Ǯ�� �����ؼ� �ٽú���,
�Ϸķ� flag ���ְ�, flag �����ϴ°� �� �����ϰ� �����ϱ�*/


// flag�� �ŵδ� ������ ����
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int map[14][14];// �� ũ�� 7~12
int flag[14][14];
int v_flag[12];

int arr[12];
int cnt = 0;

int dr[4] = { 1,2,3,4 }; // ���»�� 
int N; // ���μ��� ���μ��� ũ��
int sum = 0;
int node_max = 0;

int leng_min = 2147000000;
int min1 = 2147000000;
vector<pair<int, int>> v;

void dfs(int i) { // 1�� �迭 ������� �������ָ� �Ǵ°���
	
	if (cnt == v.size()-1) { // v������� ������ ���� ���Ѱ�
		return;
	}
	else {
		for (int j = 0; j < v.size(); j++) {
			if (v_flag[j] == 0) {
				v_flag[j] = 1;
				cnt++;
				arr[cnt] = j;
				dfs(j);
				v_flag[j] = 0;
				cnt--;

			}

		}
	}

}

// �����¿� �ѹ������θ� ���� > ���⼭���� �ٽ�Ǯ��, 1�ð� 40
//dfs �� ���� ù ��尡 ���϶� ��� ����Ǽ� dis������
void line(int n, int len, int direction, int done) { // ����ȣ, �Ÿ� , �����¿� 0,0,1
	int x = v[arr[n]].first;
	int y = v[arr[n]].second;

	cout << "����: " << direction << " n:"<<n <<" x: "<< x << "  y: " << y << endl;
	if (n == v.size()) { // ��������, ����� �����¿� ������
		//�ִ��� ���� ��尡 ����Ǿ��־����. >>> �̰Ŵٽû����ϱ�


		if (done > node_max) {
			node_max = done;
			leng_min = len;
			cout << "len1: " << len << " done: " << done<< endl;
			done = 0;
			return ;
			
		}
		else if (done == node_max) {
			if (len < leng_min) {
				leng_min = len;
				cout << "len2: " << len << " done: " << done << endl;
				done = 0;
				return ;
			}
		}
		return;
	
	}
	else {
		//x,y�� ���� �ھ� ��ġ
		//������ ���� / �ھ ���µ���
		int flagt1 = 0, flagt2 = 0, flagt3 = 0, flagt4 = 0;
		int tmp = 0;
		int cnt = 0;
		//cnt = 0; x = v[arr[n]].first;  y = v[arr[n]].second;
		


		if (direction == 1) {
			x--;
			while (flag[x][y] == 0 && map[x][y] == 0) {
				if (x == 1 || y == 1 || x == N || y == N) {
					flagt1 = 1;
					break;
				}
				x--;
			}if (flagt1 == 1) {
				x = v[arr[n]].first;
				x--; cnt = 0;
				while (flag[x][y] == 0 && map[x][y] == 0) {
					cnt++;
					if (x == 1 || y == 1 || x == N || y == N) {
						for (int i = x; i <= x + cnt; i++) { flag[i][y] = 1; 
						}
						len = len + cnt;
						cout << "cnt1: " << len << endl;
						flagt1 = 1;
						break;
					}
					x--;

				}
			}
	
			//cnt = 0; x = v[arr[n]].first;  y = v[arr[n]].second;
		}
		else if (direction == 2) {
			x++;
			while (flag[x][y] == 0 && map[x][y] == 0) {
				if (x == 1 || y == 1 || x == N || y == N) {
					flagt2 = 1;
					break;
				}
				x++;
			}if (flagt2 == 1) {
				x = v[arr[n]].first;
				x++; cnt = 0;
				while (flag[x][y] == 0 && map[x][y] == 0) {
					cnt++;
					if (x == 1 || y == 1 || x == N || y == N) {
						for (int i = x - cnt; i <= x; i++) flag[i][y] = 1;
						len = len + cnt;
						cout << "cnt2: " << len << endl;
						flagt2 = 1;
						break;
					}
					x++;

				}
			}

			//cnt = 0; x = v[arr[n]].first;  y = v[arr[n]].second;
		}

		else if (direction == 3) {
			y--;
			while (flag[x][y] == 0 && map[x][y] == 0) {
				if (x == 1 || y == 1 || x == N || y == N) {
					flagt3 = 1;
					break;
				}
				y--;
			}
			if (flagt3 == 1) {
				y = v[arr[n]].second;
				y--; cnt = 0;
				while (flag[x][y] == 0 && map[x][y] == 0) {
					cnt++;
					if (x == 1 || y == 1 || x == N || y == N) {
						for (int i = y; i <= y + cnt; i++) flag[x][i] = 1;
						len = len + cnt;
						cout << "cnt3: " << len << endl;
						flagt3 = 1;

						

						break;
					}
					y--;

				}
			}

			//cnt = 0; x = v[arr[n]].first;  y = v[arr[n]].second;
		}

		else if (direction == 4) {
			y++;
			while (flag[x][y] == 0 && map[x][y] == 0) {
				if (x == 1 || y == 1 || x == N || y == N) {
					flagt4 = 1;
					break;
				}
				y++;
			}if (flagt4 == 1) {
				y = v[arr[n]].second;
				y++; cnt = 0;
				while (flag[x][y] == 0 && map[x][y] == 0) {
					cnt++;
					if (x == 1 || y == 1 || x == N || y == N) {
						for (int i = y - cnt; i <= y; i++) flag[x][i] = 1;
						len = len + cnt;
						cout << "cnt4: " << len << endl;
						flagt4 = 1;
						break;
					}
					y++;

				}
			}

			
		}


		//flag��üȮ��!!!!!!!!!
		cout << "flag ��üȮ�� : " << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << flag[i][j] << " ";
			}
			cout << endl;
		}
		

		if (flagt1==1 || flagt2  == 1|| flagt3 == 1|| flagt4 == 1) { 
			done++; 
		}

		
		//������� �����ϱ�
		
		
		
		for (int i = 1; i <= 4; i++) {
			line(n + 1, len, i, done);

			if (flagt1 == 1)for (int i = x; i <= x + cnt; i++) flag[i][y] = 0;
			else if(flagt2==1)for (int i = x - cnt; i <= x; i++) flag[i][y] = 0;
			else if (flagt3 == 1)for (int i = y; i <= y + cnt; i++) flag[x][i] = 0;
			else if (flagt4 == 1)for (int i = y - cnt; i <= y; i++) flag[x][i] = 0;
		}

		//flag �ŵα⸸ ���ָ� �ϼ�����¥. �ٵ� �̷��Ա��� �ؾ���?
		// �ٽ�Ǯ���!!
		/*//��
		line(n + 1, len, 1, done);


		//��
		line(n + 1, len, 2, done);

		//��
		line(n + 1, len, 3, done);

		//��
		line(n + 1, len, 4, done);*/
	}
}

int main() {
	cin >> N;

	// 1. �Է¹ޱ�
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			// ���� �Ϸ�� �ھ�� 2�� ǥ���Ͽ�, ���߿� ���� continue
			// ���� ���� ������ �ʿ䵵 ����
			if (map[i][j] == 1 && (j == 1 || i == 1 || j == N || i == N)) {
				map[i][j] = 2;
			}
			//
			if (map[i][j] == 1) {
				v.push_back(make_pair(i, j));
			}

		}
	}

	// �ھ� ��� ����� ������ ����
	for (int i = 0; i < v.size(); i++) {

		v_flag[i] = 1;
		arr[0] = i;
		dfs(i);
		
		//v_copy �޾Ƽ� ������� ó���Ѵ����� �ʱ�ȭ ���ֱ�
		v_flag[i] = 0;

		//0 1 2 3 4 ... �ھ� ���� ���� �̾���, arr[i]�� ��� ���� �� 		

		sum = 0;
		for (int tt = 1; tt <=4; tt++) {
			cout << "start���:" << endl;
			int flaga1 = 0, flaga2 = 0, flaga3 = 0, flaga4 = 0;
			int x = v[arr[0]].first;
			int y = v[arr[0]].second;
			
			if (tt == 1) {
				for (int i = x-1; i >= 1; i--) {
					if (flag[i][y] != 0 || map[i][y] != 0) {
						flaga1 = 1;
						break;
					}
				}
				if (flaga1 == 0) {
					for (int i = x - 1; i >= 1; i--) {
						flag[i][y] = 1;
					}
				}
			}
			else if (tt == 2) {
				for (int i = x +1; i <= N; i++) {
					if (flag[i][y] != 0 || map[i][y] != 0) {
						flaga2 = 1;
						break;
					}
				}
				if (flaga2 == 0) {
					for (int i = x + 1; i <= N; i++) {
						flag[i][y] = 1;
					}
				}
			}
			else if (tt == 3) {
				for (int i = y - 1; i >= 1; i--) {
					if (flag[x][i] != 0 || map[x][i] != 0) {
						flaga3 = 1;
						break;
					}
				}
				if (flaga3 == 0) {
					for (int i = y - 1; i >= 1; i--) {
						flag[i][y] = 1;
					}
				}
			}
			else if (tt == 4) {
				for (int i = y + 1; i <= N; i++) {
					if (flag[x][i] != 0 || map[x][i] != 0) {
						flaga4 = 1;
						break;
					}
				}
				if (flaga4 == 0) {
					for (int i = y + 1; i <= N; i++) {
						flag[i][y] = 1;
					}
				}
			}
			
			line(0, 0, tt, 0);  // �ѹ� ���� ù��� 1�϶� �ٵ���
			////cout << leng_min << endl;

			//ó�����¾ִ� ��͵������� flag, �ȱ׷��� �ι�° �� �� flag�� ������
		

			//flag �ʱ�ȭ
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					flag[i][j] = 0;
				}
			}

		
		}

	}

	cout << leng_min;
}
