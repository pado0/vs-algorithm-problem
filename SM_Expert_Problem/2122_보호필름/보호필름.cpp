// �ϴ� Ǯ�� Ǯ���µ�, �ڵ� ����ȭ�ϴ� ������ ���� �ȵ��ִ�.

#include <iostream>
using namespace std;
int D, W, K;
int map[13][20];
int origin[13][20];
int flag[13];
int min_cnt = 2147000000;

int check() {
	int chk = 0, score = 0, total_score = 0;
	for (int i = 0; i < W; i++) { // y��
		//Kĭ�� üũ
		for (int j = 0; j <= D - K; j++) { // x ��������
			for (int k = j; k < j + K; k++) { //���ư��°�
				if (map[k][i] == 0) {
					chk++;
				}
			}

			if (chk == K || chk == 0) {
				score = 1;
				chk = 0;
				break; // !! �̹� ���� Ȯ�������Ƿ� �ٷ� �������� ����
			}
			chk = 0;

		}
		if (score == 0) break;  // !! ���� ��� ���Ѱ��̹Ƿ� ���̻� �Ⱥ�����.
		if (score == 1)total_score++;
		score = 0;

	}

	if (total_score == W) {
		return 1;  // ���
	}
	else return 0; // ����
}

void dfs(int d, int t) { // ���°������, �� ���� ���� �����Ұ����� ����

	flag[d] = t;
	// �ƿ� D-1�� ���� ���� �������ټ�����
	// !! ���ʿ� D���� K���� �����ؾ���.
	/*int cnt_go =0 ;
	for (int i = 0; i <= d; i++) {
		if (flag[i] == 0 || flag[i]==1) cnt_go++;
	}
	if (cnt_go > K) {// !! K�� �̻� ���ԵȰ��
		//cout << "ret" << endl;
		return;
	}*/
	if (d == D-1) {
		/*for (int i = 0; i <= W; i++) {
			cout << flag[i] << " " ; 
		}
		cout << endl;
		*/
		//�ʸ�����
		int cnt = 0;
		int br = 0;
		//int go = 0;
		// �� ��Ʈ�� ���� �ʸ� ���� �Ϸ�

		//�Ʒ��ڵ�� ������ ó���������Ƿ� ����
		/*for (int i = 0; i < D; i++) {
			if (flag[i] != 2) go++;
		}
		if (go > K)return; // !! �� ���� Ƚ���� K�� ���� �ʴ´�*/
		//else {
			for (int i = 0; i < D; i++) {
				if (flag[i] == 0) {
					cnt++;
					if (cnt >= min_cnt) { br = 1;  break; }
					for (int j = 0; j < W; j++) {
						map[i][j] = 0;
					}
					
				}
				else if (flag[i] == 1) {
					cnt++;
					if (cnt >= min_cnt) { br = 1;  break; }
					for (int j = 0; j < W; j++) {
						map[i][j] = 1;
					}
					
				}

				// �ּҺ��� ũ�� cnt�� ������ ��쿣 �ߴ����൵ �ȴ�
				
			}
			if (br == 0) {
				if (check() == 1) {
					if (cnt < min_cnt) min_cnt = cnt;
				}
			}
			br = 0;
			//���� ������� �ǵ�������.
			for (int i = 0; i < D; i++) {
				// !! ������� ������ a,b�ٲ۰���!
				if (flag[i] == 1 || flag[i] == 0) {
					for (int j = 0; j < W; j++) {
						map[i][j] = origin[i][j];
					}
				}
			}
		//}
	}
	else {
		int cnt_go = 0;
		for (int i = 0; i <= d; i++) {
			if (flag[i] == 0 || flag[i] == 1) cnt_go++;
		}
		if (cnt_go == K) {// !! K�� �̻� ���ԵȰ�� �ƿ� dfs ���� �������� �ذ�
			//cout << "ret" << endl;
			return;
		}

		dfs(d + 1, 2); // �ȳְų�
		dfs(d + 1, 1); // b�� �ְų�
		dfs(d + 1, 0); // a�� �ְų�
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	/*Ǯ�̹�
	1. �Է¹ޱ�
	2. ǰ���˻� �Լ� �����
	3. ��ǰ���� �Լ� �����
		>  DFS�� N�� ���� �����ϰų� ���ϰų� 2^6
		> DFS ���ٰ� ����ϸ� ���߱� ����?*/
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> D >> W >> K;

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				origin[i][j] = map[i][j];
			}
		}

		if ( K==1 || check() == 1) {
			min_cnt = 0;
		}
		else {
			//dfs�� ��ȣ�ʸ� ����ֱ�
			dfs(0, 2);
			dfs(0, 1);
			dfs(0, 0);
		}
		cout << "#" << t + 1 << " " << min_cnt << endl;
		
		min_cnt = 2147000000;
		//flag �ʱ�ȭ
		for (int i = 0; i < W; i++) {
			flag[i] = 0;
		}

	}

}
