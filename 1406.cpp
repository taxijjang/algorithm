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
	//L 커서를 왼쪽으로 한 칸 옮김
	//D 커서를 오른쪽으로 한 칸 옮김
	//B 커서 왼쪽에 있는 문자를 삭제함
	//삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만
	//실제로 커서의 오른쪽에 있던 문자는 그대로임
	//P $ $라는 문자를 커서 왼쪽에 추가함

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

