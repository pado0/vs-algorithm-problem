// 일단 풀긴 풀었는데, 코드 최적화하는 연습이 전혀 안돼있다.

#include <iostream>
using namespace std;
int D, W, K;
int map[13][20];
int origin[13][20];
int flag[13];
int min_cnt = 2147000000;

int check() {
	int chk = 0, score = 0, total_score = 0;
	for (int i = 0; i < W; i++) { // y값
		//K칸씩 체크
		for (int j = 0; j <= D - K; j++) { // x 시작점값
			for (int k = j; k < j + K; k++) { //돌아가는값
				if (map[k][i] == 0) {
					chk++;
				}
			}

			if (chk == K || chk == 0) {
				score = 1;
				chk = 0;
				break; // !! 이미 충족 확인했으므로 바로 다음열로 빠짐
			}
			chk = 0;

		}
		if (score == 0) break;  // !! 열이 통과 못한것이므로 더이상 안봐도됨.
		if (score == 1)total_score++;
		score = 0;

	}

	if (total_score == W) {
		return 1;  // 통과
	}
	else return 0; // 불통
}

void dfs(int d, int t) { // 몇번째층인지, 그 층은 뭘로 주입할건지가 들어옴

	flag[d] = t;
	// 아예 D-1로 오기 전에 리턴해줄수있음
	// !! 애초에 D에서 K개만 선택해야함.
	/*int cnt_go =0 ;
	for (int i = 0; i <= d; i++) {
		if (flag[i] == 0 || flag[i]==1) cnt_go++;
	}
	if (cnt_go > K) {// !! K개 이상 주입된경우
		//cout << "ret" << endl;
		return;
	}*/
	if (d == D-1) {
		/*for (int i = 0; i <= W; i++) {
			cout << flag[i] << " " ; 
		}
		cout << endl;
		*/
		//필름주입
		int cnt = 0;
		int br = 0;
		//int go = 0;
		// 한 세트에 대해 필름 주입 완료

		//아래코드는 위에서 처리해줬으므로 삭제
		/*for (int i = 0; i < D; i++) {
			if (flag[i] != 2) go++;
		}
		if (go > K)return; // !! 총 투약 횟수는 K를 넘지 않는다*/
		//else {
			for (int i = 0; i < D; i++) {
				if (flag[i] == 0) {
					cnt++;
					if (cnt >= min_cnt) { br = 1;  break; }
					for (int j = 0; j < W; j++) {
						map[i][j] = 0;
					}
					
				}
				else if (flag[i] == 1) {
					cnt++;
					if (cnt >= min_cnt) { br = 1;  break; }
					for (int j = 0; j < W; j++) {
						map[i][j] = 1;
					}
					
				}

				// 최소보다 크게 cnt가 들어오는 경우엔 중단해줘도 된다
				
			}
			if (br == 0) {
				if (check() == 1) {
					if (cnt < min_cnt) min_cnt = cnt;
				}
			}
			br = 0;
			//맵을 원래대로 되돌려야함.
			for (int i = 0; i < D; i++) {
				// !! 원래대로 돌릴때 a,b바꾼값만!
				if (flag[i] == 1 || flag[i] == 0) {
					for (int j = 0; j < W; j++) {
						map[i][j] = origin[i][j];
					}
				}
			}
		//}
	}
	else {
		int cnt_go = 0;
		for (int i = 0; i <= d; i++) {
			if (flag[i] == 0 || flag[i] == 1) cnt_go++;
		}
		if (cnt_go == K) {// !! K개 이상 주입된경우 아예 dfs 들어가지 않음으로 해결
			//cout << "ret" << endl;
			return;
		}

		dfs(d + 1, 2); // 안넣거나
		dfs(d + 1, 1); // b를 넣거나
		dfs(d + 1, 0); // a를 넣거나
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	/*풀이법
	1. 입력받기
	2. 품질검사 함수 만들기
	3. 약품투입 함수 만들기
		>  DFS로 N개 막을 선택하거나 안하거나 2^6
		> DFS 돌다가 통과하면 멈추기 가능?*/
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> D >> W >> K;

		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				origin[i][j] = map[i][j];
			}
		}

		if ( K==1 || check() == 1) {
			min_cnt = 0;
		}
		else {
			//dfs로 보호필름 골라주기
			dfs(0, 2);
			dfs(0, 1);
			dfs(0, 0);
		}
		cout << "#" << t + 1 << " " << min_cnt << endl;
		
		min_cnt = 2147000000;
		//flag 초기화
		for (int i = 0; i < W; i++) {
			flag[i] = 0;
		}

	}

}
