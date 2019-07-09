#include<iostream>
#include<string>
#include<set>
#include<vector>

using namespace std;
vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	set<string> ss;
	int cnt = 0;
	int lp = 0;
	int size = words.size();
	string f_s, s_s;
	ss.insert(words[0]);
	bool judge = false;
	for (int i = 1; i < size; i++) {
		f_s = words[i - 1];
		s_s = words[i];

		cnt = (cnt + 1) % n;

		if (cnt == 0) lp++;
		int f_s_s = f_s.size();

		if (f_s[f_s_s - 1] != s_s[0]) {
			answer.push_back(cnt + 1);
			answer.push_back(lp);
			judge = true;
			break;
		}
		auto num = ss.find(s_s);
		if (num == ss.end())
			ss.insert(s_s);
		else {
			answer.push_back(cnt + 1);
			answer.push_back(lp + 1);
			judge = true;
			break;
		}
	}
	if (judge == false) {
		answer.push_back(0);
		answer.push_back(0);
	}
	return answer;
}
int main(void) {
	int N; cin >> N;
	vector<string>s;
	s.push_back("tank"); s.push_back("kick");
	s.push_back("know"); s.push_back("wheel");
	s.push_back("land"); s.push_back("dream");
	s.push_back("mother"); s.push_back("robot");
	s.push_back("tank");
	solution(N, s);
}