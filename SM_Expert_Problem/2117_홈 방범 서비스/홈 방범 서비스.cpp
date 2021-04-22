/*

10�� 10��~ 11�� 20�� (50��cut)

1.������ �������, ���� = ����ũ�� = k*k + (k-1) * (k-1)
  - k�� �߽��� ���� ��������
  - !���� ����� ����� ����
2. ����ũ�� N , �ϳ��� �������� ������ ��� M
3. ���ظ� ���� �ִ��� �������� �����ϸ� ��
4. �� ���� ���

 >Ǯ��
 1. grid�Լ���  x, y, �׸���ũ��, �̷��� ���� �Ѱ��ָ� 
 2. �׸����Լ����� �� ���� �׸��忡 ���� �� ������ �����Ѵ�
    - �� ���� �׸���: k�� �簢�� ���� ���, ��������cnt�� ������� ����ֱ�
	  �� ����  ���� �۵� ���� ���� Ȯ���� ������ ����
	- �׸��� ®���� �� �׸��� * map !=0�ΰ��� ���� �ִ°����̹Ƿ�, �� �� ����cnt
 3. ���ϵ� �� ������ ����� ����, cost>=0����Ȯ���ϰ�, ������ max�������� ���
 4. flame �ʱ�ȭ

 ! ������: map /frame / map�� ��� ���� ���� kũ�� �� ���ϱ�

*/

#include <iostream>
using namespace std;

int map[22][22];
int frame[50][50];
int N, M;

int grid(int k, int x, int y) { // �� ���� ����
	int add = k-1; // 2
	int flag_add = 0;
	int cnt = 0; // ���� ���� �ִ� �� ����
	for (int i = x - k + 1; i <= x + k - 1; i++) {
		for (int j = y - k + 1 + add; j <= y + k - 1 -add; j++) {
			if (i > 0 && j > 0 && i <= N + 1 && j <= N + 1) {
				frame[i][j] = 1;
			}
		}

		if (add > 0 && flag_add==0) {
			add--;
		}
		else if (add == 0 && flag_add == 0) {
			flag_add = 1;
			add++;
		}
		else {
			add++;
		}
	}

	// ������� ����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] * frame[i][j] != 0) cnt++;
		}
	}
	return cnt;
}
int main() {
	// �Է¹ޱ�
	int T;
	int cost = 0;
	int max_house = 0;
	int house_count;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}



		// �׸��带 K= 1~ N�������� map�� 0,0���� ��������.
		for (int k = 1; k <= N+2; k++) { 
			// ������ tc�� 399�� �Ѱ��� ���ڶ�, k���������� �����ؼ� 2�÷������ 400��
 			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					house_count = grid(k, i, j);

					cost = house_count * M - (k*k + (k - 1)*(k - 1));

					if (cost >= 0) {
						if (house_count > max_house) {
							max_house = house_count;
						}
					}

					for (int i = 0; i < 50; i++) {
						for (int j = 0; j < 50; j++) {
							frame[i][j] = 0;
						}
					}
					//flame �ʱ�ȭ
					// x, y, �׸���ũ��, �̷��� ���� �Ѱ��ָ� �׸����Լ�����
					// �� ������ �׸��忡 ���� ����� �Ѵ�, i,j�� �߽���
					// ��� / �� ���� ����?
				}
			}
		}

		cout<<"#" << t+1 << " " << max_house << endl;

		//�ʱ�ȭ
		cost = 0;
		max_house = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j]=0;
			}
		}
	}
}