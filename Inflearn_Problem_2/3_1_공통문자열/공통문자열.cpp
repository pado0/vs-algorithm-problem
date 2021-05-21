/*
9:17 ~ 9:33
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a[30];
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	// 추가필요: 가장 짧은 문자까지만 비교해주면 됨.
	// count :해당 원소가 몇개있는지 리턴하는 함수 사용 가능
	// set 사용하여 중복허용하지 않는 것을 이용할 수 있음
	bool same = true;
	int j = 0;
	while (same) {
		for (int i = 0; i < N-1; i++) {
			if (a[i][j] == a[i+1][j])same = true;
			else { same = false; break; }
		}

		if (same == false) break;
		else j++;
	}

	
	for (int i = 0; i < j; i++) cout << a[0][i];
	
}