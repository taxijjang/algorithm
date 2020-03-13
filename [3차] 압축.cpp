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

#define SIZE 1010
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

map<string, int> dict;
map<string, bool> check;
void init() {
	for (char i = 'A'; i <= 'Z'; i++) {
		string s = ""; s += i;
		dict[s] = i - 'A' + 1;
		check[s] = false;
	}
}
vector<int> solution(string msg) {
	init();

	vector<int> answer;
	int len = 0;
	
	string tmp = ""; answer.push_back(dict[msg.substr(0,1)]);
	int index = 27;
	for (int i = 0; i < msg.size(); i++) {
		tmp = ""; tmp += msg[i];
		for (int j = i + 1; j < msg.size(); j++) {
			tmp += msg[j];

			if (dict.count(tmp) == 0) {
				dict[tmp] = index++;
				break;
			}
		}
	}



	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string msg; cin >> msg;

	vector<int > s = solution(msg);

}