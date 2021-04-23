/*
N개 시험장
i 번 시험장의 응시자수 A명

1)총감독관: 시험장마다 1명, 응시자 B명 감시 가능
2) 부감독관: 응시자 C명 감시가능.

solution > 꼭 필요한 감독관 수 최소값
caution > if master test supervisor can watch more than 응시자, answer is 1.

*/

#include <iostream>
long long total = 0;
long long sol = 0; // 부감독 수
using namespace std;

int p[1000000];
int main() {
	int N; //시험장 개수
	int A, B, C;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}

	cin >> B >> C;
	
	for (int i = 0; i < N; i++) {
		if (p[i] - B > 0) {
			if ((p[i] - B) % C > 0) {
				sol = (p[i] - B) / C + 1;

			}
			else if ((p[i] - B) % C == 0) {
				sol = (p[i] - B) / C;
			}
			total = total + sol;
		}
	}

	/*for (int i = 0; i < N; i++) {
		if ((p[i] - B) % C > 0 && p[i] - B > 0) {
			sol = (p[i] - B) / C + 1;

		}
		else if ((p[i] - B) % C == 0 && p[i] - B > 0) {
			sol = (p[i] - B) / C;
		}
		total = total + sol; // 이작업도 p[i]-B>0일때 해줘야함.
		작을때 해주면 sol에 0이 아닌 다른값이 들어가있으므로.
	}*/
	//cout << " n: " << N  << " t: "<< total <<endl;
	cout << total + N; // total: 부감독관수,N:주감독관수}


}