/*
���ͽ�Ʈ��: Ư���� �ϳ��� ��忡�� �ٸ� ��� �������� �Ÿ� �ּҺ�� ���, MST�ʹ� �ٸ�����. 
�ִܰŸ��� ������ ������ ������ �������� ����.
- ���̳��� ���α׷����̴� : �ִܰŸ��� ������ �ִܰŸ��� ���̱� ����. ������ ���ߴ� �ִܰŸ��� �״�� ���
- ������� �˰��ִ� �ִܰ�θ� ��� ���� > max�� �����س��� ��� ����, ��� �ּҸ� �����ϴ� ������� �����ߴµ�
- �̰� Ʋ���Ͱ���. ��� ����, �ٷΰ��� ��κ��� �۴ٴ°� �����ؾ���. �Ʒ��� �׳� ������ dist �߰��Ѱ� ��.

- �ѹ� ������ ���� �ٸ��Ϳ� ���� �ּҷ� ���ŵ� �� ������?
- �ƴ� ����, ���� ���¿����� �ּҰ��̹Ƿ�.
- ÷���ϸ�, �ٽ� �� ���� ������ �ٸ� ��带 ������ ���ľ��Ѵٴ� ���ε�
- �� ��ġ�� ������ �ּҰ��� �ƴҰ��̹Ƿ�.
*/

#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int map[21][21];
int flag[21];
int dist[21];

struct Edge {
	int v, w;

	Edge(int v1, int w1) {
		v = v1; w = w1;
	}

	bool operator < (const Edge &d) const {
		return w > d.w; // �������� ����
	}
};

priority_queue<Edge> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int x, y, w;

	cin >> n >> m;


	// �� �������ֱ�
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		map[x][y] = w;
	}

	for (int i = 2; i <= n; i++)dist[i] = 2147000000;

	pq.push(Edge(1, 0));

	int vt, wt;
	while (!pq.empty()) {
		
		// ����ġ�� ���� ���� ��� ����
		vt = pq.top().v;
		wt = pq.top().w;

		//top���� ���ذ� ��� ����
		pq.pop();
		
		// �湮���� ���� ����� ��� �Ÿ�����, �̹� �湮���� ��쿣 pass
		if (flag[vt] == 0) {
			flag[vt] = 1;


			// �湮 ������ ��带 ���� ť�� �־���´�
			// ��� ���Ե� ��� vt�� ���� ������ ���� ���� �ִܰŸ��� ���⼭ �����ؾ���.

			for (int i = 1; i <= n; i++) {
				if (map[vt][i] != 0 && flag[i] == 0) {
					// ����� ��带 ť�� �ٳ־��ش�
					pq.push(Edge(i, map[vt][i]));
					
					// ����� ���� ����ġ �� Ȯ�������� ������ ����
					if (dist[vt] + map[vt][i] < dist[i]) {
						dist[i] = dist[vt] + map[vt][i];
						
					}
				}
			}
		}

	}

	for (int i = 2; i <= n; i++) {
		cout << i << " : ";
		if(dist[i]!=2147000000) cout << dist[i] << "\n";
		else cout << "impossible" << "\n";
	}
	return 0;
}