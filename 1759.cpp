#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

char alpa[20];
bool visited[30];
int L, C;

set<string> _set;

void dfs(string word , int index,  int jaum, int moum) {
	string s = word + alpa[index];
	if (alpa[index] == 'i' || alpa[index] == 'a' || alpa[index] == 'e' || alpa[index] == 'o' || alpa[index] == 'u')
		moum++;
	else
		jaum++;
	if (jaum+ moum == L) {
		if(moum >=1 && jaum >=2)
			_set.insert(s);
		return;
	}
	for (int i = index + 1; i < C; i++) {
		dfs(s, i, jaum, moum);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> alpa[i];
	}

	sort(alpa, alpa + C);

	for (int i = 0; i <= C - L; i++) {
		dfs("", i, 0,0);
	}
	for (auto it = _set.begin(); it != _set.end(); it++) {
		cout << *it << "\n";
	}
}