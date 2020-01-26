#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<memory.h>

#define INF 2e9
#define SIZE 10100

using namespace std;

typedef long long int ll;


vector<pair<int,int>> arr[SIZE];
bool visited[SIZE];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	int left = 0, right = 0, mid;
	for (int i = 0; i < M; i++) {
		int n1, n2, cost;

		arr[n1].push_back({ n2, cost });
		arr[n2].push_back({ n1,cost });

		right = max(right, cost);
	}

	int start, end; cin >> start >> end;

	
	int res = 0;
	while (left <= right) {
		memset(visited, 0, sizeof(visited));

		mid = (left + right) / 2;
		bool check = false;
		queue<int> q;

		q.push(start);

		while (!q.empty()) {
			int here = q.front();
			q.pop();

			visited[here] = true;

			if (here == end) {
				check = true;
				break;
			}

			for (auto next : arr[here]) {
				if (visited[next.first] != true && next.second >= mid) {
					visited[next.first] = true;
					q.push(next.first);
				}
			}
		}

		if (check == true) {
			res = max(res, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << res;
	return 0;

}