#include <iostream>
using namespace std;

int rightArr[101];
int dy[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ���� ��ġ�� �ʰ� �ڱ� ���� ã�ư���. �ִ밪��?
	// ��, �ִ� �κ� ���������� �׳� ���� �ǳ�...
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> rightArr[i];
	}

	// rightArr[i]�� ������ �κ��ִ����������϶�
	// ���Ұ��� �����ֱ�

	dy[1] = 1;

	// i = ���� ��
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (rightArr[i]>rightArr[j]) {

				if(dy[j]+1 > dy[i])
				dy[i] = dy[j] + 1;
			}
		}

		if (dy[i] == 0) dy[i] = 1;
		
	}

	int max = 0;

	for (int i = 1; i <= N; i++) {
		if (dy[i] > max) max = dy[i];
	}
	cout << max;
}