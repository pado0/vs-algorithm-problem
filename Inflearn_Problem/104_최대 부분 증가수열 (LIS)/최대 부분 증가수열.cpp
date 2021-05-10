/*

// �Ʒ� Ǯ�� (���)�� Ǫ�� �ð��� �ʹ� �����ɸ���. . �̷��� �����ɸ� ��?
����ġ�� ���� ���� �ִµ� dp�ε� Ǯ��

#include <iostream>
using namespace std;
int arr[100];
int max = 0;
int n;

// max���� ���� len������ ������ ��� �����ֱ�
void dfs(int index, int len) {
	if (index >= n  ) {
		if (len > max) max = len;
		return;
	}

	else {

		if (arr[index] < arr[index + 1]) {

			//������ ä��
			dfs(index + 1, len + 1);
			
			//������ ä�� x
			dfs(index + 1, len);
		}
		else {
			// ū�� ä��x
			dfs(index + 1, len);
		}

	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ������ �״�� ������ ä ���ҵ��� ���, �κ� ������ ���� ū ���� ���̸� ����Ѵ�.
	// ��ͷ� �����ؾ��� �� ������, �ش� ���Ҹ� �������� ����. ���� ���������� ���� �����ָ� �������� ����
	// �Ŀ� �ٿ��� �� �ִ� �� ����ġ�� > �ð��� �ʹ� �����ɸ�. ����.


	// dp�� Ǯ���ֱ�: index i�� ������������ �ϴ� �������� count �ϱ�


	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	//ó������ ä��, ��ä��
	dfs(0, 1);
	dfs(0, 0);

	cout << max;
	
	return 0;
}

*/