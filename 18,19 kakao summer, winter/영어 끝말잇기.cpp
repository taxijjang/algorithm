#include <string>
#include <vector>
#include <iostream>
#include<map>
#include<set>

using namespace std;

set<string> _set;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;

	int w_size = words.size();
	int cnt = 0;
	for (int i = 0; i < w_size; i++) {
		if (i %n == 0)
			cnt++;
		if (i != 0) {
			if (words[i - 1].back() != words[i].front())
				break;
		}
		
		if (_set.find(words[i]) == _set.end()) {
			_set.insert(words[i]);
		}
		else {
			answer.push_back(i%n + 1);
			answer.push_back(cnt);
			break;
		}
	
	}

	if (answer.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}

	getchar();
	return answer;
}

int main(void) {
	vector<string> st; 
	st.push_back("hello");
	st.push_back("one");
	st.push_back("even");
	st.push_back("never");
	st.push_back("now");
	st.push_back("world");
	st.push_back("draw");
	vector<int> v = solution(2, st);
}