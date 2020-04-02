#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

map<string, int> _map;

bool cmp(pair<string, int> p1, pair<string, int>p2) {
	return p1.second > p2.second;
}
vector<int> solution(string s) {
	string num = "";
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == '}' || s[i] == '{' || s[i] == ',') {
			if (s[i] == ',' && num != "" || s[i] == '}' && num != "")
				_map[num]++;
			num = "";
		}
		else {
			num = num + s[i];
		}
	}

	vector <pair<string, int>> arr(_map.begin(), _map.end());
	sort(arr.begin(), arr.end(), cmp);

	vector<int> answer;
	for (auto a : arr) {
		answer.push_back(stoi(a.first));
	}
	return answer;
}

int main(void) {
	string s; cin >> s;

	vector<int> res = solution(s);
}