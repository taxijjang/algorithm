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


map<tuple<int, int, int>, int> ress;
bool cmp(vector<int> v1, vector<int> v2) {
	if (v1[0] == v2[0]) {
		if (v1[1] == v2[1]) {
			return v1[2] < v2[2];
		}
		return v1[1] < v2[1];
	}
	return v1[0] < v2[0];
}

bool check() {
	for (auto r : ress) {
		int x, y, a; tie(x, y, a) = r.first;

		if (a == 0) {//기둥
			if (y == 0 || ress.count(make_tuple(x - 1, y, 1)) || ress.count(make_tuple(x, y, 1)) || ress.count(make_tuple(x, y - 1, 0)))
				continue;
			else
				return false;
		}

		else if (a == 1) {//보
			if (ress.count(make_tuple(x, y - 1, 0)) || ress.count(make_tuple(x + 1, y - 1, 0)) || (ress.count(make_tuple(x - 1, y, 1)) + ress.count(make_tuple(x + 1, y, 1)) == 2))
				continue;
			else return false;
		}
	}

	return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	for (auto build : build_frame) {
		tuple<int, int, int> b = make_tuple(build[0], build[1], build[2]);
		int toggle = build[3];

		if (toggle == 1) {//추가
			ress[b] = true;

			if (check() == false) {
				ress.erase(b);
			}
		}
		else if (toggle == 0) {//삭제
			ress.erase(b);

			if (check() == false) {
				ress[b] = true;
			}
		}

	}


	for (auto res : ress) {
		int x, y, a; tie(x, y, a) = res.first;
		vector<int> r = { x,y,a };
		answer.push_back(r);
	}
	sort(answer.begin(), answer.end(), cmp);

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	//vector<vector<int>> bb = { {1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1} };
	vector<vector<int>> bb = { {0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1} };
	//vector<vector<int>> bb = { {1,0,0,1},{2,0,0,1},{0,1,1,1},{1,1,1,1},{1,1,1,0} };

	/*int n; cin >> n;
	vector<vector<int>> bb;
	for (int i = 0; i < n; i++) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		vector<int> bid = { x,y,a,b };
		bb.push_back(bid);
	}*/

	vector<vector<int>> rr = solution(5, bb);

	cout << "\n" << rr.size() << "\n";
	for (auto r : rr) {
		cout << r[0] << " " << r[1] << " " << r[2] << "\n";
	}
}