2번 - easy
#include<iostream>
#include<deque>

using namespace std;

int main(void) {
	int n, k; cin >> n >> k;

	deque<int> dq;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;

		if (dq.empty())
			dq.push_front(num);

		bool check = false;

		for (auto it = dq.begin(); it != dq.end(); it++) {
			if (*it == num)
				check = true;
		}

		if (check)
			continue;
		else {
			if (dq.size() == k) {
				dq.pop_back();
				dq.push_front(num);
			}
			else {
				dq.push_front(num);
			}
		}
	}
	cout << dq.size() << '\n';
	for (auto it = dq.begin(); it != dq.end(); it++) {
		cout << *it << ' ';
	}
}