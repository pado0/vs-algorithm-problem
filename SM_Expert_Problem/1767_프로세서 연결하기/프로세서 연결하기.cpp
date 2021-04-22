/*
못풀었음.
문제풀이 정리해서 다시보기,
일렬로 flag 놔주고, flag 해제하는걸 더 간략하게 정리하기*/


// flag를 거두는 과정이 없음
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int map[14][14];// 맵 크기 7~12
int flag[14][14];
int v_flag[12];

int arr[12];
int cnt = 0;

int dr[4] = { 1,2,3,4 }; // 하좌상우 
int N; // 프로세서 가로세로 크기
int sum = 0;
int node_max = 0;

int leng_min = 2147000000;
int min1 = 2147000000;
vector<pair<int, int>> v;

void dfs(int i) { // 1개 배열 순서대로 정렬해주면 되는것임
	
	if (cnt == v.size()-1) { // v사이즈와 같으면 정렬 다한것
		return;
	}
	else {
		for (int j = 0; j < v.size(); j++) {
			if (v_flag[j] == 0) {
				v_flag[j] = 1;
				cnt++;
				arr[cnt] = j;
				dfs(j);
				v_flag[j] = 0;
				cnt--;

			}

		}
	}

}

// 상하좌우 한방향으로만 간다 > 여기서부터 다시풀기, 1시간 40
//dfs 한 턴이 첫 노드가 상일때 모든 경우의수 dis여야함
void line(int n, int len, int direction, int done) { // 노드번호, 거리 , 상하좌우 0,0,1
	int x = v[arr[n]].first;
	int y = v[arr[n]].second;

	cout << "방향: " << direction << " n:"<<n <<" x: "<< x << "  y: " << y << endl;
	if (n == v.size()) { // 종료조건, 모든노드 상하좌우 돌았음
		//최대한 많은 노드가 연결되어있어야함. >>> 이거다시생각하기


		if (done > node_max) {
			node_max = done;
			leng_min = len;
			cout << "len1: " << len << " done: " << done<< endl;
			done = 0;
			return ;
			
		}
		else if (done == node_max) {
			if (len < leng_min) {
				leng_min = len;
				cout << "len2: " << len << " done: " << done << endl;
				done = 0;
				return ;
			}
		}
		return;
	
	}
	else {
		//x,y는 현재 코어 위치
		//전선이 없고 / 코어가 없는동안
		int flagt1 = 0, flagt2 = 0, flagt3 = 0, flagt4 = 0;
		int tmp = 0;
		int cnt = 0;
		//cnt = 0; x = v[arr[n]].first;  y = v[arr[n]].second;
		


		if (direction == 1) {
			x--;
			while (flag[x][y] == 0 && map[x][y] == 0) {
				if (x == 1 || y == 1 || x == N || y == N) {
					flagt1 = 1;
					break;
				}
				x--;
			}if (flagt1 == 1) {
				x = v[arr[n]].first;
				x--; cnt = 0;
				while (flag[x][y] == 0 && map[x][y] == 0) {
					cnt++;
					if (x == 1 || y == 1 || x == N || y == N) {
						for (int i = x; i <= x + cnt; i++) { flag[i][y] = 1; 
						}
						len = len + cnt;
						cout << "cnt1: " << len << endl;
						flagt1 = 1;
						break;
					}
					x--;

				}
			}
	
			//cnt = 0; x = v[arr[n]].first;  y = v[arr[n]].second;
		}
		else if (direction == 2) {
			x++;
			while (flag[x][y] == 0 && map[x][y] == 0) {
				if (x == 1 || y == 1 || x == N || y == N) {
					flagt2 = 1;
					break;
				}
				x++;
			}if (flagt2 == 1) {
				x = v[arr[n]].first;
				x++; cnt = 0;
				while (flag[x][y] == 0 && map[x][y] == 0) {
					cnt++;
					if (x == 1 || y == 1 || x == N || y == N) {
						for (int i = x - cnt; i <= x; i++) flag[i][y] = 1;
						len = len + cnt;
						cout << "cnt2: " << len << endl;
						flagt2 = 1;
						break;
					}
					x++;

				}
			}

			//cnt = 0; x = v[arr[n]].first;  y = v[arr[n]].second;
		}

		else if (direction == 3) {
			y--;
			while (flag[x][y] == 0 && map[x][y] == 0) {
				if (x == 1 || y == 1 || x == N || y == N) {
					flagt3 = 1;
					break;
				}
				y--;
			}
			if (flagt3 == 1) {
				y = v[arr[n]].second;
				y--; cnt = 0;
				while (flag[x][y] == 0 && map[x][y] == 0) {
					cnt++;
					if (x == 1 || y == 1 || x == N || y == N) {
						for (int i = y; i <= y + cnt; i++) flag[x][i] = 1;
						len = len + cnt;
						cout << "cnt3: " << len << endl;
						flagt3 = 1;

						

						break;
					}
					y--;

				}
			}

			//cnt = 0; x = v[arr[n]].first;  y = v[arr[n]].second;
		}

		else if (direction == 4) {
			y++;
			while (flag[x][y] == 0 && map[x][y] == 0) {
				if (x == 1 || y == 1 || x == N || y == N) {
					flagt4 = 1;
					break;
				}
				y++;
			}if (flagt4 == 1) {
				y = v[arr[n]].second;
				y++; cnt = 0;
				while (flag[x][y] == 0 && map[x][y] == 0) {
					cnt++;
					if (x == 1 || y == 1 || x == N || y == N) {
						for (int i = y - cnt; i <= y; i++) flag[x][i] = 1;
						len = len + cnt;
						cout << "cnt4: " << len << endl;
						flagt4 = 1;
						break;
					}
					y++;

				}
			}

			
		}


		//flag전체확인!!!!!!!!!
		cout << "flag 전체확인 : " << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << flag[i][j] << " ";
			}
			cout << endl;
		}
		

		if (flagt1==1 || flagt2  == 1|| flagt3 == 1|| flagt4 == 1) { 
			done++; 
		}

		
		//다음노드 선택하기
		
		
		
		for (int i = 1; i <= 4; i++) {
			line(n + 1, len, i, done);

			if (flagt1 == 1)for (int i = x; i <= x + cnt; i++) flag[i][y] = 0;
			else if(flagt2==1)for (int i = x - cnt; i <= x; i++) flag[i][y] = 0;
			else if (flagt3 == 1)for (int i = y; i <= y + cnt; i++) flag[x][i] = 0;
			else if (flagt4 == 1)for (int i = y - cnt; i <= y; i++) flag[x][i] = 0;
		}

		//flag 거두기만 해주면 완성임진짜. 근데 이렇게까지 해야해?
		// 다시풀어봐!!
		/*//상
		line(n + 1, len, 1, done);


		//하
		line(n + 1, len, 2, done);

		//좌
		line(n + 1, len, 3, done);

		//우
		line(n + 1, len, 4, done);*/
	}
}

