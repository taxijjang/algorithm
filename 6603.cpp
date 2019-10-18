#include<iostream>
#include<set>
#include<string>
#include<vector>

using namespace std;

int lotto[20];
int k;
set<vector<int>> _set;
void dfs(vector<int> v, int index, int cnt) {
	v.push_back(lotto[index]);
	if (cnt == 6) {
		_set.insert(v);
		return;
	}

	for (int i = index + 1; i < k; i++) {
		dfs(v, i, cnt + 1);
	}
}
int main(void) {
	do {
		 cin >> k;
		if (k == 0)
			break;

		
		for (int i = 0; i < k; i++) {
			cin >> lotto[i];
		}

		//로또 숫자 6개 고르기
		vector<int> empty_vector;
		vector<int> v; swap(v, empty_vector);
		set<vector<int>> empty_set;
		swap(_set, empty_set);
		for (int i = 0; i <= k - 6; i++) {
			dfs(v, i, 1);
		}

		for (auto it = _set.begin(); it != _set.end(); it++) {
			for (auto it2 = it->begin(); it2 != it->end(); it2++) {
				cout << *it2 << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	} while (true);
}