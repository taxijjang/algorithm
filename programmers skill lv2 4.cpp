#include<iostream>
#include<queue>
#include <vector>
using namespace std;

int calc_day(int p, int s) {
	int answer = 0;
	int tmp = 100 - p;
	int num = 0;
	while (tmp >= num) {
		num += s;
		answer++;
	}
	return answer;
}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	int p_size = progresses.size();
	int s_size = speeds.size();

	vector<int> p = progresses;
	vector<int> s = speeds;

	int cnt = 1;
	int day = 0;
	day = calc_day(p[0], s[0]);

	vector<int> answer;
	for (int i = 1; i < p_size; i++) {
		int next = calc_day(p[i], s[i]);
		if (day >= next) {
			cnt++;
			if (i == p_size - 1)
				answer.push_back(cnt);
		}
		else if (day < next) {
			answer.push_back(cnt);
			cnt = 1;
			day = next;
			if (i == p_size-1)
				answer.push_back(cnt);
		}
	}
	
	return answer;

}
int main(void) {
	vector<int> p;
	p.push_back(93); p.push_back(30); p.push_back(55); p.push_back(60);
	//p.push_back(10); p.push_back(10); p.push_back(10);
	vector<int> s;
	s.push_back(1); s.push_back(30); s.push_back(5); s.push_back(5);
	//s.push_back(1); s.push_back(1); s.push_back(1);
	for (auto it : solution(p,s)) {
		printf("%d\n", it);
	}
}