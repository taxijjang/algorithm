#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string s;
	cin >> s;

	int z_cnt = 0;
	int o_cnt = 0;

	int s_size = s.size();

	if (s[0] == '0') z_cnt++;
	else o_cnt++;

	for (int i = 1; i < s_size; i++) {
		if (s[i] != s[i-1]) {
			if (s[i] == '0') z_cnt++;
			else o_cnt++;
		}
	}

	
	int min = z_cnt < o_cnt ? z_cnt : o_cnt;

	printf("%d", min);
}