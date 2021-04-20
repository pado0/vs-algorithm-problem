
#include <iostream>
#include <queue>

using namespace std;

struct Loc {
	int x, y;

	Loc(int xin, int yin) {
		x = xin; y = yin;
	}

	bool operator < (const Loc &d)const {
		return x < d.x;
		/*a < b�� ��, b�� ũ�ٸ� b�� ���� �÷��ְ�, a�� ũ�ٸ� a�� ���� �÷���.
		��, �� ������ ū�� ���� �÷��ִ� �ڵ�, ����������. ex. 10 9 8 7...
		a.operator<(b)�� ��ȯ���� 1(��)�̸� b�� �÷��ְ�, a.operator<(b)�� ��ȯ���� 0(����)�̸� a�� �÷��ش�*/
	}

};


int main() {
	int N;
	priority_queue<Loc> pq;

	pq.push(Loc(1, 2));
	pq.push(Loc(4, 3));
	pq.push(Loc(2, 6));
	pq.push(Loc(3, 1));
	pq.push(Loc(5, 7));

	while (!pq.empty()) {
		cout << pq.top().x << " " << pq.top().y << endl;
		pq.pop();
	}

}