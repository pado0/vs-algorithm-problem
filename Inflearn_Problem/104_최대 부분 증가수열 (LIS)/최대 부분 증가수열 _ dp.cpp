
#include <iostream>
using namespace std;
int arr[1001];
int dy[1001]; // �ش� �ε��� ���� ���������� ������ ���϶� ���� �� ����
int max = 0;
int n;

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		// dp�� Ǯ���ֱ�: index i�� ������������ �ϴ� �������� count �ϱ�


		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			dy[i] = 0;
		}

		dy[1] = 1;
		
		// i=1�϶� 1�� �ʱ�ȭ���ְ�, 2���� ��ִ��� �����ֱ�
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {

				// �ڱ⺸�� ���� ���ξָ� ���������� �ϴ� ������ ���� + 1(�ڱ��ڽ� ����1) �� ���� ū���� ä���ϸ� ��.
				
				if (arr[i] > arr[j]) {

					// ���� ���̺��� ū ���̰� ������ �����Ѵ�.
					if (dy[j] + 1 > dy[i]) {
						dy[i] = dy[j] + 1;
					}
				}
			}

			if (dy[i] == 0) dy[i] = 1;
		}
		
		for (int i = 1; i <= n; i++) {

			if (dy[i] > max) max = dy[i];
		}

		cout << max;
		return 0;

	}