int main() {
	cin >> N;

	// 1. 입력받기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			// 연결 완료된 코어는 2로 표시하여, 나중에 고를때 continue
			// 연결 순서 생각할 필요도 없다
			if (map[i][j] == 1 && (j == 1 || i == 1 || j == N || i == N)) {
				map[i][j] = 2;
			}
			//
			if (map[i][j] == 1) {
				v.push_back(make_pair(i, j));
			}

		}
	}

	// 코어 모든 경우의 순서로 선택
	for (int i = 0; i < v.size(); i++) {

		v_flag[i] = 1;
		arr[0] = i;
		dfs(i);
		
		//v_copy 받아서 순서대로 처리한다음에 초기화 해주기
		v_flag[i] = 0;

		//0 1 2 3 4 ... 코어 선택 순서 뽑았음, arr[i]에 든거 쓰면 됨 		

		sum = 0;
		for (int tt = 1; tt <=4; tt++) {
			cout << "start재귀:" << endl;
			int flaga1 = 0, flaga2 = 0, flaga3 = 0, flaga4 = 0;
			int x = v[arr[0]].first;
			int y = v[arr[0]].second;
			
			if (tt == 1) {
				for (int i = x-1; i >= 1; i--) {
					if (flag[i][y] != 0 || map[i][y] != 0) {
						flaga1 = 1;
						break;
					}
				}
				if (flaga1 == 0) {
					for (int i = x - 1; i >= 1; i--) {
						flag[i][y] = 1;
					}
				}
			}
			else if (tt == 2) {
				for (int i = x +1; i <= N; i++) {
					if (flag[i][y] != 0 || map[i][y] != 0) {
						flaga2 = 1;
						break;
					}
				}
				if (flaga2 == 0) {
					for (int i = x + 1; i <= N; i++) {
						flag[i][y] = 1;
					}
				}
			}
			else if (tt == 3) {
				for (int i = y - 1; i >= 1; i--) {
					if (flag[x][i] != 0 || map[x][i] != 0) {
						flaga3 = 1;
						break;
					}
				}
				if (flaga3 == 0) {
					for (int i = y - 1; i >= 1; i--) {
						flag[i][y] = 1;
					}
				}
			}
			else if (tt == 4) {
				for (int i = y + 1; i <= N; i++) {
					if (flag[x][i] != 0 || map[x][i] != 0) {
						flaga4 = 1;
						break;
					}
				}
				if (flaga4 == 0) {
					for (int i = y + 1; i <= N; i++) {
						flag[i][y] = 1;
					}
				}
			}
			
			line(0, 0, tt, 0);  // 한번 돌면 첫노드 1일때 다돈거
			////cout << leng_min << endl;

			//처음도는애는 재귀들어가기전에 flag, 안그러면 두번째 돌 때 flag가 해제됨
		

			//flag 초기화
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					flag[i][j] = 0;
				}
			}

		
		}

	}

	cout << leng_min;
}
