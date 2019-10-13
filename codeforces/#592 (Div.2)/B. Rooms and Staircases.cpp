#include<iostream>
#include<string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N; cin >> N;
		string S; cin >> S;

		int index1 = -1;
		int index2 = -1;
		int s_size = S.size();
		for (int i = 0; i < s_size; i++) {
			if (S[i] == '1') {
				index1 = index1 < i + 1 ? i + 1 : index1;
				index2 = index2 < s_size - i ? s_size - i : index2;
			}
		}

		int res = index1 < index2 ? index2 : index1;
		if (res == -1)
			cout << N << "\n";
		else
			cout << res * 2 << "\n";
	}
}