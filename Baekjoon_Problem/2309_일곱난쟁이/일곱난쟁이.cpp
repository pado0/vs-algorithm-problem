// 브루트 포스: 가능한 방법을 전부 만들어 푼다, 완전탐색!

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	// 일곱난쟁이 키 합이 100
	
	// 더해보기전엔 모른다,
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