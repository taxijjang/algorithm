#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int num[10] = { 0, };
bool cmp(const int& a, const int& b) {
	return a> b;
}
int main(void) {
	string s;
	cin >> s;

	int s_size = s.size();
	int judge = 0;

	for (int i = 0; i<s_size; i++) {
		num[s[i] -'0'] += 1;
		judge += s[i] - '0';
	}

	if (num[0] == 0 && judge %3 != 0) {
		printf("%d", -1);
		return 0;
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < num[i]; j++) {
			printf("%d", i);
		}
	}

	return 0;
}