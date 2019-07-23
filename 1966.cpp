#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	int T; scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N, M; scanf("%d %d", &N, &M);

		queue<pair<int, int>> q;
		priority_queue<pair<int, int>> pq;

		for (int i = 0; i < N; i++) {
			int index = i;
			int weight; scanf("%d", &weight);

			pair<int, int> pr = { weight,index };

			q.push(pr);
			pq.push(pr);
		}

		int cnt = 0;
		while (!pq.empty()) {
			pair<int, int> q_top = q.front();
			pair<int, int> pq_top = pq.top();

			if (q_top == pq_top) {
				cnt++;
				q.pop(), pq.pop();
				if (M == q_top.second)
					break;
			}
			else {
				if (q_top.first == pq_top.first) {
					q.pop();
					pq.pop();
					cnt++;
					if (M == q_top.second)
						break;
				}

				else {
					q.push(q.front());
					q.pop();
				}
			}
		}

		printf("%d\n", cnt);
	}
}
