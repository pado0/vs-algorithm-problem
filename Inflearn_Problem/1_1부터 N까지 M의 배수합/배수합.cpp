/*
자연수 N이 입력되면
1부터 N까지의 수 중 M의 배수 합을 출력하는 프로그램
*/

#include <iostream>
using namespace std;

int main() {

	int N , M;
	int sum = 0;
	cin >> N >> M;

	for (int i = 2; i <= N; i++) {
		if(i%M ==0){
			sum = sum +i;
		}
	}

	cout << sum;
}