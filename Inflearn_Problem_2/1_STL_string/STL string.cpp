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
	cout << a.substr(0, 4)<< "\n"; // 0부터 4개

	//싹 다 지우기
	//a.clear();
	//cout << a << "\n";

	// 가장 긴 단어 찾기 문제 !!
	string res;
	int pos, max = INT_MIN; // 가장 작은 정수 뽑기
	
	a = "it is time to study";
	
	// npos? : string::npos 는 -1의 값을 가지는 상수, find()에 의해 발견된 원소가 없으면 npos 값 리턴
	while ((pos = a.find(' ')) != string::npos) {// find() : 발견됐으면 인덱스 리턴, 발견 안됐으면 거짓되어 끝남
		string tmp = a.substr(0, pos);
		int len = tmp.size();
		if (len > max) {
			max = len;
			res = tmp;
		}
		a = a.substr(pos + 1); // 띄어쓰기 뒤에부터 다시 가져옴, study 마지막단어는 안나오는데, ' '가 없기 때문임.
	}

	// 마지막 남은 단어가 study이므로 이단어로 한번 더 비교
	if (a.size() > max) res = a;
	cout << res << "\n";
}