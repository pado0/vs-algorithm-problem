// 이 유형의 문제는 진짜 생각 다시해봐야겠다.
// 포문을 두 번 안돌리고 어떻게 달성하지?

#include <iostream>
#include <string>
#include <set>
using namespace std;

int compare[120];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s, c;
	cin >> s >> c;

	for (int i = 0; i < c.size(); i++) {
		compare[c[i]]++;
	}


	for (int i = 0; i <= s.size() - c.size(); i++) {
		
	}

}