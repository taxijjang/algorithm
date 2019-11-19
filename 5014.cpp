#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 1000010

using namespace std;

typedef long long int ll;

int F, S, G, U, D;

typedef struct Data {
	int here = -1, cnt = 0;
}Data;

int visited[1000010];

queue<Data> q;


void fill_v() {
	for (int i = 0; i < SIZE; i++)
		visited[i] = -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;

	fill_v();

	Data start;
	start.cnt = 0;
	start.here = S;

	q.push(start);
	visited[S] = 0;
	while(!q.empty()) {
		Data h = q.front();
		q.pop();

		visited[h.here] = h.cnt;

		Data up; 
		up.here = h.here + U;
		up.cnt = h.cnt + 1;

		Data down;
		down.here = h.here - D;
		down.cnt = h.cnt + 1;


		if (up.here <=F && visited[up.here] == -1) {
			q.push(up);
			visited[up.here] = visited[h.here] + 1;
		}
		if (down.here >= 1 && visited[down.here] == -1) {
			q.push(down);
			visited[down.here] = visited[h.here] + 1;
		}
	}

	if (visited[G] != -1)
		cout << visited[G];
	else
		cout << "use the stairs";
}