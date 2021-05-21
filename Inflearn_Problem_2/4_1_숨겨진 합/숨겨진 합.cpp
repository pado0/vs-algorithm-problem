#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int partial = 0;
	int sum = 0;

	for (int i = 0; i < s.size(); i++) {
		int x = (int)s[i];
		
		// 숫자일 때 계속 더함
		if (x >= 48 && x <= 57) {
			
			// 부분합이 0 일때 (0으로 시작하는것 걸러주는 겸)
			if (partial == 0) {
				partial = x - 48;
			}
			// 다음 숫자를 발견했을 때
			else {
				partial = partial * 10 + x - 48;
			}

		}
		//문자일 때 합값 초기화
		else {
		//	cout << partial << endl;
			sum = sum + partial;
			partial = 0;
		}
	}
	
	// 초기화 못한 나머지 합값 다시더해주기
	sum = sum + partial;
	cout << sum;
}