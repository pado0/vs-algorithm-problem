#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;
int sol[100];
int prob = 1;
int main() {
	int T, N, K;
	char input[30];

	int num; // 비교해야 하는 숫자 자릿수
	queue<char> q;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;

		for (int i = 1; i <= N; i++) {
			cin >> input[i];
		}

		num = N / 4; // 회전수도 동일

		int cnt = num;
		int index = cnt;
		int tmp;

		for (int i = 1; i <= N; i++) {
			for (int j = i; j < i + num; j++) {
				tmp = j;

				if (tmp > N) tmp = tmp % N;

				if (input[tmp] <= 57) {
					sol[i] = sol[i] + (input[tmp] - 48) * pow(16, cnt - 1);
				}
				else {
					sol[i] = sol[i] + (input[tmp] - 55) * pow(16, cnt - 1);
				}
				cnt--;

				if (cnt == 0)cnt = num;
			}
		}

		int flag = 0;
		vector<int> v;

		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (i != j && sol[i] == sol[j]) {
					flag = 1;
				}
			}
			if (flag == 0) { v.push_back(sol[i]); }
			else { flag = 0; }
		}

		for (int i = 0; i < v.size(); i++) {
			for (int j = i; j < v.size(); j++) {
				if (v[i] < v[j]) { // 내림차순 정리
					int temp = v[i];
					v[i] = v[j];
					v[j] = temp;
				}
			}
		}

		for (int i = 0; i < v.size(); i++) {
			if (i + 1 == K) {
				cout << "#" << prob << " " << v[i] << endl;
				prob++;
			}
		}

		for (int i = 0; i <= N; i++) {
			sol[i] = 0;
		}
	}
}