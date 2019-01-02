#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

int main(void) {
	char word[100000];
	int N;
	string w;
	stack <char> s1,s2;
	char temp;
	char menu;
	char ins;
	//L Ŀ���� �������� �� ĭ �ű�
	//D Ŀ���� ���������� �� ĭ �ű�
	//B Ŀ�� ���ʿ� �ִ� ���ڸ� ������
	//������ ���� Ŀ���� �� ĭ �������� �̵��� ��ó�� ��Ÿ������
	//������ Ŀ���� �����ʿ� �ִ� ���ڴ� �״����
	//P $ $��� ���ڸ� Ŀ�� ���ʿ� �߰���

	cin >> w;

	cin >> N;

	strcpy(word, w.c_str());

	for (int i = 0; i < w.length(); i++) {
		s1.push(w[i]);
	}

	for (int n = 0; n < N; n++) {
		cin >> menu;
		if (menu == 'P') {
			cin >> ins;
			s1.push(ins);
		}

		else if (menu == 'L' && s1.size() != 0) {
			s2.push(s1.top());
			s1.pop();
		}
		else if (menu == 'D' && s2.size() != 0) {
			s1.push(s2.top());
			s2.pop();
		}
		else if (menu == 'B' && s1.size() != 0) {
			s1.pop();
		}
	}

	int s1size = s1.size();
	for (int s = 0; s < s1size; s++) {
		s2.push(s1.top());
		s1.pop();
	}

	int s2size = s2.size();
	for (int ss = 0; ss < s2size; ss++) {
		cout << s2.top();
		s2.pop();
	}

}

