#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>
#include<cmath>

#define SIZE 100
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

int board[SIZE][SIZE];
int lock_cnt;
int lock_check(vector<vector<int>> &lock) {
	int cnt = 0;
	int lock_size = lock.size();
	for (int i = 0; i < lock_size;i++) {
		for (int j = 0; j < lock_size; j++) {
			if (lock[i][j] == 0) {
				cnt++; lock[i][j] = 2;
			}
			board[lock_size - 1 + i][lock_size - 1 + j] = lock[i][j];
		}
	}

	return cnt;
}
void r(vector<vector<int>> &key) {
	int m = key.size();
	vector<vector<int>> temp(m, vector<int>(m, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			//temp[i][j] = key[j][m - i - 1];
			temp[i][j] = key[m - j - 1][i];
		}
	}
	key = temp;
}

bool check(vector<vector<int>> key,int i, int j) {
	int correct = 0;
	int key_size = key.size();
	for (int d = 0; d < 4; d++) {
		r(key);
		correct = 0;
		for (int ki = 0, li = i; ki < key_size; ki++, li++) {
			for (int kj = 0, lj = j; kj < key_size; kj++, lj++) {
				if (key[ki][kj]==1 && board[li][lj]==1) {
					continue;
				}
				if (key[ki][kj] == 1 && board[li][lj] == 2)
					correct++;
			}
		}
		if (correct == lock_cnt) {
			return true;
		}
	}
	return false;

}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	lock_cnt = lock_check(lock);
	int lock_size = lock.size();
	int size = lock_size * 3 - 2;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (check(key, i, j))
				return true;
		}

	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	vector<vector<int>> key = { {0,0,0},{1,0,0},{0,1,1} };
	vector<vector<int>> lock = { {1,1,1},{1,1,0},{1,0,1} };

	bool res = solution(key, lock);
	
	if (res)
		cout << "true";
	else
		cout << "false";
}