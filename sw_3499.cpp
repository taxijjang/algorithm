#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int n; cin >> n;

		queue<string> q1, q2;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			if (n % 2 == 0) {
				if (i < n / 2)
					q1.push(s);
				else
					q2.push(s);
			}
			else{
				if (i < n / 2 + 1)
					q1.push(s);
				else
					q2.push(s);
			}
		}

		cout << "#" << t << " ";
		for (int i = 0; i < n/2; i++) {
			cout << q1.front() << " " << q2.front() << " ";
			q1.pop(), q2.pop();
		}
		if (!q1.empty())
			cout << q1.front();
		cout << "\n";
	}


}