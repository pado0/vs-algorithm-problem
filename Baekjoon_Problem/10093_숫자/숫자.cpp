#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;

	if (a == b) {
		cout << "0";
		return 0;
	}
	cout << abs(b - a)-1 << "\n";

	if (a <= b) {
		for (long long i = a + 1; i < b; i++) {
			cout << i << " ";
		}
	}
	else {
		for (long long i = b + 1; i < a; i++) {
			cout << i << " ";
		}
	}
}