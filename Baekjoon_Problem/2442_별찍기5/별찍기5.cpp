#include <iostream>

using namespace std;
 
int main() {
// 2n-1���� ��, n-1���� ����

	int n;
	cin >> n;

	for (int j = 0; j < n; j++) {

		for (int i = j; i < n - 1; i++) cout << " ";
		for (int i = 0; i < 2 * j + 1; i++) cout << "*";

		cout << "\n";
	}
}