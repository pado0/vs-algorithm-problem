
#include <iostream>
#include <queue>

using namespace std;

struct Loc {
	int x, y;

	Loc(int xin, int yin) {
		x = xin; y = yin;
	}

	bool operator < (const Loc &d)const {
		return x < d.x;
		/*a < b일 때, b가 크다면 b를 위로 올려주고, a가 크다면 a를 위로 올려줌.
		즉, 위 예제는 큰걸 위로 올려주는 코드, 내림차순임. ex. 10 9 8 7...
		a.operator<(b)의 반환값이 1(참)이면 b를 올려주고, a.operator<(b)의 반환값이 0(거짓)이면 a를 올려준다*/
	}

};


int main() {
	int N;
	priority_queue<Loc> pq;

	pq.push(Loc(1, 2));
	pq.push(Loc(4, 3));
	pq.push(Loc(2, 6));
	pq.push(Loc(3, 1));
	pq.push(Loc(5, 7));

	while (!pq.empty()) {
		cout << pq.top().x << " " << pq.top().y << endl;
		pq.pop();
	}

}