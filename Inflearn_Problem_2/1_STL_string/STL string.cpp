//bits/stdc++.h ��� ����ϱ�:  https://miniolife.tistory.com/11 

#include <bits/stdc++.h>

using namespace std;

int main() {
	
	// 0�� �ε������� ����, ������ �ε����� null
	string a = "Time is 2021 Year 5 Month";
	cout << a.size() << endl;

	// ���ڿ� ����
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}

	cout << "\n";

	// �빮�� 
	for (int i = 0; i < a.size(); i++) {
		if (isupper(a[i])) cout << a[i] << " ";
	}

	cout << "\n";

	// �ҹ���
	for (int i = 0; i < a.size(); i++) {
		if (islower(a[i])) cout << a[i] << " ";
	}

	cout << "\n";

	// ���ڸ�
	for (int i = 0; i < a.size(); i++) {
		if (isdigit(a[i])) cout << a[i] << " ";
	}

	cout << "\n";

	// Ư�� ���ڸ�, ���� ���� �߰ߵǴ� ������ �ε���
	cout << a.find('T') << "\n"; 


	//���� �߰�, �ڿ� �����߰�
	a.push_back('S');
	cout << a << "\n";

	
	// ���� ������
	a.pop_back();
	cout << a << "\n";

	// ���� or ���ڿ� �߰� ���2
	a = a + "s Happy birthday";
	cout << a << "\n";

	// Ư�� �κ� ���ڿ� �̾Ƴ��� : from index to end
	cout << a.substr(a.find('2')) << "\n";
	cout << a.substr(0, 4); // 0���� 4��

	//�� �� �����
	a.clear();
	cout << a << "\n";
	

}