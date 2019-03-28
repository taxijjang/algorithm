#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string s;
	cin >> s;

	string result = "";
	int s_size = s.size();

	int cnt = 0;

	bool judge = true;
	for (int i = 0; i <= s_size; i++) {
		if (s[i] == 'X') cnt++;
		else if (s[i] == '.' || s[i] ==NULL) {
			if (cnt % 2 == 0) {
				for (int a = 0; a < (cnt / 4); a++) {
					result += "AAAA";
				}
				cnt -= (cnt / 4)*4;
				for (int j = 0; j < cnt/2; j++) {
					result += "BB";
				}
			}
			else {
				printf("-1\n");
				judge = false;
				break;
			}
			cnt = 0;
			if(s[i] != NULL)
				result += ".";
		}
	}

	if(judge || cnt == s_size)
		cout << result;
}