/*
�ٸ� ��ο� ģ���̸� 1��
�ٸ� ��ο� ģ�� OR ģ���� ģ���̸� 2��
...

*/
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

int mem[51][51]; //mem[i][j] : i�� j�� �󸶳� �� ģ����������
int score[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; // ȸ����
	int x= 0, y=0;
	
	cin >> N;
	//�ʱ�ȭ
	for (int i = 1; i <= N; i++) { // 
		for (int j = 1; j <= N; j++) {
			mem[i][j] = 100;
		}
	}

	while (true) {
		cin >> x >> y;
		if (x == -1 && y == -1) break;
		mem[x][y] = 1;
		mem[y][x] = 1;
	}

	for (int k = 1; k <= N; k++) { // ���İ� ģ�� ����
		for (int i = 1; i <= N; i++) { // 
			for (int j = 1; j <= N; j++) {
				mem[i][j] = min(mem[i][j], mem[i][k] + mem[k][j]);
			}
		}
	}

	// ���� ����ϱ�, �� ���� max���� �� ����� ����
	int min = 2147000000;
	for (int i = 1; i <= N; i++) { // 
		for (int j = 1; j <= N; j++) {
			if (mem[i][j] > score[i] && mem[i][j]!=100) score[i] = mem[i][j];
		}
		if (score[i] < min) min = score[i];
	}

	// ȸ�� ���� ,��
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (score[i] == min) cnt++;
//		cout << score[i] << " ";
	}
	cout << min << " " << cnt << "\n";

	for (int i = 1; i <= N; i++) {
		if (score[i] == min) cout << i << " ";
	}


}