#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);

		if (num == 0) {
			if (pq.empty()) {
				printf("%d\n", 0);
			}
			else {
				printf("%d\n", -pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(-num);
		}
	}
}