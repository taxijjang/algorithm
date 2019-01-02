#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int N, M;
	int cnt = 1;
	queue<int> q1, solv;

	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		q1.push(n + 1);
	}

	while (!q1.empty()) {
		if (cnt++ % M == 0) {
			cnt = 1;
			solv.push(q1.front());
			q1.pop();
			continue;
		}
		q1.push(q1.front());
		q1.pop();
	}

	cout << "<";
	cnt = 1;
	while (!solv.empty()) {
		cout << solv.front();
		solv.pop();
		if (cnt++ < N) {
			cout << ", ";
		}
	}
	cout << ">";
}