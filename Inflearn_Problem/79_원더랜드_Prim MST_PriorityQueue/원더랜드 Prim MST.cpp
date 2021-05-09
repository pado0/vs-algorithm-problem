#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int flag[100];
int map[100][100];

struct Edge {
	int v;
	int w;

	Edge(int v1, int wi) {
		v = v1; w = wi;
	}
	bool operator < (const Edge &d) const {
		return w > d.w;

	}
};

// �̰� ����ġ �켱���� ���� ���ֱ�
priority_queue<Edge> pq;


int main() {
	int x, y, w;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	// prim �˰����̶�? �湮�� ���� ����� ��� ���� �� ���� ����ġ�� �������� �����Ѵ�.
	// �̹� ������ ���� pass�Ѵ�.

	// �켱���� ť�� ���ڴ�.
	// 1. ��� ������ �켱���� ť���� �ִ´�. (������ȣ, ��������ġ�� ������ �ִ´�)
	// 2. �湮�� ������ flagó��, ���� ��ȣ���� �� �� �ִ� ���, ����ġ�� ��� ť�� �ִ´�.
	// 3. POP �� edge�� ����� ��带 �����Ѵ�.
	
	// �ǹ�? �켱���� ť�� ����ġ ������ ���������µ�.. ������ ��尡 �� ������� ����?
	// - �̷��� �Ǿ�����, �̹� ���õ� ���� ���� ������ �ϸ� �ȵȴ�. �׳� pop��Ű�� ��.
	// - �������� �ʰ� pop�ؼ� ����������
	

	/*
	�ʿ��Ѱ�?
	- map�� ������ �迭 ���� > � ��尡 ������ ����ġ ������ 
	
	����Ǿ��ִ��� Ȯ���ϱ� ���� map
	*/


	int v, e;

	cin >> v >> e;
	// �ʱ���
	for (int i = 1; i <= e; i++) {
		cin >> x >> y >> w;
		map[x][y] = w;
		map[y][x] = w;
	}
	
	pq.push(Edge(1, 0));

	int sum = 0;

	while (!pq.empty()) {
		int vin = pq.top().v;
		int w = pq.top().w;
		// cout << "v: " << vin <<" w: " << w << "\n";
		pq.pop();
		// �Ȱ��� ����̸� ����, ���� ����̸� ��ŵ
		
		if (flag[vin] == 0) {

			flag[vin] = 1;
			sum = sum + w;


			for (int i = 1; i <= v; i++) {
				if (map[vin][i] != 0 && flag[i] == 0){ // �̹� �湮�� ���� ����
					// cout << "chk";
					pq.push(Edge(i, map[vin][i])); // ����� ���� ����ġ�� push
				}
			}
		}

	}

	cout << sum;


}