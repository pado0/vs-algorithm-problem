/*
�ڿ��� N�� �ԷµǸ�
1���� N������ �� �� M�� ��� ���� ����ϴ� ���α׷�
*/

#include <iostream>
using namespace std;

int main() {

	int N , M;
	int sum = 0;
	cin >> N >> M;

	for (int i = 2; i <= N; i++) {
		if(i%M ==0){
			sum = sum +i;
		}
	}

	cout << sum;
}