// ���Ʈ ����: ������ ����� ���� ����� Ǭ��, ����Ž��!

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	// �ϰ������� Ű ���� 100
	
	// ���غ������� �𸥴�,
	int tall[9];
	int sum = 0;
	for (int k = 0; k < 9; k++) {
		cin >> tall[k];
	}

	sort(tall , tall + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++){
			for (int k = 0; k < 9; k++) {
				if (k != i && k != j) {
					sum = sum + tall[k];
				}

			}

			if (sum == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						cout << tall[k] <<"\n";
					}
				}
				return 0;

			}
			sum = 0;
		}
	}

}