// �Ž������� ���� ���� �׼��� �������� ��ȯ.

#include <iostream>
#include <algorithm>
using namespace std;

int coin[13];
int dy[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> coin[i];
	cin >> M; // �Ž��� ��

	sort(coin, coin + 1 + N);


	// ���� ū �� ���� �о��ָ� �����ʳ� > �ƴ�
	/*
	5
	1 8 20 25 50
	129
	79 29 4 3 2 1 0
	��: 5�ε� 7�� ����
	*/
	

	int j, tmp;
	for (int i = 1; i <= N; i++) {
		
		// ���� ����
		j = coin[i];
		tmp = coin[i];

		//dy[i] : i�� �Ž����ִµ��� �ʿ��� ������ ����
		while (j<=M) {
			
			// ���ʷ� ���� �Ž����� �� �׳� �����ϰ�
			if(dy[j] == 0) dy[j] = dy[j - tmp] + 1;

			// �ٸ� ���� �־��� �� ���� ���� �ּҰ��� �񱳸� ���� ���� �Ž����� ���� ����Ѱͺ��� ���� ���� ���� ��� ����
			else {
				if (dy[j - tmp] + 1 < dy[j]) dy[j] = dy[j - tmp] + 1;
			}

			j++;
		}
	}

	cout << dy[M];
}