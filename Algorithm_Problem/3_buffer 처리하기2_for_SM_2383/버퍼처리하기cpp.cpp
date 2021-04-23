// 다시풀고, 더 많은 유형으로 보기

#include <iostream>
#include <queue>

using namespace std;

int main() {

	//계단이 두개
	int s1_arrival_person_count[10] = {0, 1,2,0,0,0,0,0,0,0 };


	int current_stair[100];

	int s1[3]; // 2 2 2 1
	int s2[3]; // 2 2

	///1) 시간을 계속 흘린다
	int answer = 2147000000;
	for (int t = 0; t < 10; t++) {

		// 그 시간에 도착한 사람 수만큼 반복
		while (s1_arrival_person_count[t] > 0) {
			s1_arrival_person_count[t]--; // 한명씩 내려보낸다
			int down_time = 5;

			//도착 시간부터 down_time만큼반복
			for (int i = t; i < 10; i++) { // max까지 다돌면서 1씩더해줌
				if (current_stair[i] < 3) {
					// 넣은 자리+계단 건너는 시간 만큼까지 curren_stair을 +1찍 해주고
					// 위에1번for, 1번 while문은 그저 명수만큼만 반복하기 위함
					// 만약 3이 다찼으면 그자리엔 못들어가므로
					// 그다음자리를 i가 찾아가며 계속 증가함.
					current_stair[i]++;
					down_time--;

					if (down_time == 0) {
						//값 갱신 - 첫번째 사람이 계단 다 내려간 시간
						if (t + 1 < answer) {
							answer = i + 1;
							//i는 지금 들어간 사람이 계단에서 내려간 시간을 나타냄
							break;
						}
					}
				}
			}
		}

	}

	cout << answer + 2; //내려가는데 걸린시간 + 최초시작타임

}