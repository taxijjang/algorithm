#include<iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Data {
	int day;
	int score;

	bool operator < (const Data d) {
		if (d.day == day) {
			return score < d.score;
		}
		return d.day > day;
	}
};

Data arr[1001];

int max(int a, int b) {
	return a > b ? a : b;
}

int solution(int N) {
	priority_queue <int> pq;

	int sum = 0;
	int d = 1;
	for (int i = 1; i <= N; i++) {
		sum += arr[i].score;
		pq.push(-1 * arr[i].score);

		if (pq.size() > arr[i].day) {
			sum += pq.top();
			pq.pop();
		}
	}

	return sum;
}
int main(void) {
	int N;
	scanf("%d",&N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &arr[i].day, &arr[i].score);
	}

	sort(arr + 1, arr + 1 + N);

	printf("%d", solution(N));
	getchar();
}