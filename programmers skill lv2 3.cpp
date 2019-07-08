#include<iostream>
#include<string>
#include<queue>
#include<deque>
#include<vector>

using namespace std;

int solution(vector<int> priorities, int location) {
	deque<pair<int,int>> dq;
	priority_queue<pair<int,int>> pq;

	int size = priorities.size();
	
	for (int i = 0; i < size; i++) {
		int judge = 0;
		if (i == location) {
			judge = 1;
		}
		int num = priorities[i];
		dq.push_back({ num,judge });
		pq.push({ num,judge });
	}

	int answer = 0;

	while (!dq.empty()) {
		auto f_dq = dq.front();
		auto f_pq = pq.top();
		

		if (f_dq.first == f_pq.first) {
			if (f_dq.second == true || f_pq.second == true) {
				if (f_dq.second == false && f_pq.second == true) {
					dq.pop_front();
				}
				else if(f_dq.second == true && f_pq.second == true) {
					answer++;
					break;
				}
				answer++;
			}
			else {
				dq.pop_front();
				pq.pop();
				answer++;
			}
		}
		else if (f_dq.first < f_pq.first){
			dq.push_back(f_dq);
			dq.pop_front();
		}
	}
	return answer;
}

int main(void) {
	vector<int> p;
	p.push_back(1); p.push_back(1); p.push_back(9);
	p.push_back(1); p.push_back(1); p.push_back(1);

	printf("%d", solution(p, 0));
}