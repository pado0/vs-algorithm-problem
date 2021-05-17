//bits/stdc++.h 헤더 사용하기:  https://miniolife.tistory.com/11 

#include <bits/stdc++.h>

using namespace std;

int main() {
	
	// 0번 인덱스부터 시작, 마지막 인덱스는 null
	string a = "Time is 2021 Year 5 Month";
	cout << a.size() << endl;

	// 문자열 길이
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}

	cout << "\n";

	// 대문자 
	for (int i = 0; i < a.size(); i++) {
		if (isupper(a[i])) cout << a[i] << " ";
	}

	cout << "\n";

	// 소문자
	for (int i = 0; i < a.size(); i++) {
		if (islower(a[i])) cout << a[i] << " ";
	}

	cout << "\n";

	// 숫자만
	for (int i = 0; i < a.size(); i++) {
		if (isdigit(a[i])) cout << a[i] << " ";
	}

	cout << "\n";

	// 특정 문자만, 제일 먼저 발견되는 문자의 인덱스
	cout << a.find('T') << "\n"; 


	//문자 추가, 뒤에 문자추가
	a.push_back('S');
	cout << a << "\n";

	
	// 문자 꺼내기
	a.pop_back();
	cout << a << "\n";

	// 문자 or 문자열 추가 방법2
	a = a + "s Happy birthday";
	cout << a << "\n";

	// 특정 부분 문자열 뽑아내기 : from index to end
	cout << a.substr(a.find('2')) << "\n";
	cout << a.substr(0, 4); // 0부터 4개

	//싹 다 지우기
	a.clear();
	cout << a << "\n";
	

}