#include <bits/stdc++.h>
//#include <set> // ������ϴµ�, ���� �ߺ������Ҷ��� ���� �� �Ⱦ���
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> a = { 1,3,2,3,2,3,2,3,1,2 };
	set<int> s;

	for (int i = 0; i < a.size(); i++) {
		s.insert(a[i]); // �ڷᰡ ���� ���� �ڵ����� ���ĵǰ�, �ߺ��� ������� ����.
	}

	cout << s.size() << "\n";
	for (auto it = s.begin(); it != s.end(); it++) { // auto Ű���� ���� Ȯ��, ������ end()�� �ƴϴٶ�� �������. ������ �ƴ϶� < >�Ұ�
		cout << *it << " ";
	}

	cout << "\n";

	for (auto x : s) cout << x << " "
		;
	cout << "\n";

	if (s.find(3) == s.end()) cout << "false"; // 3�� ã�Ҵµ� ������ s,end()�� ����
	else cout << "true";
	return 0;

}