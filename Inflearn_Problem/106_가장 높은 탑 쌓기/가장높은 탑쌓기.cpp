/*

�ظ��� ���� ��� ���� ���� ����� �÷����Ѵ�.
���ſ ���� ������ ���� �־���Ѵ�.


1. �ظ���� / �������� / ����
-> ���̼����� �����ϰ� 
-> ���Կ� ���� �ִ������Լ��� �����
-> ����� �������� �ִ� ���̸� ����Ѵ�.
����ġ(����)�� �޶� ���� �������� �����͵� �ƴ�


1  5 2
9  9 3 /
25 3 4 / 16 2 5 / 4  4 6

*/
#include <algorithm>
#include <iostream>
using namespace std;
int dy[101];

struct block {
	int area, height, weight;

	bool operator < (const block &d) const {
		return area < d.area;
	}

};

struct block b[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, h, w;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a >> h >> w;
		b[i].area = a;
		b[i].height = h;
		b[i].weight = w;
	}

	sort(b, b + n +1);
	dy[1] = b[1].height;

	for (int i = 2; i <= n; i++) {
		for(int j=1; j<i ;j++){
		//������� ���� ���̰� ���� ž�� ������ �ȴ�
		
			if (b[j].weight < b[i].weight) {
				if (dy[j]+b[i].height > dy[i]) {
					dy[i] = dy[j] + b[i].height;
				}

			}
		}

		if (dy[i] == 0)dy[i] = b[i].height;
	}
	
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (dy[i] > max) max = dy[i];
	}

	cout << max;
}