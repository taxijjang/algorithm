#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#define INF 2e9
#define SIZE 55

using namespace std;

typedef long long int ll;

typedef struct Data {
	int x, y;
}Data;
int arr[SIZE][SIZE];
int len_arr[SIZE][SIZE];

int N, M;

queue<Data> home;
vector<Data> chi;

void fill_len() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			len_arr[i][j] = INF;
		}
	}
}
int len(Data home, Data chicken) {
	return abs(home.x - chicken.x) + abs(home.y - chicken.y);
}
int total_len() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += len_arr[i][j] == INF ? 0 : len_arr[i][j];
		}
	}
	return sum;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	 cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				home.push({ i,j });
			if (arr[i][j] == 2)
				chi.push_back({ i,j });
		}
	}

	vector<int> ids; ids.assign(chi.size(), 0);

	for (int i = ids.size() - M; i < ids.size(); i++)
		ids[i] = 1;

	int res = INF;

	do {
		vector<Data> c_index;

		for (int i = 0; i < ids.size(); i++) {
			if (ids[i] == 1)
				c_index.push_back(chi[i]);
		}

		int h_c = 0;
		fill_len();
		for (auto it = c_index.begin(); it != c_index.end(); it++) {
			queue<Data> h_home = home;
			while (!h_home.empty()) {
				Data h = h_home.front();
				h_home.pop();
				int l_calc = len(h, *it);
				len_arr[h.x][h.y] = min(len_arr[h.x][h.y], l_calc);
			}

		}
		int t_l = total_len();
		res = res < t_l ? res : t_l;

	} while (next_permutation(ids.begin(), ids.end()));

	cout << res;
}