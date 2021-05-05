#include <iostream>
using namespace std;
int unf[100];

int find(int v) {
	if (unf[v] == v) return v;
	else return unf[v] = find(unf[v]);
}

void uni(int a, int b){
	a = find(a);
	b = find(b);

	//찾은 a의 집합번호에다 b의집합번호를 넣어줘야됨.
	// 그래야 같은 집합번호를 갖게됨
	// a=1,집합번호4, b=5,집합번호 5라면
	// unf[4] = 5로 해줘야 루트노드를 5로 만드는 것임
	// unf[4]=5, unf[5]= 5상태인것.
	if (a != b) unf[a] = b;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;	//학생수, 숫자쌍
	cin >> n >> m;

	/*
	//같은 그룹이면 같은 ID를 먹임?

	// find : 넘어온 매개변수 값의 집합번호를 리턴함
			- 재귀로 찾음. > 왜 재귀로 찾는지..
			ex. 1,2 / 2,3 / 3,4가 들어올때
			[1][2][3][4][5]
		 	 1  2  3  4  5
			>1차
			[1][2][3][4][5]
			 2  2  3  4  5
			>2차
			[1][2][3][4][5]
			 2  3  3  4  5

			 = find는 1을 넣으면 2리턴, 2를 다시넣어 3리턴, 3은 3을 리턴하니까.
			 결국 1,2,3이 다같은 3으로 귀결되어 같은 집합임을 의미
			 루트노드의 번호로 집합번호가같아지는 것임

	// unf[] : 집합번호를 저장하는 배열
	// Union : 둘의집합번호가 다르면 같게 만들어줌

	*/

	// 집합번호 배열 초기화
	for (int i = 1; i <= n; i++) {
		unf[i] = i;
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		uni(a, b);
	}

	cin >> a >> b;

	if (find(a) == find(b))cout << "YES";
	else cout << "NO";
}