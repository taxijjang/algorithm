#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	getline(cin, s);

	int size = s.size();
	int cnt = 0;
	int judge = 1; //0알파벳일때 1공백일때
	for (int i = 0; i < size; i++) {
		if (s[i] >= 'A' && s[i] <= 'z') {
			if (judge == 1) {
				cnt++;
			}
			judge = 0;
		}
		if (s[i] == ' ') {
			judge = 1;
		}
	}

	printf("%d", cnt);
}