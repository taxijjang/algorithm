#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<functional>

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

bool visited[SIZE];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;

	map<int, priority_queue<int>> _map;
	for (int i = 0; ; i++) {
		//cout << s <<"\n";
		memset(visited, false, sizeof(visited));
		priority_queue<int> res;
		int s_size = s.size();
		int left = 0;
		int right = s_size - 1;
		int cnt = 0;

		while (left < right) {
			while (left < s_size && (s[left] != '(' || visited[left] == true))
				left++;

			while (right >= 0 && (s[right] != ')' || visited[right] == true))
				right--;

			if (left >= right || left >= s_size || right < 0)
				break;
			/*if (s[left] != '(' || visited[left] == true) {
			left++;
			}
			if (s[right] != ')' || visited[right] == true) {
			right--;
			}*/

			if ((visited[left] != true && visited[right] != true) && s[left] == '(' && s[right] == ')') {
				res.push(-left); res.push(-right);
				visited[left] = true; visited[right] = true;
				left++; right--;
				cnt++;
				//if (cnt >= 2) break;
			}

		}

		if (cnt == 0)
			break;

		_map[i] = res;

		string tmp = "";
		for (int i = 0; i < s_size; i++) {
			if (visited[i] == false)
				tmp += s[i];
		}
		s = tmp;
	}

	cout << _map.size() << "\n";
	for (int i = 0; i < _map.size(); i++) {
		cout << _map[i].size() << "\n";
		while (!_map[i].empty()) {
			cout << -(_map[i].top()) + 1 << " ";
			_map[i].pop();
		}
		cout << "\n";
	}
}