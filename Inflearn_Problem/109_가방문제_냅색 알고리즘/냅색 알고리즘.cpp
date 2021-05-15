#include <iostream>

using namespace std;

struct jew {
	int weight, value;
};

struct jew jew[30] ;
int dy[1001]; // dy[j]:가방에 j라는 무게를 담았을때 보석의 가치

int N, L; // N: 보석 종류개수, L: 가방 한계 무게
int max = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	// L kg를 넘지 않으면서 최대가치가 되어야한다.
	// > 이 문제의 문제점은 현재의 최선이 최선이 아닐 수 있다는 것
	// 하나의 보석을 선택하고, dy[j]에 그 보석으로 담을 수 있는 모든 무게를 채운다

	// 가방에 7g의 보석을 담았다고 했을때 거기에 5g짜리 보석이 포함된 경우를 생각한다.
	// > dy[2](2g넣었을 때 가치) + 5g 보석 가치 = dy[7]

	int tw, tv;
	for (int i = 0; i < N; i++) {
		cin >> tw >> tv;
		jew[i].weight= tw;
		jew[i].value = tv;
	}
	
	int j = 0; int tmp = 0;
	for (int i = 0; i < N; i++) { // 보석 선택
		
		tmp = jew[i].weight; // 선택한 보석의 기준 무게 잡기
		j = jew[i].weight; // interation 변수
 
		while (j <= L) { // j: 보석의 무게가 한계치보다 작을동안. j는 jew[i].weight의 배수로 움직여야하는거 아닌가 생각했는데 아님. 모든경우를 다 보기 위해 순서대로 탐방.
			if (dy[j - tmp] + jew[i].value > dy[j]) { // 현재 보석보다 다른 or 새로운 보석을 담는 경우의 가치가 클때
				dy[j] = dy[j - tmp] + jew[i].value; // 선택한 보석의 가치를 계속 더해준다.
				                                    // 여기가 중요한데,  tmp(i, 선택한 보석) 무게를 가진 보석을 더하기위해,
				                                    // j - tmp 무게에 저장된 가치에 현재 보석의 가치를 더한다. (j-tmp 무게만큼 가방에 저장되어있는데, 여기에 tmp 무게를 넣었을 때 가치가 궁금한 것이므로)

			}
			j++;
		}
	}

	for (int i = 1; i <= L; i++) {
		if (dy[i] > max) max = dy[i];
	}

	cout << max;
	return 0;
}