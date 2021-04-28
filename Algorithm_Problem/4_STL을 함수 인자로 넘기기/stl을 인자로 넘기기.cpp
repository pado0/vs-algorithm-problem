#include <iostream>
#include <vector>

using namespace std;


//������ &�� ������� ������ vector�� ��� �����ϰ� �ǹǷ� 
// �ð����⵵�� O(N)�� �ȴ�.

bool cmp2(vector<int>& v1, vector<int>& v2, int idx) {
	return v1[idx] > v2[idx];
}

int main() {
	//����� �ӵ� ���̱�
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> v1;
	vector<int> v2;

	v1.push_back(1);
	v1.push_back(2);

	v2.push_back(3);
	v2.push_back(1);

	cout << cmp2(v1, v2, 0); // v1=1, v2 = 3, false����
	cout << cmp2(v1, v2, 1); // v1=2, v2 = 1, true����
}