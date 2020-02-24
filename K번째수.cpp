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

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++) {
		vector<int> tmp;
		tmp.assign(array.begin() + commands[i][0]-1, array.begin() + commands[i][1] );
		sort(tmp.begin(), tmp.end());

		answer.push_back(tmp[commands[i][2] - 1]);
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> s;

	vector<int> array;
	for (int i = 0; i < 7; i++) {
		int num; cin >> num;
		array.push_back(num);
	}

	vector<vector<int>> commands;
	for (int j = 0; j < 3; j++) {
		vector<int> n;
		for (int i = 0; i < 3; i++) {
			 int num; cin >> num;
			n.push_back(num);
		}
		commands.push_back(n);
	}
	s = solution(array, commands);

}