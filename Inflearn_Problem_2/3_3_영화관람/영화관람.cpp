// 11:33~

// 1�ʿ� ��� �����̾�����.. > 3-5��
// 100000 000 000 > worst case 1õ���̵�...
// ����ȭ ����


#include <bits/stdc++.h>
using namespace std;

int student[100001];
int hide[100001]; // i��° �л��� �þ߸� ������ �л���ȣ

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> student[i];
	}
	
	
	
	for (int i = 1; i <= N; i++) { // �����л�
		
		for (int j = i - 1; j > 0; j--) { // ���л�
			if (student[i] < student[j]) {
				hide[i] = j;
				break;
			}
			else if (student[i] == student[j]) {
				hide[i] = hide[j];
				break;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << hide[i] << " ";
	}

	/*
	// ���� ��û���� �л� ��ȣ ���
	for (int i = N; i > 0; i--) { // �����л�
		for (int j = i - 1; j > 0; j--) { // ���л�
			if (student[i] < student[j]) {
				hide[i] = j;
				break;
			}

		}
	}

	for (int i = 1; i <= N; i++) {
		cout <<  hide[i] << " ";
	}
	*/

}