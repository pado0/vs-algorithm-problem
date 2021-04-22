#include <iostream>
#include <queue>
using namespace std;
int main() {
	//버퍼 오버플로우가 나면 입력은 모두 버려짐
	// N: 버퍼크기 0: 1개 처리,


	//이거 말고 버퍼 대기 예제 한개 더 풀어보기

	queue<int> q;
	int N,x;
	cin >> N;

	while (1) {

		cin >> x;

		if (x == -1)break;
		if (x == 0 && !q.empty()) {
			q.pop();
		}
		else {
			if (q.size() < N) {
				q.push(x);

			}
		}
	}
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}