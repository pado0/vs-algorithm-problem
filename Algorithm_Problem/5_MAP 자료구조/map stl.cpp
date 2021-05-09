#include <map>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//앞에껄 char 키, 뒤에껄 int value로 한다. 
	map<char, int> ch;

	// 데이터에 접근하기 위한 반복자가 필요함. 인덱스로 접근 불가.
	map<char, int>::iterator it;

	char a[100];
	
	cout << "chk \n";
	cin >> a;

	// 각 알파벳 개수 카운트

	for (int i = 0; a[i] != '\0'; i++) {
		// a[i]는 특정 알파벳인데, 이 특정 알파벳을 키로 함. 따라서, 해당 키(알파벳)이 몇개인지 확인할 수 있음.
		ch[a[i]]++; //이렇게 하면 카운트가 됨
	}

	// 아래처럼 이터레이터로 접근한다. 
	for (it = ch.begin(); it != ch.end(); it++) {
		cout << it->first << ' ' << it->second << "\n";
	}

	//return 0;
}