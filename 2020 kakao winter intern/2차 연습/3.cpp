#include <string>
#include <vector>
#include<iostream>
#include<set>
#include<algorithm>
#define SIZE 10
using namespace std;

bool visited[SIZE];
set<string> _set;

void dfs(vector<string> user_id, vector<string> banned_id, int b_index) {
	int u_size = user_id.size();
	int b_size = banned_id.size();

	if (b_index >= b_size) {
		string res = "";
		for (int i = 0; i < user_id.size(); i++) {
			if (visited[i]) {
				res += i;
			}
		}
		_set.insert(res);
		return;
	}


	for (int i = 0; i < u_size; i++) {
		if (banned_id[b_index].size() != user_id[i].size() || visited[i]) {
			continue;
		}

		bool toggle = true;

		for (int j = 0; j < user_id[i].size(); j++) {
			if (banned_id[b_index][j] == '*') {
				continue;
			}
			if (user_id[i][j] != banned_id[b_index][j]) {
				toggle = false;
				break;
			}
		}

		if (toggle) {
			visited[i] = true;
			dfs(user_id, banned_id, b_index + 1);
			visited[i] = false;
		}
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {
   int answer = 0;
   dfs(user_id, banned_id, 0);
   answer = _set.size();
   return answer;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   //vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
   //vector<string> banned_id = { "fr*d*", "abc1**" };

   //vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
   //vector<string> banned_id = {"*rodo", "*rodo", "******"};

   vector<string> user_id = { "frodo", "fradi", "crodo" };
   vector<string> banned_id = { "*****" };
   cout << solution(user_id, banned_id);

}