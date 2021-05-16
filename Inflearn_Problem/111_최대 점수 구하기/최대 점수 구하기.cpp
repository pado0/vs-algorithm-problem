// �迭 �ȸ��� ��
// �񱳽� min, max �Լ� ���

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


int dy[1001]; // dy[i] : i�ð��� Ǭ �ִ� ����

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// M�ð� �ȿ� N���� ���� �� �ִ������� ���� �� �ֵ���.
	int N, M, ts, tt;

	cin >> N >> M;

	// Ǯ���� ���� ������, �ɸ��� �ð��� ���ʴ�� �־���
	// �ڿ����� ���ؾ��ϴ� ����? > �տ��� ���� �ϸ� �ߺ���.
	// !! ���������� ������ Ǯ�� �ȵż� �ߺ� �Ұ�!!!
	// ��, �׷��� �ڿ����� ä��� �Ǵ±���.. �տ� ����ƴ� ���� ������!

	for (int i = 1; i <= N; i++) {
		cin >> ts >> tt;

		for (int j = M; j >= tt; j--) {
			dy[j] = max(dy[j], dy[j - tt] + ts);

		}
	}

	cout << dy[M];

}