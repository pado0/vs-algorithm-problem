#include <iostream>
#include <vector>

using namespace std;


//참조자 &를 사용하지 않으면 vector를 모두 복사하게 되므로 
// 시간복잡도가 O(N)이 된다.

bool cmp2(vector<int>& v1, vector<int>& v2, int idx) {
	return v1[idx] > v2[idx];
}

int main() {
	//입출력 속도 높이기
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v1;
	vector<int> v2;

	v1.push_back(1);
	v1.push_back(2);

	v2.push_back(3);
	v2.push_back(1);

	cout << cmp2(v1, v2, 0); // v1=1, v2 = 3, false리턴
	cout << cmp2(v1, v2, 1); // v1=2, v2 = 1, true리턴
}