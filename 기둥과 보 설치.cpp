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
#include<stack>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

map<int, map<int, bool>> gi;
map<int, map<int, bool>> bo;

bool cmp(vector<int> v1, vector<int> v2) {
	if (v1[0] == v2[0]) {
		if (v1[1] == v2[0]) {
			return v1[2] < v2[2];
		}
		return v1[1] < v2[2];
	}
	return v1[0] < v2[0];
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	for (auto build : build_frame) {
		//a(0 기둥, 1 보)  , b(0 삭제, 1 설치)
		int x = build[0], y = build[1], a = build[2], b = build[3];
		if (b == 1) {//설치 할때
			if (a == 0) {//기둥
				if (y == 0 || gi[x][y - 1] == true || bo[x - 1][y] == true || bo[x][y] == true)
					gi[x][y] = true;
			}
			else if (a == 1) {//보
				if (gi[x][y - 1] == true || gi[x + 1][y - 1] == true || (bo[x - 1][y] == true && bo[x + 1][y] == true)) {
					bo[x][y] = true;
				}
			}
		}

		else if (b == 0) {//삭제 할때
			if (a == 0) {//기둥
				if (gi[x][y + 1] == true)
					continue;

				int check = 0;
				for (int i = x - 1; i >= -1; i--) {
					if (bo[i][y + 1] != true) {
						if (i == x - 1)
							check++;
						break;
					}

					if (gi[i][y] == true) {
						check++;
						break;
					}

				}
				for (int i = x; i <= n; i++) {
					if (bo[i][y + 1] != true) {
						if (i == x)
							check++;
						break;
					}

					if (gi[i][y] == true) {
						check++;
						break;
					}

				}

				if (check < 2)
					continue;
				gi[x][y] = false;

			}

			else if (a == 1) {//보
				if ((gi[x][y] == true && bo[x - 1][y] != true) || (gi[x + 1][y] == true && bo[x + 1][y] != true))
					continue;

				int check = 0;
				for (int i = x; i > x - 2; i--) {
					if (bo[i][y] != true) {
						if (i == x - 1)
							check++;
						break;
					}
					if (gi[i][y - 1] == true) {
						check++;
						break;
					}
				}

				for (int i = x + 1; i <= x + 2; i++) {
					if (bo[i][y] != true) {
						if (i == x + 1)
							check++;
						break;
					}
					if (gi[i][y - 1] == true) {
						check++;
						break;
					}
				}

				if (check < 2)
					continue;

				bo[x][y] = false;
			}
		}
	}

	for (auto g : gi) {
		for (auto gg : g.second) {
			if (gg.second == true) {
				vector<int> a;
				a.push_back(g.first); a.push_back(gg.first); a.push_back(0);
				answer.push_back(a);
			}
		}
	}


	for (auto b : bo) {
		for (auto bb : b.second) {
			if (bb.second == true) {
				vector<int> a;
				a.push_back(b.first); a.push_back(bb.first); a.push_back(1);
				answer.push_back(a);
			}
		}
	}

	sort(answer.begin(), answer.end(), cmp);

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	vector<vector<int>> bb = { {1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1} };
	//vector<vector<int>> bb = {{0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1}};
	//vector<vector<int>> bb = { {1,0,0,1},{2,0,0,1},{0,1,1,1},{1,1,1,1},{1,1,1,0} };

	/*int n; cin >> n;
	vector<vector<int>> bb;
	for (int i = 0; i < n; i++) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		vector<int> bid = { x,y,a,b };
		bb.push_back(bid);
	}*/

	vector<vector<int>> res = solution(5, bb);

	cout << "\n" << res.size() << "\n";
	for (auto r : res) {
		cout << r[0] << " " << r[1] << " " << r[2] << "\n";
	}
}