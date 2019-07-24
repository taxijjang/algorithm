#include<iostream>
#include<deque>

using namespace std;

typedef long long int ll;

ll start(int i, int L) {
	if (i - L + 1 < 1)
		return 1;
	return i - L + 1;
}
typedef struct Data {
	ll num;
	ll index;
}Data;

deque<Data> dq;

int main(void) {
	int N, L; scanf("%d %d", &N, &L);
	for (int i = 1; i <= N; i++) {
		int num; scanf("%d", &num);

		ll left = start(i, L);
		while (!dq.empty() && dq.front().index < left) {
			dq.pop_front();
		}
		while (!dq.empty() && dq.back().num > num) {
			dq.pop_back();
		}
		dq.push_back({ num,i });

		
		printf("%d ", dq.front());
	}
}