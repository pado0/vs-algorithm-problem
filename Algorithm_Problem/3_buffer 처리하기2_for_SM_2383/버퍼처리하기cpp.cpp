// �ٽ�Ǯ��, �� ���� �������� ����

#include <iostream>
#include <queue>

using namespace std;

int main() {

	//����� �ΰ�
	int s1_arrival_person_count[10] = {0, 1,2,0,0,0,0,0,0,0 };


	int current_stair[100];

	int s1[3]; // 2 2 2 1
	int s2[3]; // 2 2

	///1) �ð��� ��� �기��
	int answer = 2147000000;
	for (int t = 0; t < 10; t++) {

		// �� �ð��� ������ ��� ����ŭ �ݺ�
		while (s1_arrival_person_count[t] > 0) {
			s1_arrival_person_count[t]--; // �Ѹ� ����������
			int down_time = 5;

			//���� �ð����� down_time��ŭ�ݺ�
			for (int i = t; i < 10; i++) { // max���� �ٵ��鼭 1��������
				if (current_stair[i] < 3) {
					// ���� �ڸ�+��� �ǳʴ� �ð� ��ŭ���� curren_stair�� +1�� ���ְ�
					// ����1��for, 1�� while���� ���� �����ŭ�� �ݺ��ϱ� ����
					// ���� 3�� ��á���� ���ڸ��� �����Ƿ�
					// �״����ڸ��� i�� ã�ư��� ��� ������.
					current_stair[i]++;
					down_time--;

					if (down_time == 0) {
						//�� ���� - ù��° ����� ��� �� ������ �ð�
						if (t + 1 < answer) {
							answer = i + 1;
							//i�� ���� �� ����� ��ܿ��� ������ �ð��� ��Ÿ��
							break;
						}
					}
				}
			}
		}

	}

	cout << answer + 2; //�������µ� �ɸ��ð� + ���ʽ���Ÿ��

}