
#include <iostream>
using namespace std;
int arr[1001];
int dy[1001]; // 해당 인덱스 값이 증가수열의 마지막 항일때 가장 긴 길이
int max = 0;
int n;

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		// dp로 풀어주기: index i를 마지막항으로 하는 증가수열 count 하기


		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			dy[i] = 0;
		}

		dy[1] = 1;
		
		// i=1일땐 1로 초기화해주고, 2부터 몇개있는지 세어주기
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {

				// 자기보다 작은 값인애를 마지막으로 하는 수열의 길이 + 1(자기자신 포함1) 중 가장 큰값을 채택하면 됨.
				
				if (arr[i] > arr[j]) {

					// 이전 길이보다 큰 길이가 나오면 갱신한다.
					if (dy[j] + 1 > dy[i]) {
						dy[i] = dy[j] + 1;
					}
				}
			}

			if (dy[i] == 0) dy[i] = 1;
		}
		
		for (int i = 1; i <= n; i++) {

			if (dy[i] > max) max = dy[i];
		}

		cout << max;
		return 0;

	}


