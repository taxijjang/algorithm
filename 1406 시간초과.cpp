#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	string s; //입력 받을 문자열
	int cnt; //케이스 수
	string edit; //편집 할 명령어



	cin >> s;
	cin >> cnt;

	int cursor = s.size(); //커서 위치는 맨 뒤
	cin.ignore(256, '\n');
	while (cnt-- > 0) {

		getline(cin, edit, '\n');
		//cout << edit;
		char e; //정화된 명령어
		e = edit.at(0);
		switch (e) {
		case 'L': //커서를 왼쪽으로 한 칸 옮김(커서가 문장의 맨 앞이면 무시됨)
			if (cursor <= 0)//커서가 맨 왼쪽 일때 커서의 변화 없음
				break;
			cursor--;
			break;
		case 'D': //커서를 오른쪽으로 한 칸 옮김(커서가 문장의 맨 뒤이면 무시됨)
			if (cursor >= s.size())//커서가 맨 오른쪽 일때 커서의 변화 없음
				break;
			cursor++;
			break;
		case 'B': //커서 왼쪽에 있는 문자를 삭제
			if (cursor <= 0)
				break;
			s = s.erase(cursor - 1, 1);
			cursor--;
			break;
		case 'P': //$라는 문자를 커서 왼쪽에 추가함
			s.insert(cursor, edit.substr(2));
			cursor++;
			break;

		default:
			break;
		}
	}
	cout << s;


}