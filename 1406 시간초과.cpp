#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	string s; //�Է� ���� ���ڿ�
	int cnt; //���̽� ��
	string edit; //���� �� ��ɾ�



	cin >> s;
	cin >> cnt;

	int cursor = s.size(); //Ŀ�� ��ġ�� �� ��
	cin.ignore(256, '\n');
	while (cnt-- > 0) {

		getline(cin, edit, '\n');
		//cout << edit;
		char e; //��ȭ�� ��ɾ�
		e = edit.at(0);
		switch (e) {
		case 'L': //Ŀ���� �������� �� ĭ �ű�(Ŀ���� ������ �� ���̸� ���õ�)
			if (cursor <= 0)//Ŀ���� �� ���� �϶� Ŀ���� ��ȭ ����
				break;
			cursor--;
			break;
		case 'D': //Ŀ���� ���������� �� ĭ �ű�(Ŀ���� ������ �� ���̸� ���õ�)
			if (cursor >= s.size())//Ŀ���� �� ������ �϶� Ŀ���� ��ȭ ����
				break;
			cursor++;
			break;
		case 'B': //Ŀ�� ���ʿ� �ִ� ���ڸ� ����
			if (cursor <= 0)
				break;
			s = s.erase(cursor - 1, 1);
			cursor--;
			break;
		case 'P': //$��� ���ڸ� Ŀ�� ���ʿ� �߰���
			s.insert(cursor, edit.substr(2));
			cursor++;
			break;

		default:
			break;
		}
	}
	cout << s;


}