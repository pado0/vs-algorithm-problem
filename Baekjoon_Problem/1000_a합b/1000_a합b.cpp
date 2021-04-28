#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	/* 1000_a+b
	int A, B;
	cin >> A >> B;
	cout << A + B;
	*/

	int a, b, c;
	cin >> a >> b >> c;

	if (a >= b && a >= c) {
		if (b >= c) cout << c << " " << b << " " << a;
		else cout << b << " " << c << " " << a;
	}
	else if (b >= a && b >= c) {
		if (a >= c) cout << c << " " << a << " " << b;
		else cout << a << " " << c << " " << b;

	}
	else {
		if (b >= a) cout << a << " " << b << " " << c;
		else cout << b << " " << a << " " << c;

	}
}