#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int s_size = s.size();

		sort(s.begin(), s.end());

		bool judge = true;
		for (int i = 0; i < s_size - 1; i++) {
			if (s[i + 1] - s[i] != 1) {
				printf("NO\n");
				judge = false;
				break;
			}
		}

		if (judge) {
			printf("YES\n");
		}


	}
}