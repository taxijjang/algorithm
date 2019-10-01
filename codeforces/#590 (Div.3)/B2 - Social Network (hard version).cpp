2 - hard
#include<iostream>
#include<deque>
#include<map>
#define SIZE 200010

using namespace std;

map<int, bool> m;
deque<int> dq;
int main(void) {
	int n, k; cin >> n >> k;

	for(int i =0 ; i < n ;i++){
		int num; cin >> num;

		if (dq.empty()) {
			dq.push_front(num);
			if (m.find(num) == m.end())
				m.insert({ num,true });
			else
				m[num] = true;
		}

		else {
			if (m[num] == true )
				continue;
			else {
				if (dq.size() == k) {
					m[dq.back()] = false;
					dq.pop_back();
					dq.push_front(num);
				}
				else {
					dq.push_front(num);
				}
				if (m.find(num) == m.end()) {
					m.insert({ num,true });
				}
				else
					m[num] = true;
			}
		}
	}

	cout << dq.size() << '\n';
	for (auto it = dq.begin(); it != dq.end(); it++) {
		cout << *it << ' ';
	}
}