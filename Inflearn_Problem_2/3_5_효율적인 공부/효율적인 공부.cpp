/*
M ���� �� ������ ȿ����
���� ���� ȿ������?
���̳��� ���α׷��� > ��, ��ƴ�. dy[i] ���ϱ� ������ �ʿ��غ���.

*/

#include <iostream>
#include <algorithm>
using namespace std;

int dy[1000001];
struct study_time {
	int s, e, ef;

	bool operator < (const study_time &d) const {
		return e < d.e;
	}
};

struct study_time study[1001];

int main() {
	int N, M, R;
	int st, et, eff;

	// N ���� ��νð��� �־����� �� 5�� ������ ���� ���� ȿ����,
	// R��ŭ�� �޽Ľð��� �ʼ���
	cin >> N >> M >> R; 

	for (int i = 1; i <= M; i++) {
		cin >> st >> et >> eff;
		study[i].s = st;
		study[i].e = et;
		study[i].ef = eff;
	}

	sort(study + 1, study + M + 1);
	

	//dy[i]: i��° �ε����� �ִ� ������ �������� ���������� �������� �� �ִ� ȿ��

	for (int i = 1; i <= M; i++) {
		dy[i] = study[i].ef; // i��°�� �������̴ϱ� �� ���� ȿ���� ������ ��
		for (int j = i - 1; j > 0; j--) {
			// �����½ð��� ���۽ð����� �۰�, i������ �ִ�ȿ������ ũ��
			if (study[j].e + R <= study[i].s && dy[j] + study[i].ef > dy[i]) {
				dy[i] = dy[j] + study[i].ef;

			}
		}
	
	}

	int max_e = 0;
	for (int i = 1; i <= M; i++) {

		max_e = max(max_e, dy[i]);
	}

	cout << max_e;
}