/*
N�� ������
i �� �������� �����ڼ� A��

1)�Ѱ�����: �����帶�� 1��, ������ B�� ���� ����
2) �ΰ�����: ������ C�� ���ð���.

solution > �� �ʿ��� ������ �� �ּҰ�
caution > if master test supervisor can watch more than ������, answer is 1.

*/

#include <iostream>
long long total = 0;
long long sol = 0; // �ΰ��� ��
using namespace std;

int p[1000000];
int main() {
	int N; //������ ����
	int A, B, C;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}

	cin >> B >> C;
	
	for (int i = 0; i < N; i++) {
		if (p[i] - B > 0) {
			if ((p[i] - B) % C > 0) {
				sol = (p[i] - B) / C + 1;

			}
			else if ((p[i] - B) % C == 0) {
				sol = (p[i] - B) / C;
			}
			total = total + sol;
		}
	}

	/*for (int i = 0; i < N; i++) {
		if ((p[i] - B) % C > 0 && p[i] - B > 0) {
			sol = (p[i] - B) / C + 1;

		}
		else if ((p[i] - B) % C == 0 && p[i] - B > 0) {
			sol = (p[i] - B) / C;
		}
		total = total + sol; // ���۾��� p[i]-B>0�϶� �������.
		������ ���ָ� sol�� 0�� �ƴ� �ٸ����� �������Ƿ�.
	}*/
	//cout << " n: " << N  << " t: "<< total <<endl;
	cout << total + N; // total: �ΰ�������,N:�ְ�������}


}