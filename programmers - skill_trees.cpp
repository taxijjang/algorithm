#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	vector<string> s_t = skill_trees;
	string sk = skill;

	int answer = 0;
	int size = s_t.size();
	
	for (int i = 0; i < size; i++) {
		int index = 0;
		int find = 0;
		int size_i = s_t[i].size();
		for (int j = 0; j < size_i; j++) {
			int judge = sk.find(s_t[i][j]);
			if (sk.find(s_t[i][j]) != -1) {
				if (index == judge)
					index++;
				else
					break;
			}
			find++;
		}
		if ((index == sk.size() - 1) || find == size_i) {
			answer++;
		}
	}

	return answer;
}

int main(void) {
	string s;
	cin >> s;

	vector<string> skill_trees;

	int n;

	cin >> n;

	string skill;

	for (int i = 0; i < n; i++) {
		cin >> skill;
		skill_trees.push_back(skill);
	}

	printf("%d", solution(s, skill_trees));
}