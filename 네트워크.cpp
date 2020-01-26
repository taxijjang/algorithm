#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>

#define INF 2e9
#define SIZE 210

using namespace std;

typedef long long int ll;

int parrent[SIZE];

void fill_p() {
	for (int i = 0; i < SIZE; i++) {
		parrent[i] = i;
	}
}
int _find(int a) {
	if (parrent[a] == a)
		return a;

	return parrent[a] = _find(parrent[a]);
}

void _union(int a, int b) {
	int aRoot = _find(a);
	int bRoot = _find(b);

	if (aRoot == bRoot)
		return;

	parrent[bRoot] = aRoot;
}

int solution(int n, vector<vector<int>> computers) {
	fill_p();
	int c_size = computers.size();

	for (int i = 0; i < c_size; i++) {
		for (int j = i; j < c_size; j++) {
			if (computers[i][j] == 1 && i!=j)
				_union(i, j);
		}
	}

	getchar();

	int answer = 0;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<vector<int>> com;
	
	
	for (int i = 0; i < 3; i++) {
		vector<int> cc;
		int a, b, c; cin >> a >> b >> c;
		cc.push_back(a); cc.push_back(b); cc.push_back(c);
		com.push_back(cc);
	}

	cout << solution(N, com);
}