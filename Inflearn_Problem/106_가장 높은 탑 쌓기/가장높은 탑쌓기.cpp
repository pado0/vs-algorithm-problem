/*

밑면이 넓은 블록 위에 좁은 블록을 올려야한다.
무거운돌 위에 가벼운 돌을 넣어야한다.


1. 밑면넓이 / 벽돌높이 / 무게
-> 넓이순으로 정렬하고 
-> 무게에 대한 최대증가함수를 만든다
-> 만드는 과정에서 최대 높이를 기록한다.
가중치(높이)가 달라서 많이 쌓을수록 좋은것도 아님


1  5 2
9  9 3 /
25 3 4 / 16 2 5 / 4  4 6

*/
#include <algorithm>
#include <iostream>
using namespace std;
int dy[101];

struct block {
	int area, height, weight;

	bool operator < (const block &d) const {
		return area < d.area;
	}

};

struct block b[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, h, w;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a >> h >> w;
		b[i].area = a;
		b[i].height = h;
		b[i].weight = w;
	}

	sort(b, b + n +1);
	dy[1] = b[1].height;

	for (int i = 2; i <= n; i++) {
		for(int j=1; j<i ;j++){
		//현재까지 가장 높이가 높은 탑에 쌓으면 된다
		
			if (b[j].weight < b[i].weight) {
				if (dy[j]+b[i].height > dy[i]) {
					dy[i] = dy[j] + b[i].height;
				}

			}
		}

		if (dy[i] == 0)dy[i] = b[i].height;
	}
	
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (dy[i] > max) max = dy[i];
	}

	cout << max;
}