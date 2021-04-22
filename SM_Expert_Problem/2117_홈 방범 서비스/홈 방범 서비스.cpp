/*

10시 10분~ 11시 20분 (50분cut)

1.면적은 마름모꼴, 운영비용 = 면적크기 = k*k + (k-1) * (k-1)
  - k는 중심점 부터 범위길이
  - !면적 벗어나도 비용은 같음
2. 도시크기 N , 하나의 집이지불 가능한 비용 M
3. 손해만 없이 최대한 많은집에 제공하면 됨
4. 집 개수 출력

 >풀이
 1. grid함수에  x, y, 그리드크기, 이렇게 세개 넘겨주면 
 2. 그리드함수에서 한 단위 그리드에 대한 집 개수를 리턴한다
    - 한 단위 그리드: k로 사각형 범위 잡고, 별도변수cnt로 마름모꼴 깍아주기
	  위 로직  정상 작동 여부 먼저 확인후 다음꺼 구현
	- 그리드 짰으면 그 그리드 * map !=0인것이 집이 있는공간이므로, 이 집 개수cnt
 3. 리턴된 집 개수로 비용을 구해, cost>=0인지확인하고, 맞으면 max집개수를 기록
 4. flame 초기화

 ! 주의점: map /frame / map을 모두 덮기 위한 k크기 잘 정하기

*/

#include <iostream>
using namespace std;

int map[22][22];
int frame[50][50];
int N, M;

int grid(int k, int x, int y) { // 집 개수 리턴
	int add = k-1; // 2
	int flag_add = 0;
	int cnt = 0; // 격자 내에 있는 집 개수
	for (int i = x - k + 1; i <= x + k - 1; i++) {
		for (int j = y - k + 1 + add; j <= y + k - 1 -add; j++) {
			if (i > 0 && j > 0 && i <= N + 1 && j <= N + 1) {
				frame[i][j] = 1;
			}
		}

		if (add > 0 && flag_add==0) {
			add--;
		}
		else if (add == 0 && flag_add == 0) {
			flag_add = 1;
			add++;
		}
		else {
			add++;
		}
	}

	// 컨볼루션 진행
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] * frame[i][j] != 0) cnt++;
		}
	}
	return cnt;
}
int main() {
	// 입력받기
	int T;
	int cost = 0;
	int max_house = 0;
	int house_count;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}



		// 그리드를 K= 1~ N까지만들어서 map의 0,0부터 돌려본다.
		for (int k = 1; k <= N+2; k++) { 
			// 마지막 tc가 399로 한개가 모자라, k범위문제라 생각해서 2늘려줬더니 400됨
 			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					house_count = grid(k, i, j);

					cost = house_count * M - (k*k + (k - 1)*(k - 1));

					if (cost >= 0) {
						if (house_count > max_house) {
							max_house = house_count;
						}
					}

					for (int i = 0; i < 50; i++) {
						for (int j = 0; j < 50; j++) {
							frame[i][j] = 0;
						}
					}
					//flame 초기화
					// x, y, 그리드크기, 이렇게 세개 넘겨주면 그리드함수에서
					// 한 단위의 그리드에 대한 계산을 한다, i,j는 중심점
					// 비용 / 집 개수 리턴?
				}
			}
		}

		cout<<"#" << t+1 << " " << max_house << endl;

		//초기화
		cost = 0;
		max_house = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				map[i][j]=0;
			}
		}
	}
}