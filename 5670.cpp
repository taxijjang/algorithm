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

#define SIZE 30
const int INF = 2000000000;

using namespace std;

typedef long long int ll;

struct Trie {
	Trie *node[SIZE];
	int alpa_cnt;
	bool is_finish, is_child;

	Trie() {
		fill(node, node + SIZE, nullptr);
		alpa_cnt = 0; is_finish = is_child = false;
	}

	~Trie() {
		for (int i = 0; i < SIZE; i++) {
			if (node[i])
				delete node[i];
		}
	}

	void insert(const string &word, int index) {
		if (index >= word.size()) {
			is_finish = true;
			return;
		}
		else if (index < word.size()) {
			int word_index = word[index] - 'a';
			if (node[word_index] == NULL) {
				alpa_cnt++;
				is_child = true;
				node[word_index] = new Trie();
			}

			node[word_index]->insert(word, index + 1);
		}
	}

	int find(const string &word, int index, int cnt) {
		if (index >= word.size()) {
			return cnt;
		}
		int res = 0;
		int word_index = word[index] - 'a';
		
		if (index != 0 && (alpa_cnt != 1 || (alpa_cnt == 1 && is_finish== true))&&node[word_index]!=NULL) {
			res = node[word_index]->find(word, index + 1, cnt + 1);
		}
		else {
			res = node[word_index]->find(word, index + 1, cnt);
		}

		return res;
	}
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int N; cin >> N;

		Trie root; vector<string> words;
		for (int i = 0; i < N; i++) {
			string word; cin >> word; words.push_back(word);
			root.insert(word, 0);
		}

		double res = 0;
		for (auto word : words) {
			res += root.find(word,0,0) + 1;
		}

		cout << fixed;
		cout.precision(2);
		cout << res/double(N) << "\n";
	}
}