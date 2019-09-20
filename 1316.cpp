#include<iostream>
#include<string>
using namespace std;

int arr[30];
void init() {
	for (int i = 0; i < 30; i++) {
		arr[i] = 0;
	}
}
int main(void) {
	ios::sync_with_stdio(false);

	int T; cin >> T;
	int res = 0;
	for (int t = 0; t < T; t++) {
		init();
		string s; cin >> s;
		char check = s[0];
		bool pass = false;
		int s_size = s.size();

		arr[s[0] - 'a'] = 1;

		for (int i = 1; i < s_size; i++) {
			if (check == s[i])
				arr[s[i] - 'a'] ++;
			else if (check != s[i]) {
				check = s[i];
				if (arr[s[i] - 'a'] != 0) {
					pass = true;
					break;
				}
				else if (arr[s[i] - 'a'] == 0) {
					arr[s[i] - 'a']++;
				}
			}
		}
		if (pass != true)
			res++;
	}

	cout << res;
}