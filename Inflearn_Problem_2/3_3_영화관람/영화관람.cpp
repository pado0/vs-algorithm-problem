// 11:33~

// 1초에 몇번 연산이었더라.. > 3-5억
// 100000 000 000 > worst case 1천억이됨...
// 최적화 실패
// 백준에서 '탑' 문제 풀어보기

#include <bits/stdc++.h>
using namespace std;

int student[100001];
int hide[100001]; // i번째 학생의 시야를 가리는 학생번호
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> student[i];
	}


	// timeout 안나는 방법. 이걸 어떻게 짜지..?
	// 스택에 있는 학생 중 내(i)가 시청방해학생인지 확인
	// 내가 방해학생이면, 방해한 학생에 내 번호를 기록하고, 그 학생은 방해자 찾은거니까 팝
	// 내가 먼저들어간애보다 작으면 그냥 계속 들어가면 됨. (자연스럽게 오름차순 정렬됨)
	// 스택엔 방해학생 못찾은 애들만 남음
	for (int i = N; i > 0; i--) {

		while (!s.empty() && student[i] > student[s.top()]) {
			hide[s.top()] = i;
			s.pop();
		}

		s.push(i);
	}

	for (int i = 1; i <= N; i++) {
		cout << hide[i] << " ";
	}


	// time out. 
	/* 앞부터 보기
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
	*/

	/* 뒤부터 보기, 앞부터 보는 것 보다 빠름
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