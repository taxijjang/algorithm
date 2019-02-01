#include <iostream>
#include <vector>

using namespace std;

int visited[10001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int head, tail;
		cin >> head >> tail;
		for (int j = head; j < tail; j++) {
			visited[j] = 1;
		}
	}

	int sum = 0;
	for (int i = 1; i <= 10000; i++) {
		if (visited[i] == 1)
			sum += 1;
	}

	cout << sum;
	
	return 0;
}