#include <iostream>
using namespace std;
int unf[100];

int find(int v) {
	if (unf[v] == v) return v;
	else return find(unf[v]);
}

void uni(int a, int b){
	int ta = find(a);
	int tb = find(b);

	if (ta != tb) unf[a] = unf[b];
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;	//�л���, ���ڽ�
	cin >> n >> m;

	/*
	//���� �׷��̸� ���� ID�� ����?

	// find : �Ѿ�� �Ű����� ���� ���չ�ȣ�� ������
			- ��ͷ� ã��. > �� ��ͷ� ã����..
			ex. 1,2 / 2,3 / 3,4�� ���ö�
			[1][2][3][4][5]
		 	 1  2  3  4  5
			>1��
			[1][2][3][4][5]
			 2  2  3  4  5
			>2��
			[1][2][3][4][5]
			 2  3  3  4  5

			 = find�� 1�� ������ 2����, 2�� �ٽó־� 3����, 3�� 3�� �����ϴϱ�.
			 �ᱹ 1,2,3�� �ٰ��� 3���� �Ͱ�Ǿ� ���� �������� �ǹ�
			 ��Ʈ����� ��ȣ�� ���չ�ȣ���������� ����

	// unf[] : ���չ�ȣ�� �����ϴ� �迭
	// Union : �������չ�ȣ�� �ٸ��� ���� �������

	*/

	// ���չ�ȣ �迭 �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		unf[i] = i;
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		uni(a, b);
	}

}