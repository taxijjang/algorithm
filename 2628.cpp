#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);

	int M, N; cin >> M >> N;
	int T; cin >> T;

	vector<int> garo;
	garo.push_back(0); garo.push_back(M);
	vector<int> sero;
	sero.push_back(0); sero.push_back(N);

	for (int t = 1; t <= T; t++) {
		int menu, num; cin >> menu >> num;
		if (menu == 0)
			sero.push_back(num);
		else
			garo.push_back(num);
	}

	sort(garo.begin(), garo.end());
	sort(sero.begin(), sero.end());

	int ga = 0, se = 0;
	for (int i = 1; i < garo.size(); i++) {
		ga = ga < garo[i] - garo[i - 1] ? garo[i] - garo[i - 1] : ga;
	}

	for (int i = 1; i < sero.size(); i++) {
		se = se < sero[i] - sero[i - 1] ? sero[i] - sero[i - 1] : se;
	}

	cout << ga*se;
}