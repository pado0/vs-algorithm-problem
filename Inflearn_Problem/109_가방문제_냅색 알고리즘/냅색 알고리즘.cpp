#include <iostream>

using namespace std;

struct jew {
	int weight, value;
};

struct jew jew[30] ;
int dy[1001]; // dy[j]:���濡 j��� ���Ը� ������� ������ ��ġ

int N, L; // N: ���� ��������, L: ���� �Ѱ� ����
int max = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	// L kg�� ���� �����鼭 �ִ밡ġ�� �Ǿ���Ѵ�.
	// > �� ������ �������� ������ �ּ��� �ּ��� �ƴ� �� �ִٴ� ��
	// �ϳ��� ������ �����ϰ�, dy[j]�� �� �������� ���� �� �ִ� ��� ���Ը� ä���

	// ���濡 7g�� ������ ��Ҵٰ� ������ �ű⿡ 5g¥�� ������ ���Ե� ��츦 �����Ѵ�.
	// > dy[2](2g�־��� �� ��ġ) + 5g ���� ��ġ = dy[7]

	int tw, tv;
	for (int i = 0; i < N; i++) {
		cin >> tw >> tv;
		jew[i].weight= tw;
		jew[i].value = tv;
	}
	
	int j = 0; int tmp = 0;
	for (int i = 0; i < N; i++) { // ���� ����
		
		tmp = jew[i].weight; // ������ ������ ���� ���� ���
		j = jew[i].weight; // interation ����
 
		while (j <= L) { // j: ������ ���԰� �Ѱ�ġ���� ��������. j�� jew[i].weight�� ����� ���������ϴ°� �ƴѰ� �����ߴµ� �ƴ�. ����츦 �� ���� ���� ������� Ž��.
			if (dy[j - tmp] + jew[i].value > dy[j]) { // ���� �������� �ٸ� or ���ο� ������ ��� ����� ��ġ�� Ŭ��
				dy[j] = dy[j - tmp] + jew[i].value; // ������ ������ ��ġ�� ��� �����ش�.
				                                    // ���Ⱑ �߿��ѵ�,  tmp(i, ������ ����) ���Ը� ���� ������ ���ϱ�����,
				                                    // j - tmp ���Կ� ����� ��ġ�� ���� ������ ��ġ�� ���Ѵ�. (j-tmp ���Ը�ŭ ���濡 ����Ǿ��ִµ�, ���⿡ tmp ���Ը� �־��� �� ��ġ�� �ñ��� ���̹Ƿ�)

			}
			j++;
		}
	}

	for (int i = 1; i <= L; i++) {
		if (dy[i] > max) max = dy[i];
	}

	cout << max;
	return 0;
}