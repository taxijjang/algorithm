#include <string>
#include <vector>
#include<iostream>
#include<map>

using namespace std;

string arr[1010];
int solution(string s) {
	int answer = 0;
	int s_size = s.size();
	int min_size = 10000;
	for (int len = 1; len <= s_size; len++) {
		arr[len] = "";
		string cmp = "";
		string cut;
		int cnt = 0;
		int i;
		for (i = 0; i <= s_size - len; i = i + len) {
			cut = "";
			for (int j = i; j < i + len; j++) {
				cut += s[j];
			}
			if (cmp != cut) {
				if (cnt == 0 || cnt == 1) {
					arr[len] += cmp;
				}
				else {
					arr[len] += to_string(cnt) + cmp;
				}
				cnt = 1;
				cmp = cut;
				cut = "";
			}
			else if (cmp == cut) {
				cnt++;
			}
		}

		if (cnt == 0 || cnt == 1) {
			arr[len] += cmp;
		}
		else {
			arr[len] += to_string(cnt) + cmp;
		}
		for (; i < s_size; i++) {
			arr[len] += s[i];
		}
		min_size = min_size > arr[len].size() ? arr[len].size() : min_size;
	}

	answer = min_size;
	return answer;
}

int main(void) {
	string s;
	s = "aaaaaaaaaaaaaaa";
	cout << solution(s);
}