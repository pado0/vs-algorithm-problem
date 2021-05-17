#include <bits/stdc++.h>
//#include <set> // 해줘야하는데, 보통 중복제거할때만 쓰고 잘 안쓴다
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> a = { 1,3,2,3,2,3,2,3,1,2 };
	set<int> s;

	for (int i = 0; i < a.size(); i++) {
		s.insert(a[i]); // 자료가 들어가는 순간 자동으로 정렬되고, 중복을 허용하지 않음.
	}

	cout << s.size() << "\n";
	for (auto it = s.begin(); it != s.end(); it++) { // auto 키워드 뭔지 확인, 마지막 end()가 아니다라고 해줘야함. 정수가 아니라서 < >불가
		cout << *it << " ";
	}

	cout << "\n";

	for (auto x : s) cout << x << " "
		;
	cout << "\n";

	if (s.find(3) == s.end()) cout << "false"; // 3을 찾았는데 없으면 s,end()를 리턴
	else cout << "true";
	return 0;

}