#include <iostream>
#include <string>

using namespace std;


int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0;i < N ; i++) {
		string s;
		cin >> s;
		int score;
		int cnt;
		if (s[0] == 'O') {
			score = 1;
			cnt = 1;
		}
		else {
			score = 0;
			cnt = 0;
		}

		int size =s.size();
		char O_X = s[0];

		for (int j = 1; j < size; j++) {
			if (s[j] == 'O') {
				++cnt;
				score += cnt;				
			}
			else {
				cnt = 0;
			}
		}
		printf("%d\n", score);
	}
}