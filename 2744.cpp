#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string s; cin >> s;

	for (int i = 0; i < s.size(); i++) {
		char t;
		if (s[i] >= 'a' && s[i] <= 'z')
			t = s[i] - 32;
		else
			t = s[i] + 32;
		printf("%c", t);
	}
}