#include<iostream>

using namespace std;

int check(int l, int cnt) {
	int res = 0;
	if (l <= cnt)
		return 1;
	else {
		res += l / cnt;
		if (l%cnt != 0)
			res++;
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false);
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int a, b, c, d, e; cin >> a >> b >> c >> d >> e;


		int lec_cnt = check(a, c);
		int prac_cnt = check(b, d);

		if (lec_cnt + prac_cnt <= e)
			cout << lec_cnt << " " << prac_cnt << "\n";
		else
			cout << "-1\n";
	}
}