#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#define INF 2e9
#define SIZE 10010
using namespace std;

bool prime[SIZE];
bool visited[SIZE];

int res;

typedef struct Data {
	string num;
	int cnt = 0;
}Data;
void eratos() {
	for (int i = 2; i < SIZE; i++) {
		for (int j = 2; i * j < SIZE; j++) {
			if (prime[i*j] != true)
				prime[i*j] = true;
		}
	}
}

void fill_v() {
	for (int i = 0; i < SIZE; i++) {
		visited[i] = false;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	eratos();

	int N; cin >> N;

	for (int t = 0; t < N; t++) {
		string start, end; cin >> start >> end;
		int res = 0;
		if (start == end)
			cout << "0\n";
		else {
			queue<Data> q;
			Data s; s.num = start, s.cnt = 0;
			q.push(s);

			while (!q.empty()) {
				Data here;
				here.num = q.front().num;
				here.cnt = q.front().cnt;
				visited[stoi(here.num)] = true;
				q.pop();

				for (int i = 0; i < 4; i++) {
					string t_mp = here.num;
					for (int j = 0; j < 10; j++) {
						if (i == 0 && j == 0)
							continue;

						Data next;
						next.num = t_mp.replace(i, 1, to_string(j));
						next.cnt = here.cnt + 1;

						int tmp = stoi(next.num);
						if (visited[tmp] == true)
							continue;
						if (prime[tmp] == true)
							continue;

						if (next.num == end) {
							i = 4; j = 10; q.swap(queue<Data>());
							res = next.cnt;
							break;
						}
						q.push(next);
					}
				}

			}
		}
		cout << res << "\n";
		fill_v();
	}
}