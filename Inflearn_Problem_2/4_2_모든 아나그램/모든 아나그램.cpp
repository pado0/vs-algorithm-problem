/*
아나그램, 나열은 다르지만 구성이 일치
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

int a[200];
int b[200];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s, c;
	string tmp = "";
	cin >> s >> c;

	int clength = c.size();
	int cnt = 0;
	int sol = 0;

	
	// s 스트링 시작점 선택
	for (int i = 0; i <= s.size() - clength; i++) {
		cnt = 0;
		tmp = "";
		for (int j = 90; j < 120; j++) {
			a[j] = 0; b[j] = 0;
		}

		// s배열 잘라 tmp 스트링 만들기
		for (int j = i; j < i + clength; j++) {
			tmp = tmp + s[j];
		}

		//tmp와 c 스트링 요소가 같으면됨
		for (int j = 0; j < clength; j++) {
			a[c[j]]++;
			b[tmp[j]]++;
		}

		for (int j = 90; j < 120; j++) {
			if (a[j] == b[j] && a[j] !=0) {
				cnt = cnt + a[j];
			}
		}
		if (cnt == clength) sol++;
	
	}
	cout << sol;
}

