#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define SIZE 55

using namespace std;

typedef long long int ll;
typedef struct Data {
	int x, y, time=0;
}Data;

const int INF = 2e9;

int arr[SIZE][SIZE];
int tmp[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M, total_cnt, wall_cnt , off_virus, m_cnt;

int res;

vector<Data> virus;
vector<int> idx;

void init(int virus_size) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = arr[i][j];
			visited[i][j] = false;
		}
	}
	total_cnt =wall_cnt + M;
	m_cnt = 0;
	off_virus = virus_size - M;
}

void bfs() {
	init(virus.size());

	for (int i = 0; i < idx.size(); i++) {
		if (idx[i] != 1) {
			tmp[virus[i].x][virus[i].y] = 3;
		}
	}

	queue<Data> virus_q;

	for (auto v : virus) {
		if (tmp[v.x][v.y] == 2)
			virus_q.push(v);
	}

	while (!virus_q.empty()) {
		Data h = virus_q.front();
		virus_q.pop();

		visited[h.x][h.y] = true;

		for (int i = 0; i < 4; i++) {
			Data n;
			n.x = h.x + dx[i];
			n.y = h.y + dy[i];
			n.time = h.time + 1;
			if ((n.x < 0 || n.x >= N || n.y < 0 || n.y >= N) || visited[n.x][n.y] == true || tmp[n.x][n.y] == 1 || tmp[n.x][n.y] == 2)
				continue;
			
			if (tmp[n.x][n.y] == 3)
				off_virus--;
			visited[n.x][n.y] = true;
			total_cnt++;

			m_cnt = max(m_cnt, n.time);
			if (total_cnt + off_virus == N*N) {
				res = min(res, m_cnt);
				return;
			}
			virus_q.push(n);
		}
	}
		
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				Data n; n.x = i; n.y = j;
				virus.push_back(n);
			}
			else if (arr[i][j] == 1)
				wall_cnt++;
		}
	}

	
	for (int i = 0; i < virus.size(); i++) {
		if (i >= virus.size() - M)
			idx.push_back(1);
		else
			idx.push_back(0);
	}

	if (virus.size() + wall_cnt == N*N) {
		cout << 0;
		return 0;
	}
	res = INF;
	//0 빈칸 , 1 벽 , 2 바이러스 , 3 비활성 바이러스
	do {
		bfs();
	} while (next_permutation(idx.begin(),idx.end()));

	cout << (res == INF ? -1 : res);
}