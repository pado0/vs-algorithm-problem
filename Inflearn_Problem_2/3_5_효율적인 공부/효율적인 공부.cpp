/*
M ���� �� ������ ȿ����

���� ���� ȿ������?

�ð����⵵�� ������ �������⵵�� ������
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
	

	// ������ �ð��� ���� �� �������� ����
	//dy[i]: i�ð����� �������� ���� ȿ����?



}