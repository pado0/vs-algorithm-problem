/*
11:00 ~

*/

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//������������ ���� ���� ���ԵǴ� ������ ���������� ���� ���ϱ�
	// ���̳ʹ� ũ�� ��į..?
	// �������� ���̵忡 ������ �ϸ� �ȴٴ� ���̵��� �Ȱ���
	// ��, �ٵ� ���������� �ϳ��� x��ǥ�� ��������, �ٸ� ���������� y��ǥ�� �������� ���� ���� ���� �ʳ�!
	// > �����ϴ� �׸��� ��ǥ�� ������ ������������ x, �ٸ� ������ y�� ���ڴ� �� > �׷������Ʊ� ����ߴ� ���̽� �ذ�

	int W, H, T, S;

	
	cin >> W >> H >> T >> S;

	int x, y;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	int max_count = 0;
	//���� tree�� x��ǥ, ������ Ʈ�� y��ǥ ����
	for (int i = 0; i < T; i++) { // 100
		for (int j = 0; j < T; j++) { // 100

			int count = 0;
			//�����ȿ��� ������ �ȴٴ� �������� for�� �� ���� ���� �� ����.

			// k: �������� ���� �ٸ� ������
			for (int k = 0; k < T; k++) {
				if (v[i].first <= v[k].first &&  v[k].first <= v[i].first + S) {
					if (v[j].second <= v[k].second && v[k].second <= v[j].second + S) {
						// �� ������ �� ������ ������ ���� ������ count ++ ���ش�
						count++;
					}
				}
			}

			max_count = max(max_count, count);

			/* �Ʒ� ����� time out
			for (int k = v[i].first; k <= v[i].first + S; k++) {	// 100000
				for (int l = v[j].second; l <= v[j].second + S; l++) {

					//Ʈ���� �ִ��� ����
					for (int t = 0; t < T; t++) { // 100
						if (k == v[t].first && l == v[t].second) count++;
					}
					
					//Ʈ���� max�� ���ϱ�
					if (count > max) max = count;

				}
			}*/

		}
	}

	cout << max_count;

}