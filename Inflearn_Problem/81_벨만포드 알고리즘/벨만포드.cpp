/*
���-��� ������ �ִܰŸ��� ���ϴ� �˰���

���]
���� 1�������� > 2�� .. > ��尳��-1 �� ������. N������ ���� ����Ŭ�� ����°��̹Ƿ� �� ��������.
���� ����Ŭ�� �������� �ʴ� �ٴ� ���� ������ �Ѵ�.

1. DIST �迭�� ����� ���������� �Ÿ��� ���Ѵ�� �ʱ�ȭ���ش�.
2. Ư�� ��忡�� ������ �� ���� �Ἥ �� �� �ִ� ��� �������� ����� Ȯ���ϰ� DIST�� �����Ѵ�
3. Ư�� ��忡�� ������ �� ���� �Ἥ �� �� �ִ� ��� �������� ����� Ȯ���ϰ� DIST�� �����Ѵ�.

*/


#include <iostream>
#include <queue>
using namespace std;

int map[201][201];
int dist[100];

struct Edge {

};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int tx, ty, w;

	// �ʱ���
	for (int i = 1; i <= m; i++) {
		cin >> tx >> ty >> w;
		map[tx][ty] = w;
	}

	//�ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		dist[i] = 2147000000;
	}

	// ���, ������ ����
	int sc, dc;
	cin >> sc >> dc;

	dist[sc] = 0;

	return 0;
}