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
	int x, y;
}Data;

const int INF = 2e9;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 }; 
char board[SIZE][SIZE];
int board_alt[SIZE][SIZE];
bool visited[SIZE][SIZE];
set<int> s;
vector<int> alt;

int N;
int k_cnt;

void fill_v() {
	k_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

void dfs(Data here, int left, int right) {
	if (board_alt[here.x][here.y] < alt[left] || board_alt[here.x][here.y] >alt[right])
		return;
	if (board[here.x][here.y] == 'K')
		k_cnt++;
	visited[here.x][here.y] = true;

	for (int i = 0; i < 8; i++) {
		Data n;
		n.x = here.x + dx[i];
		n.y = here.y + dy[i];

		if (n.x <0 || n.x >=N | n.y < 0 || n.y >= N)
			continue;
		if (visited[n.x][n.y] == true)
			continue;
		dfs(n, left, right);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	Data start;
	int K_CNT = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'P') {
				start.x = i; start.y = j;
			}
			else if (board[i][j] == 'K')
				K_CNT++;
		}
	}

	for(int i=0 ; i < N;i++){
		for (int j = 0; j < N; j++) {
			cin >> board_alt[i][j];
			s.insert(board_alt[i][j]);
		}
	}

	alt.swap(vector<int>(s.begin(), s.end()));
	
	int left = 0, right = 0, res = INF;

	while (right < alt.size()) {
		fill_v();

		dfs(start,left, right);
		
		if (k_cnt == K_CNT) {
			res = min(res, alt[right] - alt[left]);
			left++;
		}
		else if (k_cnt != K_CNT) {
			right++;
		}
	}
	cout << res;
}