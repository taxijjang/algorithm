#include<iostream>
#include<map>
#include<string>

using namespace std;

map<char,int> phone;

int main(void) {
	char c = 'A';
	for (int i = 2; i <= 9; i++) {
		int cnt = 3;
		if (i == 7 || i == 9) {
			cnt = 4;
		}
		for (int j = 0; j < cnt; j++) {
			phone[c++] = i;
		}
	}

	string s; cin >> s;

	int s_size = s.size();
	int time = s_size;
	for (int i = 0; i < s_size; i++) {
		time += phone[s[i]];
	}
	printf("%d", time);
}
