#include <map>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//�տ��� char Ű, �ڿ��� int value�� �Ѵ�. 
	map<char, int> ch;

	// �����Ϳ� �����ϱ� ���� �ݺ��ڰ� �ʿ���. �ε����� ���� �Ұ�.
	map<char, int>::iterator it;

	char a[100];
	
	cout << "chk \n";
	cin >> a;

	// �� ���ĺ� ���� ī��Ʈ

	for (int i = 0; a[i] != '\0'; i++) {
		// a[i]�� Ư�� ���ĺ��ε�, �� Ư�� ���ĺ��� Ű�� ��. ����, �ش� Ű(���ĺ�)�� ����� Ȯ���� �� ����.
		ch[a[i]]++; //�̷��� �ϸ� ī��Ʈ�� ��
	}

	// �Ʒ�ó�� ���ͷ����ͷ� �����Ѵ�. 
	for (it = ch.begin(); it != ch.end(); it++) {
		cout << it->first << ' ' << it->second << "\n";
	}

	//return 0;
}