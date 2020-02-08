#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 101

using namespace std;

typedef long long int ll;

typedef struct Data {
	int x = 0, y = 0;
	int direct = 0;

	bool operator == (Data d) {
		return ((d.x == x) && (d.y == y));
	}
}Data;

const int brank = 0;
const int snake = 1;
const int apple = 2;

deque<Data> dq;
int board[SIZE][SIZE];
queue<pair<int, char>> query;

Data s_move(Data snake) {
	Data s_m = snake;
	if (s_m.direct == 1) {
		s_m.x += 1;
	}
	else if (s_m.direct == 2) {
		s_m.y -= 1;
	}
	else if (s_m.direct == 3) {
		s_m.x -= 1;
	}
	else if (s_m.direct == 4) {
		s_m.y += 1;
	}
	return s_m;
}

int direct_change(Data snake, char dir) {
	int s_direct = snake.direct;

	if (s_direct == 1) {
		if (dir == 'L')
			return 4;
		else
			return 2;
	}
	else if (s_direct == 2) {
		if (dir == 'L')
			return 1;
		else
			return 3;
	}
	else if (s_direct == 3) {
		if (dir == 'L')
			return 2;
		else
			return 4;
	}
	else if (s_direct == 4) {
		if (dir == 'L')
			return 3;
		else
			return 1;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	int K; cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y; cin >> x >> y;
		board[x][y] = apple;
	}
	board[1][1] = snake;

	int L; cin >> L;
	for (int i = 0; i < L; i++) {
		int time; char m; cin >> time >> m;
		query.push({ time,m });
	}

	int s_size = 1;
	Data head; head.x = 1; head.y = 1; head.direct = 4;
	dq.push_back(head);

	int q_index = 0;
	int time=0;
	while (1){
		time++;	
		Data n_loc = s_move(dq.front());

		if (n_loc.x <= 0 || n_loc.x > N || n_loc.y <= 0 || n_loc.y > N) {
			break;
		}
		if (board[n_loc.x][n_loc.y] == apple) {
			dq.push_front(n_loc);
			board[n_loc.x][n_loc.y] = snake;
		}
		else if (board[n_loc.x][n_loc.y] == brank) {
			board[n_loc.x][n_loc.y] = snake;
			dq.push_front(n_loc);

			board[dq.back().x][dq.back().y] = brank;
			dq.pop_back();
		}
		else if (board[n_loc.x][n_loc.y] == snake) {
			break;
		}

		if (!query.empty()) {
			if (query.front().first == time) {
				dq.front().direct = direct_change(dq.front(), query.front().second);
				query.pop();
			}
		}
	}

	cout << time;;
	 
}