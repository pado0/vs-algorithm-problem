/*
11:00 ~

*/

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//오랜지나무가 가장 많이 포함되는 지역의 오렌지나무 개수 구하기
	// 값이너무 크면 어캄..?
	// 오렌지가 사이드에 가도록 하면 된다는 아이디어는 똑같음
	// 아, 근데 오렌지나무 하나의 x좌표를 기준으로, 다른 오렌지들의 y좌표를 기준으로 포문 돌면 되지 않냐!
	// > 좌측하단 네모의 좌표를 선택한 오렌지나무의 x, 다른 나무의 y로 하자는 것 > 그럼내가아까 고민했던 케이스 해결

	int W, H, T, S;

	
	cin >> W >> H >> T >> S;

	int x, y;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	int max_count = 0;
	//선택 tree의 x좌표, 나머지 트리 y좌표 고르기
	for (int i = 0; i < T; i++) { // 100
		for (int j = 0; j < T; j++) { // 100

			int count = 0;
			//범위안에만 들어오면 된다는 생각으로 for문 세 번만 돌릴 수 있음.

			// k: 선택하지 않은 다른 나무들
			for (int k = 0; k < T; k++) {
				if (v[i].first <= v[k].first &&  v[k].first <= v[i].first + S) {
					if (v[j].second <= v[k].second && v[k].second <= v[j].second + S) {
						// 그 나무들 중 범위에 들어오는 놈이 있으면 count ++ 해준다
						count++;
					}
				}
			}

			max_count = max(max_count, count);

			/* 아래 방법도 time out
			for (int k = v[i].first; k <= v[i].first + S; k++) {	// 100000
				for (int l = v[j].second; l <= v[j].second + S; l++) {

					//트리가 있는지 보기
					for (int t = 0; t < T; t++) { // 100
						if (k == v[t].first && l == v[t].second) count++;
					}
					
					//트리의 max값 구하기
					if (count > max) max = count;

				}
			}*/

		}
	}

	cout << max_count;

}