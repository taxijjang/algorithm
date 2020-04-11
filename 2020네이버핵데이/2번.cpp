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
typedef pair<int, int> pii;

map<string, pair<int,int>> _map;
int solution(vector<string> id_list, int k) {
	int coupon = 0;
	int id_size = id_list.size();
	for (int i = 0; i < id_size; i++) {
		string id = "";
		bool check = false;
		int iid_size = id_list[i].size();

		for(int j = 0; j <iid_size ; j++){
			id = id + id_list[i][j];
			check = true;

			if (id_list[i][j] ==' ' || j+1 == iid_size) {
				if (id_list[i][j] == ' ') id.pop_back();
				if (_map.find(id) == _map.end()) {
					_map[id] = make_pair(i, 1);
					coupon++;
				}

				else {
					if (_map[id].first == i || _map[id].second >= k) {
						id = "";
						continue;
						
					}
					else {
						_map[id].first = i;
						_map[id].second++;
						coupon++;
					}
				}
				id = "";
			}
		}

		
	}

	return coupon;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<string> id_list = { "A B C D","A D", "A B D", "B D" };
	//vector<string> id_list = { "JAY","JAY ELLE JAY MAY","MAY ELLE MAY", "ELLE MAY","ELLE ELLE ELLE","MAY" };
	int k = 2;
	cout << solution(id_list, k);

}
