// �ٽ�Ǯ��, �� ���� �������� ����

#include <iostream>
#include <queue>

using namespace std;

int main() {

	//����� �ΰ�
	int s1_arrival_person_count[4] = { 2,3,1,1 };
	
	
	int current_stair[100];

	int s1[3]; // 2 2 2 1
	int s2[3]; // 2 2

	///1) �ð��� ��� �기��
	int clock1, clock2, clock3;
	for (int t = 0; t < 21; t++) {
	
		// �� �ð��� ������ ����� �ִٸ�, �ش�ð��뿡 �� ���� ���
		while (s1_arrival_person_count[t] > 0) {
			s1_arrival_person_count[t]--; // �Ѹ� ����������

			//�������������� ��� ó���ϴ°�?
			// �� �ð��� ��ܿ� �ִ� ��� ���� ��ek
			for (int i = t; i < t+3; i++) {
				if (current_stair[i] < 3) {
					current_stair[i]++;
				}
			}
		}
		//��ܿ� �ö� time���� ������
		int down_time = 3;

	}





}