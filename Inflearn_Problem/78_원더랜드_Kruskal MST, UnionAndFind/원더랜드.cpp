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
	else return Find(unf[v]); // ��Ʈ��带 ���� ���� 
}

int Union(int a, int b) {
	// ���� ����� ���չ�ȣ ã��
	a = Find(a);
	b = Find(b); 

	if (a != b) {
		unf[a] = b;
		return 1;
	} // �ΰ��� ������ �ٸ��� union
	else  return 0; // �̰� �̹� ���� ���¸� ���Ͽ� ������
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ���ø� �����ϴµ� ��� �ּҺ��?

	// Kruskal�� ��ü���� �������� �����̶�°� ����Ǿ�����
	
	// �ּ� �������� �����Ͽ� ��峢�� union
	// union & find�� ����Ŭ �������� üũ
	// - ���� ����Ŭ����?
	// - ���� ������ ������ �� ��尡 �̹� ���� �����̸� ����Ŭ!
	// ����Ŭ�� ������ MST ���տ� �߰�
	

	// �迭�� �ε����� ����ȣ, 
	// �迭 ���� ���� ����

	int v, e;

	cin >> v >> e;

	// struct ����
	// ����ġ �������� �����ϴ°� ���ڴ�,
	// ���� �� ��������Ǹ�, �ش� ����ġ�� sum������ ��.

	
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