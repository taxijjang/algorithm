#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
#include<map>


using namespace std;

map<char, int> _map;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int s_size = skill.size();
	for (int i = 0; i < s_size; i++) {
		_map[skill[i]] = i;
	}

	for (auto sk = skill_trees.begin(); sk != skill_trees.end(); sk++) {
		int index = 0;
		int sk_size = sk->size();
		string tmp_sk = *sk;
		bool toggle = true;

		for (int i = 0; i < sk_size; i++) {
			if (_map.find(tmp_sk[i]) != _map.end()) {
				if (index != _map[tmp_sk[i]]) {
					toggle = false;
					break;
				}
				else {
					index++;
				}
			}
		}
		if (toggle)
			answer++;

	}
	return answer;
}

int main(void) {
	string skill = "CBD";
	vector<string> sk;
	sk.push_back("BACDE");
	sk.push_back("CBADF");
	sk.push_back("AECB");
	sk.push_back("BDA");

	cout << solution(skill, sk);
}