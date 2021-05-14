#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int map[21][21];
int dy[21][21];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	// dy[x][y] : x,y�� ��������� ��α���
	// �� ������ ��� ���̸� ��� ���ϱ�!! �ּҰ��� ������ ��α��� �� �ּҿ��� �������� >  �̰� Ű IDEA

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			
			if(i==1 && j == 1)dy[1][1] = map[1][1];
			else if (i == 1) {
				dy[i][j] = map[i][j] + dy[1][j-1];
			}
			else if (j == 1) {
				dy[i][j] = map[i][j] + dy[i-1][1];
			}
			else {
				dy[i][j] = map[i][j] + min(dy[i - 1][j], dy[i][j - 1]);
			}
		}
	}
	
	
	cout << dy[N][N];

}