#include <iostream>
#include <algorithm>

using namespace std;
int unf[100];

struct node {
	int sv;
	int ev;
	int weight;

	bool operator < (const node &d) const {
		return weight < d.weight;
	}
};

struct node N[100];
int sum = 0;

int Find(int v) {
	if (unf[v] == v) return v;
	else return Find(unf[v]); // 루트노드를 향한 여정 
}

int Union(int a, int b) {
	// 들어온 노드의 집합번호 찾기
	a = Find(a);
	b = Find(b); 

	if (a != b) {
		unf[a] = b;
		return 1;
	} // 두개의 집합이 다르면 union
	else  return 0; // 이게 이미 같은 상태면 유니온 안해줌
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 도시를 연결하는데 드는 최소비용?

	// Kruskal은 전체적인 관점에서 최적이라는게 증명되어있음
	
	// 최소 간선부터 선택하여 노드끼리 union
	// union & find로 사이클 생성여부 체크
	// - 뭐가 사이클이지?
	// - 새로 연결한 간선의 두 노드가 이미 같은 집합이면 사이클!
	// 사이클이 없으면 MST 집합에 추가
	

	// 배열의 인덱스가 노드번호, 
	// 배열 값이 속한 집합

	int v, e;

	cin >> v >> e;

	// struct 만들어서
	// 가중치 기준으로 정렬하는게 낫겠다,
	// 정렬 후 간선연결되면, 해당 가중치를 sum변수로 합.

	
	for (int i = 1; i <= v; i++) {
		unf[i] = i;
	}
	for (int i = 1; i<= e; i++) {
		cin >> N[i].sv;
		cin >> N[i].ev;
		cin >> N[i].weight;
	}

	sort(N+1, N + e+1);

	for (int i = 1; i <= e; i++) {
		if (Union(N[i].sv, N[i].ev) == 1) {
			sum = sum + N[i].weight;
		}

	}
	cout << sum;

	
}