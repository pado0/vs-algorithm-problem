#include <iostream>

using namespace std;

struct jew {
	int weight, value;
};

struct jew jew[30] ;
int dy[31];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L; // N: ���� ��������, L: ���� �Ѱ� ����
	cin >> N >> L;

	// L kg�� ���� �����鼭 �ִ밡ġ�� �Ǿ���Ѵ�.
	// ���� ��ġ�� ū�� �� ���� ������� ���� �ִ´�. > �ƴϴ�.
	// �� kg�� ����� �� ��ġ�� �����Ѵ�.
	// �� 1���� ����� �� ��ġ
	// �״��� 2�� ����� �� ��ġ
	// > �� ������ �������� ������ �ּ��� �ּ��� �ƴ� �� �ִٴ� ��

	int tw, tv;
	for (int i = 0; i < N; i++) {
		cin >> tw >> tv;
		jew[i].value = tw;
		jew[i].value = tv;
	}

	return 0;
}