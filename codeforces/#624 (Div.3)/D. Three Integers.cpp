#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

vector<int> factor(int num) {
	vector<int> res;
	for (int i = 1; i*i <= num; i++) {
		if (num%i == 0) {
			res.push_back(i);
			res.push_back(num / i);
		}
	}

	return res;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	while (T--) {
		int A, B, C; cin >> A >> B >> C;

		int total_dis = INF;
		int a_res, b_res, c_res;
		//b
		for (int b = 1; b <= 20000; b++) {
			int b_dis = abs(B - b);

			vector<int> fac = factor(b);
			int a_dis = INF;
			int a_tmp = -1;

			for (auto a : fac) {
				if (b%a == 0 && abs(A - a) < a_dis) {
					a_dis = abs(A - a);
					a_tmp = a;
				}
			}

			int c_dis = INF;
			int c_tmp = -1;
			for (int c = b; c <= 40000; c += b) {
				if (c%b == 0 && abs(C - c) < c_dis) {
					c_dis = abs(C - c);
					c_tmp = c;
				}
			}

			if (a_dis + b_dis + c_dis < total_dis) {
				a_res = a_tmp;
				b_res = b;
				c_res = c_tmp;
				total_dis = a_dis + b_dis + c_dis;
			}
		}

		cout << total_dis << "\n" << a_res << " " << b_res << " " << c_res << "\n";

	}
}