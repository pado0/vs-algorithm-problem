// 다시풀고, 더 많은 유형으로 보기

#include <iostream>
#include <queue>

using namespace std;

int main() {

	//계단이 두개
	int s1_arrival_person_count[4] = { 2,3,1,1 };
	
	
	int current_stair[100];

	int s1[3]; // 2 2 2 1
	int s2[3]; // 2 2

	///1) 시간을 계속 흘린다
	int clock1, clock2, clock3;
	for (int t = 0; t < 21; t++) {
	
		// 그 시간에 도착한 사람이 있다면, 해당시간대에 명 수를 기록
		while (s1_arrival_person_count[t] > 0) {
			s1_arrival_person_count[t]--; // 한명씩 내려보낸다

			//내려보낼지말지 어떻게 처리하는가?
			// 그 시간에 계단에 있는 사람 수를 센ek
			for (int i = t; i < t+3; i++) {
				if (current_stair[i] < 3) {
					current_stair[i]++;
				}
			}
		}
		//계단에 올라간 time부터 세야함
		int down_time = 3;

	}





}