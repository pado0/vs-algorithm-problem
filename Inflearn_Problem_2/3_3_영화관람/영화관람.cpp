// 11:33~

// 1초에 몇번 연산이었더라.. > 3-5억
// 100000 000 000 > worst case 1천억이됨...
// 최적화 실패


#include <bits/stdc++.h>
using namespace std;

int student[100001];
int hide[100001]; // i번째 학생의 시야를 가리는 학생번호

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> student[i];
	}
	
	
	
	for (int i = 1; i <= N; i++) { // 기준학생
		
		for (int j = i - 1; j > 0; j--) { // 비교학생
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
	// 최초 시청방해 학생 번호 출력
	for (int i = N; i > 0; i--) { // 기준학생
		for (int j = i - 1; j > 0; j--) { // 비교학생
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