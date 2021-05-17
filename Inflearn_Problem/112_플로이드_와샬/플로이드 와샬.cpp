/*
- ��� �������� ��� �������� ���� �ּҺ���� ���ϴµ� ����ϴ� �˰���
- ���̳��� ���α׷������� Ǭ��
- i->j�� ���� �ּҺ���� i->k->j�� ���� ���� �ּҺ��� ���Ѵ�.
- ��� ������ ���İ��� ��츦 �� ���� ���� 3�� for���� �ʿ��ϴ�
- k=1, 1�� ���İ���, k=2,2�� ���İ����� �ܰ躰 �����ϴٺ��� 5->4������ 5->2,1��ħ ->4�� ���°� �ڿ������� ���ŵ�
- ����� �ʴ�!

*/

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

long long dis[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, x, y, w;
	cin >> N >> M;

	// �ʱ�ȭ Max, 0
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = 2147000000;
		}
	}

	// �Է¹ޱ�
	for (int i = 1; i <= M; i++) {
		cin >> x >> y >> w;
		dis[x][y] = w;
	}


	// �˰���
	for (int k = 1; k <= N; k++) { // ���İ��� ���
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	// ���
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(dis[i][j]==2147000000) cout << "M ";
			else cout << dis[i][j] << " ";
		}
		cout << "\n";
	}
}