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
#include<stack>

#define SIZE 33
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

struct Trie {
	Trie *node[SIZE];
	bool finish, child;
	int child_cnt = 0;
	Trie() {
		fill(node, node + SIZE, nullptr);
		finish = child = child_cnt = false;
	}

	~Trie() {
		for (int i = 0; i < SIZE; i++) {
			if (node[i])
				delete node[i];
		}
	}

	void insert(const string &word, int index,int toggle) {
		child_cnt++;
		if (toggle == 1) {//왼쪽에서 오른쪽으로
			if (index >= word.size()) {
				finish = true;
				return;
			}
		}		
		else if(toggle == -1) {//오른쪽에서 왼쪽으로
			if (index < 0) {
				finish = true;
				return;
			}
		}

		int alpa_index = word[index] - 'a';
		if (node[alpa_index] == NULL) {
			node[alpa_index] = new Trie();
			child = true;
		}

		node[alpa_index]->insert(word, index + toggle, toggle);
	}

	int find(const string &word, int index,int toggle) {
		int res = 0;
		int word_index = word[index] - 'a';

		//현재 단어가 '?' 이면 밑에 있는 자식들의 개수를 리턴
		if (word[index] == '?')
			return child_cnt;

		//단어의 끝날 때 0 리턴
		if (node[word_index] == NULL) {
			return 0;
		}
		
		if (toggle == 1) { //오른쪽에서 왼쪽으로
			res = node[word_index]->find(word, index + toggle, toggle);
		}
		else if (toggle == -1) {//왼쪽에서 오른쪽으로
			res = node[word_index]->find(word, index + toggle, toggle);
		}

		return res;
	}
};
Trie left_right[10010];
Trie right_left[10010];

vector<int> solution(vector<string> words, vector<string> queries) {

	for (auto word : words) {
		//가사의 길이를 분류하여 트라이를 만듬
		int w_size = word.size();
		left_right[w_size].insert(word, 0, 1);
		right_left[w_size].insert(word, word.size() - 1, -1);
	}
	vector<int> answer;

	int res = 0;
	for (auto querie : queries) {
		int q_size = querie.size();
		
		//?의 위치 파악
		int toggle = (querie[0] == '?' ? -1 : 1);

		if (toggle == 1) {
			answer.push_back(left_right[q_size].find(querie, 0, toggle));
		}
		else if (toggle == -1) {
			answer.push_back(right_left[q_size].find(querie, querie.size() - 1, toggle));
		}
	}
	return answer;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<string> words = { "frodo","front","frost","frozen","frame","kakao" };
	vector<string> queries = { "fro??","????o","fr???","fro???","pro?" };
	vector<int> s = solution(words, queries);

}