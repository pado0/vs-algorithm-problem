#include <iostream>

using namespace std;
 
int main() {
// 2n-1개의 별, n-1개의 공백

	int n;
	cin >> n;

	for (int j = 0; j < n; j++) {

		for (int i = j; i < n - 1; i++) cout << " ";
		for (int i = 0; i < 2 * j + 1; i++) cout << "*";

		cout << "\n";
	}
}