#include <iostream>
#include <stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

stack<char> st;

string cmp(string s1, string s2) {
	if (s1.size() < s2.size()) {
		return s2;
	}
	return s1;
}
string getMin(string word, int k) {
	int word_size = word.size();

	string tmp = "";
	string res = "";
	for (int i = 0; i < word_size - 1; i++) {
		if (i == 0) {
			tmp += word[i];
			res += word[i];
		}

		if (abs(word[i] - word[i + 1]) <= k) {
			tmp = tmp + word[i + 1];
		}
		else {
			res = cmp(res, tmp);
			tmp = "";
			tmp += word[i + 1];
		}
	}

	res = cmp(res, tmp);

	return res;

}

int main() {
	string s = "ababbacaabbbb";
	int k = 2;
	cout << getMin(s, k);
}