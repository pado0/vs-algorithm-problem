#include <iostream>
#include <queue>
using namespace std;
int main() {
	//���� �����÷ο찡 ���� �Է��� ��� ������
	// N: ����ũ�� 0: 1�� ó��,


	//�̰� ���� ���� ��� ���� �Ѱ� �� Ǯ���

	queue<int> q;
	int N,x;
	cin >> N;

	while (1) {

		cin >> x;

		if (x == -1)break;
		if (x == 0 && !q.empty()) {
			q.pop();
		}
		else {
			if (q.size() < N) {
				q.push(x);

			}
		}
	}
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}