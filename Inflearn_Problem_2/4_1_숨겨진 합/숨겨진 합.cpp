#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int partial = 0;
	int sum = 0;

	for (int i = 0; i < s.size(); i++) {
		int x = (int)s[i];
		
		// ������ �� ��� ����
		if (x >= 48 && x <= 57) {
			
			// �κ����� 0 �϶� (0���� �����ϴ°� �ɷ��ִ� ��)
			if (partial == 0) {
				partial = x - 48;
			}
			// ���� ���ڸ� �߰����� ��
			else {
				partial = partial * 10 + x - 48;
			}

		}
		//������ �� �հ� �ʱ�ȭ
		else {
		//	cout << partial << endl;
			sum = sum + partial;
			partial = 0;
		}
	}
	
	// �ʱ�ȭ ���� ������ �հ� �ٽô����ֱ�
	sum = sum + partial;
	cout << sum;
}